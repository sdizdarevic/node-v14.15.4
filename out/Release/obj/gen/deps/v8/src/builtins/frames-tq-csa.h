#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_FRAMES_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_FRAMES_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Smi> FromConstexpr_FrameType_constexpr_FrameType_0(compiler::CodeAssemblerState* state_, StackFrame::Type p_t);
TNode<Smi> Cast_FrameType_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> LoadObjectFromFrame_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_f, int32_t p_o);
TNode<RawPtrT> LoadPointerFromFrame_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_f, int32_t p_o);
TNode<Smi> LoadSmiFromFrame_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_f, int32_t p_o);
TNode<JSFunction> LoadFunctionFromFrame_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_f);
TNode<RawPtrT> LoadCallerFromFrame_0(compiler::CodeAssemblerState* state_, TNode<RawPtrT> p_f);
TNode<Object> Cast_ContextOrFrameType_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> LoadContextOrFrameTypeFromFrame_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_f);
TNode<Smi> LoadLengthFromAdapterFrame_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_f);
TNode<BoolT> FrameTypeEquals_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_f1, TNode<Smi> p_f2);
TNode<RawPtrT> Cast_StandardFrame_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_f, compiler::CodeAssemblerLabel* label_CastError);
TNode<RawPtrT> Cast_ArgumentsAdaptorFrame_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RawPtrT> p_f, compiler::CodeAssemblerLabel* label_CastError);
TNode<JSFunction> LoadTargetFromFrame_0(compiler::CodeAssemblerState* state_);
TNode<Context> Cast_Context_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TNode<Object> UnsafeCast_ContextOrFrameType_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_FRAMES_TQ_H_
