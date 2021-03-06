/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_AOT_TFCOMPILE_UTIL_H_
#define TENSORFLOW_COMPILER_AOT_TFCOMPILE_UTIL_H_

#include "tensorflow/compiler/aot/tfcompile.pb.h"
#include "tensorflow/core/framework/graph.pb.h"
#include "tensorflow/core/lib/core/status.h"
#include "tensorflow/core/lib/core/stringpiece.h"

namespace tensorflow {
namespace tfcompile {

// ValidateCppIdent returns OK iff ident is a valid C++ identifier.  The msg is
// appended to error messages.
Status ValidateCppIdent(StringPiece ident, StringPiece msg);

// ValidateConfig returns OK iff config is valid.
Status ValidateConfig(const Config& config);

// Returns in <out> a copy of <in>, pruned to only include fetches from
// <config>.
Status PruneGraphDefInto(const Config& config, const GraphDef& in,
                         GraphDef* out);

}  // namespace tfcompile
}  // namespace tensorflow

#endif  // TENSORFLOW_COMPILER_AOT_TFCOMPILE_UTIL_H_
