/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ONERT_BACKEND_CPU_KERNEL_STRIDEDSLICELAYER_H__
#define __ONERT_BACKEND_CPU_KERNEL_STRIDEDSLICELAYER_H__

#include "../operand/Tensor.h"
#include "OperationUtils.h"

#include <exec/IFunction.h>

namespace onert
{
namespace backend
{
namespace cpu
{
namespace kernel
{

class StridedSliceLayer : public ::onert::exec::IFunction
{
public:
  StridedSliceLayer();

public:
  void configure(const operand::Tensor *input, const operand::Tensor *begin,
                 const operand::Tensor *end, const operand::Tensor *strides,
                 operand::Tensor *output, const int32_t begin_mask, const int32_t end_mask,
                 const int32_t shrink_axis_mask, const int32_t rank);

  void run();
  void runSync()
  {
    // this abstract method is used just for profiling and called for
    // backend::acl_common::AclFunction
    run();
  }

private:
  void stridedSliceFloat32();
  void stridedSliceQuant8();

private:
  const operand::Tensor *_input;
  const operand::Tensor *_begin;
  const operand::Tensor *_end;
  const operand::Tensor *_strides;
  operand::Tensor *_output;

  int32_t _begin_mask;
  int32_t _ellipsis_mask;
  int32_t _end_mask;
  int32_t _new_axis_mask;
  int32_t _shrink_axis_mask;

  int32_t _rank;
};

} // namespace kernel
} // namespace cpu
} // namespace backend
} // namespace onert

#endif // __ONERT_BACKEND_CPU_KERNEL_STRIDEDSLICELAYER_H__
