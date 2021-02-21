#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_FOREIGN_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_FOREIGN_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<ExternalPointerT> LoadForeignForeignAddress_0(compiler::CodeAssemblerState* state_, TNode<Foreign> p_o);
void StoreForeignForeignAddress_0(compiler::CodeAssemblerState* state_, TNode<Foreign> p_o, TNode<ExternalPointerT> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_FOREIGN_TQ_H_
