/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_DATA_RECORDER_RECORD_SERVICE_H_
#define MODULES_DATA_RECORDER_RECORD_SERVICE_H_

#include <memory>

#include "cybertron/common/macros.h"
#include "cybertron/cybertron.h"
#include "cybertron/service/service.h"
#include "modules/data/proto/record_request.pb.h"
#include "modules/data/proto/record_response.pb.h"

/**
 * @namespace apollo::data
 * @brief apollo::data
 */
namespace apollo {
namespace data {

class RecordService {
 public:
  static bool Init(const std::shared_ptr<apollo::cybertron::Node>& node);
 private:
  static void OnRecordRequest(
      const std::shared_ptr<RecordRequest> &request,
      const std::shared_ptr<RecordResponse> &response);
 private:
  std::shared_ptr<apollo::cybertron::Service<RecordRequest, RecordResponse>>
      server_;
  DECLARE_SINGLETON(RecordService);
};

}  // namespace data
}  // namespace apollo

#endif  // MODULES_DATA_RECORDER_RECORD_SERVICE_H_
