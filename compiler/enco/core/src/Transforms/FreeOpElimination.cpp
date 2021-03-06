/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "FreeOpElimination.h"

#include <cassert>
#include <set>

namespace
{

/**
 * @brief Return the set of Free Op Elimination candidates
 */
std::set<coco::Op *> candidates(const coco::Module *m)
{
  std::set<coco::Op *> res;

  for (uint32_t n = 0; n < m->entity()->op()->size(); ++n)
  {
    if (auto op = m->entity()->op()->at(n))
    {
      if ((op->parent() == nullptr) && (op->up() == nullptr))
      {
        res.insert(op);
      }
    }
  }

  return res;
}

} // namespace

namespace enco
{

void eliminate_free_op(coco::Module *m)
{
  for (auto op : candidates(m))
  {
    m->entity()->op()->destroy_all(op);
  }
}

} // namespace enco
