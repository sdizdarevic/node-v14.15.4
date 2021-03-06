#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_PROMISE_ABSTRACT_OPERATIONS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_PROMISE_ABSTRACT_OPERATIONS_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Context> ExtractHandlerContextInternal_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_handler, compiler::CodeAssemblerLabel* label_NotFound);
TNode<Context> ExtractHandlerContext_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_handler);
TNode<Context> ExtractHandlerContext_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_primary, TNode<HeapObject> p_secondary);
void MorphAndEnqueuePromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<PromiseReaction> p_promiseReaction, TNode<Object> p_argument, PromiseReaction::Type p_reactionType);
void TriggerPromiseReactions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_reactions, TNode<Object> p_argument, PromiseReaction::Type p_reactionType);
TNode<Context> CreatePromiseCapabilitiesExecutorContext_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_nativeContext, TNode<PromiseCapability> p_capability);
TNode<PromiseCapability> CreatePromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_promise, TNode<HeapObject> p_resolve, TNode<HeapObject> p_reject);
TorqueStructPromiseResolvingFunctions CreatePromiseResolvingFunctions_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<Object> p_debugEvent, TNode<NativeContext> p_nativeContext);
TNode<PromiseCapability> InnerNewPromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_constructor, TNode<Object> p_debugEvent);
void PerformPromiseThenImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSPromise> p_promise, TNode<HeapObject> p_onFulfilled, TNode<HeapObject> p_onRejected, TNode<HeapObject> p_resultPromiseOrCapability);
TNode<Object> CallResolve_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_constructor, TNode<Object> p_resolve, TNode<Object> p_value);
TNode<JSBoundFunction> Cast_JSBoundFunction_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);
TorqueStructReference_Map_0 UnsafeConstCast_Map_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Map_0 p_r);
TNode<PromiseFulfillReactionJobTask> UnsafeCast_PromiseFulfillReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<PromiseRejectReactionJobTask> UnsafeCast_PromiseRejectReactionJobTask_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<Object> UnsafeCast_Zero_OR_PromiseReaction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<BoolT> Is_Callable_Object_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<JSPromise> UnsafeCast_JSPromise_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
TNode<PromiseCapability> UnsafeCast_PromiseCapability_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_BUILTINS_PROMISE_ABSTRACT_OPERATIONS_TQ_H_
