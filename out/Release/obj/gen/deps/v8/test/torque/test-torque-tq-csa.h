#ifndef V8_GEN_TORQUE_GENERATED_______DEPS_V8_TEST_TORQUE_TEST_TORQUE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_______DEPS_V8_TEST_TORQUE_TEST_TORQUE_TQ_H_

#include "src/builtins/builtins-promise.h"
#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<BoolT> ElementsKindTestHelper1_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind);
bool ElementsKindTestHelper2_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind);
void LabelTestHelper1_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label1);
void LabelTestHelper2_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label2, compiler::TypedCodeAssemblerVariable<Smi>* label_Label2_parameter_0);
void LabelTestHelper3_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label3, compiler::TypedCodeAssemblerVariable<Oddball>* label_Label3_parameter_0, compiler::TypedCodeAssemblerVariable<Smi>* label_Label3_parameter_1);
void TestConstexpr1_0(compiler::CodeAssemblerState* state_);
void TestConstexprIf_0(compiler::CodeAssemblerState* state_);
void TestConstexprReturn_0(compiler::CodeAssemblerState* state_);
TNode<Oddball> TestGotoLabel_0(compiler::CodeAssemblerState* state_);
TNode<Oddball> TestGotoLabelWithOneParameter_0(compiler::CodeAssemblerState* state_);
TNode<Oddball> TestGotoLabelWithTwoParameters_0(compiler::CodeAssemblerState* state_);
void TestBuiltinSpecialization_0(compiler::CodeAssemblerState* state_);
void LabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag, compiler::CodeAssemblerLabel* label_Label4, compiler::CodeAssemblerLabel* label_Label5);
TNode<BoolT> CallLabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag);
TNode<Oddball> TestPartiallyUnusedLabel_0(compiler::CodeAssemblerState* state_);
TNode<Object> GenericMacroTest_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2);
TNode<Object> GenericMacroTestWithLabels_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2, compiler::CodeAssemblerLabel* label_Y);
void TestMacroSpecialization_0(compiler::CodeAssemblerState* state_);
TNode<Oddball> TestFunctionPointers_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Oddball> TestVariableRedeclaration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Smi> TestTernaryOperator_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x);
void TestFunctionPointerToGeneric_0(compiler::CodeAssemblerState* state_);
TNode<BuiltinPtr> TestTypeAlias_0(compiler::CodeAssemblerState* state_, TNode<BuiltinPtr> p_x);
TNode<Oddball> TestUnsafeCast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_n);
void TestHexLiteral_0(compiler::CodeAssemblerState* state_);
void TestLargeIntegerLiterals_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c);
void TestMultilineAssert_0(compiler::CodeAssemblerState* state_);
void TestNewlineInString_0(compiler::CodeAssemblerState* state_);
  int31_t kConstexprConst_0(compiler::CodeAssemblerState* state_);
  TNode<IntPtrT> kIntptrConst_0(compiler::CodeAssemblerState* state_);
  TNode<Smi> kSmiConst_0(compiler::CodeAssemblerState* state_);
