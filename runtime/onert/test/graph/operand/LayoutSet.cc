/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include <gtest/gtest.h>

#include "ir/LayoutSet.h"

using onert::ir::Layout;
using onert::ir::LayoutSet;

TEST(graph_operand_LayoutSet, layout_set_operators)
{
  LayoutSet set1{Layout::NCHW};
  LayoutSet set2{Layout::NHWC};
  LayoutSet set3 = set1 | set2;

  ASSERT_EQ(set3.size(), 2);

  ASSERT_EQ((set3 - set1).size(), 1);
  ASSERT_EQ((set3 - set1).contains(Layout::NHWC), true);
  ASSERT_EQ((set3 - set2).size(), 1);
  ASSERT_EQ((set3 - set2).contains(Layout::NCHW), true);
  ASSERT_EQ((set3 - set3).size(), 0);

  ASSERT_EQ((set3 & set1).size(), 1);
  ASSERT_EQ((set3 & set1).contains(Layout::NCHW), true);
  ASSERT_EQ((set3 & set2).size(), 1);
  ASSERT_EQ((set3 & set2).contains(Layout::NHWC), true);
  ASSERT_EQ((set1 & set2).size(), 0);
}
