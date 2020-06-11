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

#include "luci/IR/Nodes/CircleLessEqual.h"

#include "luci/IR/CircleDialect.h"
#include "luci/IR/CircleNodeVisitor.h"

#include <gtest/gtest.h>

TEST(CircleLessEqualTest, constructor_P)
{
  luci::CircleLessEqual less_equal_node;

  ASSERT_EQ(luci::CircleDialect::get(), less_equal_node.dialect());
  ASSERT_EQ(luci::CircleOpcode::LESS_EQUAL, less_equal_node.opcode());

  ASSERT_EQ(nullptr, less_equal_node.x());
  ASSERT_EQ(nullptr, less_equal_node.y());
}

TEST(CircleLessEqualTest, input_NEG)
{
  luci::CircleLessEqual less_equal_node;
  luci::CircleLessEqual node;

  less_equal_node.x(&node);
  less_equal_node.y(&node);
  ASSERT_NE(nullptr, less_equal_node.x());
  ASSERT_NE(nullptr, less_equal_node.y());

  less_equal_node.x(nullptr);
  less_equal_node.y(nullptr);
  ASSERT_EQ(nullptr, less_equal_node.x());
  ASSERT_EQ(nullptr, less_equal_node.y());
}

TEST(CircleLessEqualTest, arity_NEG)
{
  luci::CircleLessEqual less_equal_node;

  ASSERT_NO_THROW(less_equal_node.arg(1));
  ASSERT_THROW(less_equal_node.arg(2), std::out_of_range);
}

TEST(CircleLessEqualTest, visit_mutable_NEG)
{
  struct TestVisitor final : public luci::CircleNodeMutableVisitor<void>
  {
  };

  luci::CircleLessEqual less_equal_node;

  TestVisitor tv;
  ASSERT_THROW(less_equal_node.accept(&tv), std::exception);
}

TEST(CircleLessEqualTest, visit_NEG)
{
  struct TestVisitor final : public luci::CircleNodeVisitor<void>
  {
  };

  luci::CircleLessEqual less_equal_node;

  TestVisitor tv;
  ASSERT_THROW(less_equal_node.accept(&tv), std::exception);
}
