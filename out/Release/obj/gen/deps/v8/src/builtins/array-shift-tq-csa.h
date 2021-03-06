#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_ARRAY_SHIFT_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_ARRAY_SHIFT_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> TryFastArrayShift_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, compiler::CodeAssemblerLabel* label_Slow, compiler::CodeAssemblerLabel* label_Runtime);
TNode<Object> GenericArrayShift_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_ARRAY_SHIFT_TQ_H_
