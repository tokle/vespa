// Copyright Verizon Media. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include "i_bm_feed_handler.h"

namespace document { class DocumentTypeRepo; }
namespace documentapi { class DocumentMessage; };
namespace storage::api { class StorageMessageAddress; }

namespace feedbm {

class BmMessageBus;

/*
 * Benchmark feed handler for feed to distributor using document api protocol
 * over message bus.
 */
class DocumentApiMessageBusBmFeedHandler : public IBmFeedHandler
{
    vespalib::string _name;
    std::unique_ptr<storage::api::StorageMessageAddress> _storage_address;
    BmMessageBus&                                        _message_bus;
    void send_msg(std::unique_ptr<documentapi::DocumentMessage> msg, PendingTracker& tracker);
public:
    DocumentApiMessageBusBmFeedHandler(BmMessageBus &message_bus);
    ~DocumentApiMessageBusBmFeedHandler();
    void put(const document::Bucket& bucket, std::unique_ptr<document::Document> document, uint64_t timestamp, PendingTracker& tracker) override;
    void update(const document::Bucket& bucket, std::unique_ptr<document::DocumentUpdate> document_update, uint64_t timestamp, PendingTracker& tracker) override;
    void remove(const document::Bucket& bucket, const document::DocumentId& document_id,  uint64_t timestamp, PendingTracker& tracker) override;
    void attach_bucket_info_queue(PendingTracker &tracker) override;
    uint32_t get_error_count() const override;
    const vespalib::string &get_name() const override;
    bool manages_buckets() const override;
    bool manages_timestamp() const override;
};

}