void TestModuleConstBindings_0(compiler::CodeAssemblerState* state_);
void TestLocalConstBindings_0(compiler::CodeAssemblerState* state_);
TNode<Smi> TestStruct1_0(compiler::CodeAssemblerState* state_, TorqueStructTestStructA_0 p_i);
TorqueStructTestStructA_0 TestStruct2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TorqueStructTestStructA_0 TestStruct3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TorqueStructTestStructC_0 TestStruct4_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void CallTestStructInLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestForLoop_0(compiler::CodeAssemblerState* state_);
void TestSubtyping_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x);
TNode<Int32T> TypeswitchExample_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_x);
void TestTypeswitch_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestTypeswitchAsanLsanFailure_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj);
void TestGenericOverload_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestEquality_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<BoolT> TestOrAnd_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z);
TNode<BoolT> TestAndOr_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z);
void TestLogicalOperators_0(compiler::CodeAssemblerState* state_);
TNode<Smi> TestCall_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_i, compiler::CodeAssemblerLabel* label_A);
void TestOtherwiseWithCode1_0(compiler::CodeAssemblerState* state_);
void TestOtherwiseWithCode2_0(compiler::CodeAssemblerState* state_);
void TestOtherwiseWithCode3_0(compiler::CodeAssemblerState* state_);
void TestForwardLabel_0(compiler::CodeAssemblerState* state_);
void TestQualifiedAccess_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Smi> TestCatch1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestCatch2Wrapper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Smi> TestCatch2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestCatch3WrapperWithLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, compiler::CodeAssemblerLabel* label__Abort);
TNode<Smi> TestCatch3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Map> p_map);
void TestFrame1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestNew_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestStructConstructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<InternalClass> NewInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x);
void TestInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestConstInStructs_0(compiler::CodeAssemblerState* state_);
void TestParentFrameArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Object> TestNewFixedArrayFromSpread_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestReferences_0(compiler::CodeAssemblerState* state_);
void TestSlices_0(compiler::CodeAssemblerState* state_);
TNode<Oddball> TestSliceEnumeration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestStaticAssert_0(compiler::CodeAssemblerState* state_);
void TestLoadEliminationFixed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
void TestLoadEliminationVariable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Smi> TestRedundantArrayElementCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<Smi> TestRedundantSmiCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context);
TNode<IntPtrT> TestGenericStruct1_0(compiler::CodeAssemblerState* state_);
TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0 TestGenericStruct2_0(compiler::CodeAssemblerState* state_);
TNode<BoolT> BranchAndWriteResult_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x, TNode<SmiBox> p_box);
void TestBranchOnBoolOptimization_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_input);
void TestBitFieldLoad_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_val, TNode<BoolT> p_expectedA, TNode<Uint16T> p_expectedB, TNode<Uint32T> p_expectedC, TNode<BoolT> p_expectedD);
void TestBitFieldStore_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_val);
void TestBitFieldInit_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_a, TNode<Uint16T> p_b, TNode<Uint32T> p_c, TNode<BoolT> p_d);
void TestBitFieldUintptrOps_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_val2, TNode<UintPtrT> p_val3);
void TestFullyGeneratedClassWithElements_0(compiler::CodeAssemblerState* state_);
TNode<ExportedSubClass> TestFullyGeneratedClassFromCpp_0(compiler::CodeAssemblerState* state_);
TNode<Smi> LoadInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o);
void StoreInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Smi> p_v);
TNode<Number> LoadInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o);
void StoreInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Number> p_v);
void Method_InternalClass_Flip_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_this, compiler::CodeAssemblerLabel* label_NotASmi);
TNode<Smi> LoadSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o);
void StoreSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o);
void StoreSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v);
TorqueStructReference_Smi_0 Method_SmiPair_GetA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_this);
TNode<Smi> LoadSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o);
void StoreSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v);
TNode<Smi> LoadSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o);
void StoreSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadExportedSubClassBaseA_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o);
void StoreExportedSubClassBaseA_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadExportedSubClassBaseB_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o);
void StoreExportedSubClassBaseB_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o, TNode<HeapObject> p_v);
TNode<Int32T> LoadExportedSubClassCField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o);
void StoreExportedSubClassCField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadExportedSubClassDField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o);
void StoreExportedSubClassDField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o, TNode<Int32T> p_v);
TNode<Smi> LoadExportedSubClassEField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o);
void StoreExportedSubClassEField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o, TNode<Smi> p_v);
TNode<Smi> LoadInternalClassWithSmiElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o);
void StoreInternalClassWithSmiElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<Smi> p_v);
TNode<Oddball> LoadInternalClassWithSmiElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o);
void StoreInternalClassWithSmiElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<Oddball> p_v);
TNode<Smi> LoadInternalClassWithSmiElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<IntPtrT> p_i);
void StoreInternalClassWithSmiElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<IntPtrT> p_i, TNode<Smi> p_v);
TNode<Int32T> LoadInternalClassWithStructElementsDummy1_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o);
void StoreInternalClassWithStructElementsDummy1_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Int32T> p_v);
TNode<Int32T> LoadInternalClassWithStructElementsDummy2_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o);
void StoreInternalClassWithStructElementsDummy2_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Int32T> p_v);
TNode<Smi> LoadInternalClassWithStructElementsCount_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o);
TNode<Smi> LoadInternalClassWithStructElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o);
void StoreInternalClassWithStructElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Smi> p_v);
TNode<Object> LoadInternalClassWithStructElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o);
void StoreInternalClassWithStructElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Object> p_v);
TNode<Smi> LoadInternalClassWithStructElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<IntPtrT> p_i);
void StoreInternalClassWithStructElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<IntPtrT> p_i, TNode<Smi> p_v);
TNode<Object> GenericMacroTest_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param);
TNode<Object> GenericMacroTestWithLabels_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param, compiler::CodeAssemblerLabel* label__X);
TNode<Object> IncrementIfSmi_NumberOrFixedArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_x);
TNode<Smi> ExampleGenericOverload_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_o);
TNode<Object> ExampleGenericOverload_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o);
TNode<BoolT> Is_JSArray_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_o);
void InitializeFieldsFromIterator_Object_TestIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructTestIterator_0 p_originIterator);
void Swap_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Smi_0 p_a, TorqueStructReference_Smi_0 p_b);
TorqueStructTestTuple_Smi_intptr_0 TupleSwap_intptr_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructTestTuple_intptr_Smi_0 p_tuple);
void InitializeFieldsFromIterator_Smi_SmiGeneratorIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Smi_0 p_target, TorqueStructSmiGeneratorIterator_0 p_originIterator);
void InitializeFieldsFromIterator_InternalClassStructElement_InternalClassStructElementGeneratorIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_InternalClassStructElement_0 p_target, TorqueStructInternalClassStructElementGeneratorIterator_0 p_originIterator);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_______DEPS_V8_TEST_TORQUE_TEST_TORQUE_TQ_H_
