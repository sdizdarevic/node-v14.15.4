#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_MAP_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_MAP_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<PrototypeInfo> LoadMapPrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_m, compiler::CodeAssemblerLabel* label_HasNoPrototypeInfo);
TNode<Uint8T> LoadMapInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadMapInObjectPropertiesStartOrConstructorFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapInObjectPropertiesStartOrConstructorFunctionIndex_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadMapUsedOrUnusedInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapUsedOrUnusedInstanceSizeInWords_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadMapVisitorId_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapVisitorId_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v);
TNode<Uint16T> LoadMapInstanceType_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapInstanceType_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint16T> p_v);
TNode<Uint8T> LoadMapBitField_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapBitField_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v);
TNode<Uint8T> LoadMapBitField2_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapBitField2_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint8T> p_v);
TNode<Uint32T> LoadMapBitField3_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapBitField3_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Uint32T> p_v);
TNode<HeapObject> LoadMapPrototype_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapPrototype_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<HeapObject> p_v);
TNode<Object> LoadMapConstructorOrBackPointerOrNativeContext_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapConstructorOrBackPointerOrNativeContext_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Object> p_v);
TNode<DescriptorArray> LoadMapInstanceDescriptors_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapInstanceDescriptors_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<DescriptorArray> p_v);
TNode<WeakFixedArray> LoadMapDependentCode_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapDependentCode_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<WeakFixedArray> p_v);
TNode<Object> LoadMapPrototypeValidityCell_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapPrototypeValidityCell_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<Object> p_v);
TNode<MaybeObject> LoadMapTransitionsOrPrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o);
void StoreMapTransitionsOrPrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_o, TNode<MaybeObject> p_v);
TNode<PrototypeInfo> Method_Map_PrototypeInfo_0(compiler::CodeAssemblerState* state_, TNode<Map> p_this, compiler::CodeAssemblerLabel* label_HasNoPrototypeInfo);
TNode<MaybeObject> Cast_Weak_Map_0(compiler::CodeAssemblerState* state_, TNode<MaybeObject> p_o, compiler::CodeAssemblerLabel* label_CastError);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_SRC_OBJECTS_MAP_TQ_H_