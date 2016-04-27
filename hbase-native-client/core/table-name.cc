/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#include "core/table-name.h"

#include <folly/Conv.h>

using namespace hbase;

TableName::TableName(std::string table_name)
    : name_space_("default"), table_(table_name) {}
TableName::TableName(std::string name_space, std::string table_name)
    : name_space_(name_space), table_(table_name) {}
bool TableName::is_default_name_space() const {
  return name_space_.length() == 0 || name_space_ == "default";
}
bool TableName::operator==(const TableName &other) const {
  return name_space_ == other.name_space_ && table_ == other.table_;
}