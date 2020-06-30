//*****************************************************************************
// Copyright 2020 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************
#pragma once
#include <memory>
#include <string>

#include "modelmanager.hpp"
#include "modelinstance.hpp"

namespace ovms {

class ModelInstancePredictRequestsHandlesCountGuard {
public:
    ModelInstancePredictRequestsHandlesCountGuard(ModelInstance& modelInstance) : modelInstance(modelInstance) {
        modelInstance.increasePredictRequestsHandlesCount();
    }
    ~ModelInstancePredictRequestsHandlesCountGuard() {
        modelInstance.decreasePredictRequestsHandlesCount();
    }
private:
    ModelInstance& modelInstance;
};

Status getModelInstance(ModelManager& manager,
                        const std::string& modelName,
                        model_version_t modelVersionId,
                        std::shared_ptr<ModelInstance>& modelInstance,
                        std::unique_ptr<ModelInstancePredictRequestsHandlesCountGuard>& modelInstancePredictRequestsHandlesCountGuardPtr);
}  // namespace ovms