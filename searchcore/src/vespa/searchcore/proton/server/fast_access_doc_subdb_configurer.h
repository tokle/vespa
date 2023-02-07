// Copyright Yahoo. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.
#pragma once

#include "searchable_doc_subdb_configurer.h"
#include "fast_access_feed_view.h"
#include "i_attribute_writer_factory.h"
#include <vespa/searchcore/proton/reprocessing/i_reprocessing_initializer.h>

namespace proton {

/**
 * Class used to reconfig the feed view used in a fast-access sub database
 * when the set of fast-access attributes change.
 */
class FastAccessDocSubDBConfigurer
{
public:
    using FeedViewVarHolder = vespalib::VarHolder<FastAccessFeedView::SP>;

private:
    FeedViewVarHolder           &_feedView;
    IAttributeWriterFactory::UP _factory;
    vespalib::string             _subDbName;

    void reconfigureFeedView(FastAccessFeedView & curr,
                             search::index::Schema::SP schema,
                             std::shared_ptr<const document::DocumentTypeRepo> repo,
                             IAttributeWriter::SP attrWriter);

public:
    FastAccessDocSubDBConfigurer(FeedViewVarHolder &feedView,
                                 IAttributeWriterFactory::UP factory,
                                 const vespalib::string &subDbName);
    ~FastAccessDocSubDBConfigurer();

    std::unique_ptr<const DocumentSubDBReconfig> prepare_reconfig(const DocumentDBConfig& new_config_snapshot, const DocumentDBConfig& old_config_snapshot, const ReconfigParams& reconfig_params, std::optional<search::SerialNum> serial_num);

    IReprocessingInitializer::UP reconfigure(const DocumentDBConfig &newConfig,
                                             const DocumentDBConfig &oldConfig,
                                             AttributeCollectionSpec && attrSpec,
                                             const DocumentSubDBReconfig& prepared_reconfig,
                                             search::SerialNum serial_num);
};

} // namespace proton

