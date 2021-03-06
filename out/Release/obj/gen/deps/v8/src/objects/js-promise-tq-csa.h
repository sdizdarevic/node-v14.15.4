#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_JS_PROMISE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_JS_PROMISE_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> LoadJSPromiseReactionsOrResult_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_o);
void StoreJSPromiseReactionsOrResult_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_o, TNode<Object> p_v);
TNode<Smi> LoadJSPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_o);
void StoreJSPromiseFlags_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_o, TNode<Smi> p_v);
TNode<Int32T> Method_JSPromise_Status_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_this);
void Method_JSPromise_SetStatus_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_this, Promise::PromiseState p_status);
TNode<BoolT> Method_JSPromise_HasHandler_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_this);
void Method_JSPromise_SetHasHandler_0(compiler::CodeAssemblerState* state_, TNode<JSPromise> p_this);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_JS_PROMISE_TQ_H_
