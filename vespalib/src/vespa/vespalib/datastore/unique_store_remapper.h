// Copyright Yahoo. Licensed under the terms of the Apache 2.0 license. See LICENSE in the project root.

#pragma once

#include "entryref.h"
#include "entry_ref_filter.h"
#include <vector>
#include <vespa/vespalib/stllike/allocator.h>

namespace vespalib::datastore {

/**
 * Remapper for related UniqueStore class, used for adjusting
 * references to unique store after compaction.
 */
template <typename RefT>
class UniqueStoreRemapper {
public:
    using RefType = RefT;

protected:
    EntryRefFilter _compacting_buffer;
    std::vector<std::vector<EntryRef, allocator_large<EntryRef>>> _mapping;
public:
    UniqueStoreRemapper()
        : _compacting_buffer(RefT::numBuffers(), RefT::offset_bits),
          _mapping()
    {
    }
    virtual ~UniqueStoreRemapper() = default;

    EntryRef remap(EntryRef ref) const {
        if (ref.valid()) {
            if (!_compacting_buffer.has(ref)) {
                // No remapping for references to buffers not being compacted
                return ref;
            } else {
                RefType internal_ref(ref);
                auto &inner_mapping = _mapping[internal_ref.bufferId()];
                assert(internal_ref.unscaled_offset() < inner_mapping.size());
                EntryRef mapped_ref = inner_mapping[internal_ref.unscaled_offset()];
                assert(mapped_ref.valid());
                return mapped_ref;
            }
        } else {
            return EntryRef();
        }
    }

    void remap(vespalib::ArrayRef<EntryRef> refs) const {
        for (auto &ref : refs) {
            auto mapped_ref = remap(ref);
            if (mapped_ref != ref) {
                ref = mapped_ref;
            }
        }
    }

    virtual void done() = 0;
};

}
