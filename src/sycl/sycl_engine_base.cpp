/*******************************************************************************
* Copyright 2019 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "sycl/sycl_engine_base.hpp"

#include "common/memory.hpp"
#include "common/memory_storage.hpp"
#include "sycl/sycl_memory_storage.hpp"
#include "sycl/sycl_stream.hpp"

namespace mkldnn {
namespace impl {
namespace sycl {

status_t sycl_engine_base_t::create_memory_storage(memory_storage_t **storage,
        unsigned flags, size_t size, void *handle) {
    return safe_ptr_assign<memory_storage_t>(*storage,
            new memory_storage_t(
                    new sycl_memory_storage_t(this, flags, size, handle)));
}

status_t sycl_engine_base_t::create_stream(stream_t **stream, unsigned flags) {
    return sycl_stream_t::create_stream(stream, this, flags);
}
status_t sycl_engine_base_t::create_stream(stream_t **stream, cl::sycl::queue &queue) {
    return sycl_stream_t::create_stream(stream, this, queue);
}

} // namespace sycl
} // namespace impl
} // namespace mkldnn
