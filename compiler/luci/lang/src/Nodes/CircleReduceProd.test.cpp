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

#include "luci/IR/Nodes/CircleReduceProd.h"

#include "luci/IR/CircleDialect.h"

#include <gtest/gtest.h>

TEST(CircleReduceProdTest, constructor)
{
  luci::CircleReduceProd reduce_prod_node;

  ASSERT_EQ(luci::CircleDialect::get(), reduce_prod_node.dialect());
  ASSERT_EQ(luci::CircleOpcode::REDUCE_PROD, reduce_prod_node.opcode());

  ASSERT_EQ(nullptr, reduce_prod_node.input());
  ASSERT_EQ(nullptr, reduce_prod_node.reduction_indices());

  ASSERT_FALSE(reduce_prod_node.keep_dims());
}
