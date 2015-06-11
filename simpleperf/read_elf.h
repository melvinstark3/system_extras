/*
 * Copyright (C) 2015 The Android Open Source Project
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

#ifndef SIMPLE_PERF_READ_ELF_H_
#define SIMPLE_PERF_READ_ELF_H_

#include <functional>
#include <string>
#include "build_id.h"

bool GetBuildIdFromNoteFile(const std::string& filename, BuildId* build_id);
bool GetBuildIdFromElfFile(const std::string& filename, BuildId* build_id);

struct ElfFileSymbol {
  uint64_t start_in_file;
  uint64_t len;
  bool is_func;
  bool is_in_text_section;
  std::string name;
};

bool ParseSymbolsFromElfFile(const std::string& filename,
                             std::function<void(const ElfFileSymbol&)> callback);

#endif  // SIMPLE_PERF_READ_ELF_H_
