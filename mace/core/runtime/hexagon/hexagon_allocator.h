// Copyright 2020 The MACE Authors. All Rights Reserved.
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

#ifndef MACE_CORE_RUNTIME_HEXAGON_HEXAGON_ALLOCATOR_H_
#define MACE_CORE_RUNTIME_HEXAGON_HEXAGON_ALLOCATOR_H_

#include "mace/core/allocator.h"

namespace mace {

class HexagonAllocator : public Allocator {
 public:
  MaceStatus New(size_t nbytes, void **result) override;

  void Delete(void *buffer) override;

  bool OnHost() const override;

  Rpcmem *rpcmem() override;

 private:
  Rpcmem rpcmem_;
};

}  // namespace mace

#endif  // MACE_CORE_RUNTIME_HEXAGON_HEXAGON_ALLOCATOR_H_