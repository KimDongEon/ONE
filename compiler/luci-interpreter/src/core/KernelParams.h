/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LUCI_INTERPRETER_CORE_KERNELPARAMS_H
#define LUCI_INTERPRETER_CORE_KERNELPARAMS_H

#include <luci/IR/AttrPadding.h>
#include <luci/IR/AttrFusedActFunc.h>

#include <cstdint>

namespace luci_interpreter
{

// Inject commonly used types into `luci_interpreter` namespace for convenience.
using Activation = luci::FusedActFunc;
using Padding = luci::Padding;

struct ConcatenationParams
{
  int axis;
};

struct DepthwiseConv2DParams
{
  Padding padding;
  int32_t depth_multiplier; // TODO Remove, as it can be calculated.
  int32_t stride_height;
  int32_t stride_width;
  int32_t dilation_height_factor;
  int32_t dilation_width_factor;
  Activation activation;
};

struct FullyConnectedParams
{
  Activation activation;
};

struct MulParams
{
  Activation activation;
};

struct Pool2DParams
{
  Padding padding;
  int32_t filter_height;
  int32_t filter_width;
  int32_t stride_height;
  int32_t stride_width;
  Activation activation;
};

struct SoftmaxParams
{
  float beta;
};

} // namespace luci_interpreter

#endif // LUCI_INTERPRETER_CORE_KERNELPARAMS_H
