// Copyright Yahoo. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
package com.yahoo.vespa.hosted.provision.maintenance;

import com.yahoo.config.provision.ApplicationId;
import com.yahoo.config.provision.ApplicationLockException;
import com.yahoo.config.provision.ClusterResources;
import com.yahoo.config.provision.ClusterSpec;
import com.yahoo.jdisc.Metric;
import com.yahoo.transaction.Mutex;
import com.yahoo.vespa.hosted.provision.NodeList;
import com.yahoo.vespa.hosted.provision.NodeRepository;
import com.yahoo.vespa.hosted.provision.applications.Application;
import com.yahoo.vespa.hosted.provision.applications.Applications;
import com.yahoo.vespa.hosted.provision.applications.AutoscalingStatus;
import com.yahoo.vespa.hosted.provision.applications.Cluster;
import com.yahoo.vespa.hosted.provision.autoscale.Autoscaler;
import com.yahoo.vespa.hosted.provision.autoscale.Autoscaling;
import com.yahoo.vespa.hosted.provision.autoscale.MetricsDb;

import java.time.Duration;
import java.util.Map;
import java.util.Optional;

/**
 * Maintainer computing scaling suggestions for all clusters
 *
 * @author bratseth
 */
public class ScalingSuggestionsMaintainer extends NodeRepositoryMaintainer {

    private final Autoscaler autoscaler;

    public ScalingSuggestionsMaintainer(NodeRepository nodeRepository,
                                        Duration interval,
                                        Metric metric) {
        super(nodeRepository, interval, metric);
        this.autoscaler = new Autoscaler(nodeRepository);
    }

    @Override
    protected double maintain() {
        if ( ! nodeRepository().zone().environment().isProduction()) return 1.0;

        int attempts = 0;
        int failures = 0;
        for (var application : activeNodesByApplication().entrySet()) {
            for (var cluster : nodesByCluster(application.getValue()).entrySet()) {
                attempts++;
                if ( ! suggest(application.getKey(), cluster.getKey(), cluster.getValue()))
                    failures++;
            }
        }
        return asSuccessFactor(attempts, failures);
    }

    private Applications applications() {
        return nodeRepository().applications();
    }

    private boolean suggest(ApplicationId applicationId,
                            ClusterSpec.Id clusterId,
                            NodeList clusterNodes) {
        Application application = applications().get(applicationId).orElse(Application.empty(applicationId));
        Optional<Cluster> cluster = application.cluster(clusterId);
        if (cluster.isEmpty()) return true;
        var suggestion = autoscaler.suggest(application, cluster.get(), clusterNodes);
        if (suggestion.status().status() == AutoscalingStatus.Status.waiting) return true;

        // empty suggested resources == keep the current allocation
        var suggestedResources = suggestion.resources().orElse(clusterNodes.not().retired().toResources());
        if ( ! shouldUpdateSuggestion(cluster.get().suggested(), suggestedResources)) return true;

        // Wait only a short time for the lock to avoid interfering with change deployments
        try (Mutex lock = nodeRepository().applications().lock(applicationId, Duration.ofSeconds(1))) {
            applications().get(applicationId).ifPresent(a -> updateSuggestion(suggestedResources, clusterId, a, lock));
            return true;
        }
        catch (ApplicationLockException e) {
            return false;
        }
    }

    private boolean shouldUpdateSuggestion(Autoscaling currentSuggestion, ClusterResources suggestedResources) {
        return currentSuggestion.resources().isEmpty()
               || currentSuggestion.at().isBefore(nodeRepository().clock().instant().minus(Duration.ofDays(7)))
               || isHigher(suggestedResources, currentSuggestion.resources().get());
    }

    private void updateSuggestion(ClusterResources suggestion,
                                  ClusterSpec.Id clusterId,
                                  Application application,
                                  Mutex lock) {
        Optional<Cluster> cluster = application.cluster(clusterId);
        if (cluster.isEmpty()) return;
        applications().put(application.with(cluster.get().withSuggested(new Autoscaling(suggestion,
                                                                                        AutoscalingStatus.empty(),
                                                                                        nodeRepository().clock().instant()))), lock);
    }

    private boolean isHigher(ClusterResources r1, ClusterResources r2) {
        // Use cost as a measure of "highness" over multiple dimensions
        return r1.totalResources().cost() > r2.totalResources().cost();
    }

    private Map<ClusterSpec.Id, NodeList> nodesByCluster(NodeList applicationNodes) {
        return applicationNodes.groupingBy(n -> n.allocation().get().membership().cluster().id());
    }

}
