
/*
 * This file is generated by ../../deps/v8/tools/gen-postmortem-metadata.py.  Do not edit directly.
 */

#include "src/init/v8.h"
#include "src/execution/frames.h"
#include "src/execution/frames-inl.h" /* for architecture-specific frame constants */
#include "src/objects/contexts.h"
#include "src/objects/objects.h"
#include "src/objects/data-handler.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"

namespace v8 {
namespace internal {

extern "C" {

/* stack frame constants */
#define FRAME_CONST(value, klass)           int v8dbg_frametype_##klass = StackFrame::value;

STACK_FRAME_TYPE_LIST(FRAME_CONST)

#undef FRAME_CONST

/* miscellaneous constants */
int v8dbg_FirstNonstringType = FIRST_NONSTRING_TYPE;
int v8dbg_APIObjectType = JS_API_OBJECT_TYPE;
int v8dbg_SpecialAPIObjectType = JS_SPECIAL_API_OBJECT_TYPE;
int v8dbg_FirstContextType = FIRST_CONTEXT_TYPE;
int v8dbg_LastContextType = LAST_CONTEXT_TYPE;
int v8dbg_IsNotStringMask = kIsNotStringMask;
int v8dbg_StringTag = kStringTag;
int v8dbg_StringEncodingMask = kStringEncodingMask;
int v8dbg_TwoByteStringTag = kTwoByteStringTag;
int v8dbg_OneByteStringTag = kOneByteStringTag;
int v8dbg_StringRepresentationMask = kStringRepresentationMask;
int v8dbg_SeqStringTag = kSeqStringTag;
int v8dbg_ConsStringTag = kConsStringTag;
int v8dbg_ExternalStringTag = kExternalStringTag;
int v8dbg_SlicedStringTag = kSlicedStringTag;
int v8dbg_ThinStringTag = kThinStringTag;
int v8dbg_HeapObjectTag = kHeapObjectTag;
int v8dbg_HeapObjectTagMask = kHeapObjectTagMask;
int v8dbg_SmiTag = kSmiTag;
int v8dbg_SmiTagMask = kSmiTagMask;
int v8dbg_SmiValueShift = kSmiTagSize;
int v8dbg_SmiShiftSize = kSmiShiftSize;
int v8dbg_SystemPointerSize = kSystemPointerSize;
int v8dbg_SystemPointerSizeLog2 = kSystemPointerSizeLog2;
int v8dbg_TaggedSize = kTaggedSize;
int v8dbg_TaggedSizeLog2 = kTaggedSizeLog2;
int v8dbg_OddballFalse = Oddball::kFalse;
int v8dbg_OddballTrue = Oddball::kTrue;
int v8dbg_OddballTheHole = Oddball::kTheHole;
int v8dbg_OddballNull = Oddball::kNull;
int v8dbg_OddballArgumentsMarker = Oddball::kArgumentsMarker;
int v8dbg_OddballUndefined = Oddball::kUndefined;
int v8dbg_OddballUninitialized = Oddball::kUninitialized;
int v8dbg_OddballOther = Oddball::kOther;
int v8dbg_OddballException = Oddball::kException;
int v8dbg_prop_kind_Data = kData;
int v8dbg_prop_kind_Accessor = kAccessor;
int v8dbg_prop_kind_mask = PropertyDetails::KindField::kMask;
int v8dbg_prop_location_Descriptor = kDescriptor;
int v8dbg_prop_location_Field = kField;
int v8dbg_prop_location_mask = PropertyDetails::LocationField::kMask;
int v8dbg_prop_location_shift = PropertyDetails::LocationField::kShift;
int v8dbg_prop_attributes_NONE = NONE;
int v8dbg_prop_attributes_READ_ONLY = READ_ONLY;
int v8dbg_prop_attributes_DONT_ENUM = DONT_ENUM;
int v8dbg_prop_attributes_DONT_DELETE = DONT_DELETE;
int v8dbg_prop_attributes_mask = PropertyDetails::AttributesField::kMask;
int v8dbg_prop_attributes_shift = PropertyDetails::AttributesField::kShift;
int v8dbg_prop_index_mask = PropertyDetails::FieldIndexField::kMask;
int v8dbg_prop_index_shift = PropertyDetails::FieldIndexField::kShift;
int v8dbg_prop_representation_mask = PropertyDetails::RepresentationField::kMask;
int v8dbg_prop_representation_shift = PropertyDetails::RepresentationField::kShift;
int v8dbg_prop_representation_smi = Representation::Kind::kSmi;
int v8dbg_prop_representation_double = Representation::Kind::kDouble;
int v8dbg_prop_representation_heapobject = Representation::Kind::kHeapObject;
int v8dbg_prop_representation_tagged = Representation::Kind::kTagged;
int v8dbg_prop_desc_key = DescriptorArray::kEntryKeyIndex;
int v8dbg_prop_desc_details = DescriptorArray::kEntryDetailsIndex;
int v8dbg_prop_desc_value = DescriptorArray::kEntryValueIndex;
int v8dbg_prop_desc_size = DescriptorArray::kEntrySize;
int v8dbg_elements_fast_holey_elements = HOLEY_ELEMENTS;
int v8dbg_elements_fast_elements = PACKED_ELEMENTS;
int v8dbg_elements_dictionary_elements = DICTIONARY_ELEMENTS;
int v8dbg_bit_field2_elements_kind_mask = Map::Bits2::ElementsKindBits::kMask;
int v8dbg_bit_field2_elements_kind_shift = Map::Bits2::ElementsKindBits::kShift;
int v8dbg_bit_field3_is_dictionary_map_shift = Map::Bits3::IsDictionaryMapBit::kShift;
int v8dbg_bit_field3_number_of_own_descriptors_mask = Map::Bits3::NumberOfOwnDescriptorsBits::kMask;
int v8dbg_bit_field3_number_of_own_descriptors_shift = Map::Bits3::NumberOfOwnDescriptorsBits::kShift;
int v8dbg_class_Map__instance_descriptors_offset = Map::kInstanceDescriptorsOffset;
int v8dbg_off_fp_context_or_frame_type = CommonFrameConstants::kContextOrFrameTypeOffset;
int v8dbg_off_fp_context = StandardFrameConstants::kContextOffset;
int v8dbg_off_fp_constant_pool = StandardFrameConstants::kConstantPoolOffset;
int v8dbg_off_fp_function = StandardFrameConstants::kFunctionOffset;
int v8dbg_off_fp_args = StandardFrameConstants::kFixedFrameSizeAboveFp;
int v8dbg_scopeinfo_idx_nparams = ScopeInfo::kParameterCount;
int v8dbg_scopeinfo_idx_ncontextlocals = ScopeInfo::kContextLocalCount;
int v8dbg_scopeinfo_idx_first_vars = ScopeInfo::kVariablePartIndex;
int v8dbg_jsarray_buffer_was_detached_mask = JSArrayBuffer::WasDetachedBit::kMask;
int v8dbg_jsarray_buffer_was_detached_shift = JSArrayBuffer::WasDetachedBit::kShift;
int v8dbg_context_idx_scope_info = Context::SCOPE_INFO_INDEX;
int v8dbg_context_idx_prev = Context::PREVIOUS_INDEX;
int v8dbg_context_min_slots = Context::MIN_CONTEXT_SLOTS;
int v8dbg_native_context_embedder_data_offset = Internals::kNativeContextEmbedderDataOffset;
int v8dbg_namedictionaryshape_prefix_size = NameDictionaryShape::kPrefixSize;
int v8dbg_namedictionaryshape_entry_size = NameDictionaryShape::kEntrySize;
int v8dbg_globaldictionaryshape_entry_size = GlobalDictionaryShape::kEntrySize;
int v8dbg_namedictionary_prefix_start_index = NameDictionary::kPrefixStartIndex;
int v8dbg_numberdictionaryshape_prefix_size = NumberDictionaryShape::kPrefixSize;
int v8dbg_numberdictionaryshape_entry_size = NumberDictionaryShape::kEntrySize;
int v8dbg_simplenumberdictionaryshape_prefix_size = SimpleNumberDictionaryShape::kPrefixSize;
int v8dbg_simplenumberdictionaryshape_entry_size = SimpleNumberDictionaryShape::kEntrySize;
int v8dbg_type_JSError__JS_ERROR_TYPE = JS_ERROR_TYPE;
int v8dbg_class_SharedFunctionInfo__function_data__Object = SharedFunctionInfo::kFunctionDataOffset;

/* class type information */
int v8dbg_type_AbstractInternalClassSubclass1__ABSTRACT_INTERNAL_CLASS_SUBCLASS1_TYPE = ABSTRACT_INTERNAL_CLASS_SUBCLASS1_TYPE;
int v8dbg_type_AbstractInternalClassSubclass2__ABSTRACT_INTERNAL_CLASS_SUBCLASS2_TYPE = ABSTRACT_INTERNAL_CLASS_SUBCLASS2_TYPE;
int v8dbg_type_AccessorInfo__ACCESSOR_INFO_TYPE = ACCESSOR_INFO_TYPE;
int v8dbg_type_AccessorPair__ACCESSOR_PAIR_TYPE = ACCESSOR_PAIR_TYPE;
int v8dbg_type_AccessCheckInfo__ACCESS_CHECK_INFO_TYPE = ACCESS_CHECK_INFO_TYPE;
int v8dbg_type_AliasedArgumentsEntry__ALIASED_ARGUMENTS_ENTRY_TYPE = ALIASED_ARGUMENTS_ENTRY_TYPE;
int v8dbg_type_AllocationMemento__ALLOCATION_MEMENTO_TYPE = ALLOCATION_MEMENTO_TYPE;
int v8dbg_type_AllocationSite__ALLOCATION_SITE_TYPE = ALLOCATION_SITE_TYPE;
int v8dbg_type_ArrayBoilerplateDescription__ARRAY_BOILERPLATE_DESCRIPTION_TYPE = ARRAY_BOILERPLATE_DESCRIPTION_TYPE;
int v8dbg_type_AsmWasmData__ASM_WASM_DATA_TYPE = ASM_WASM_DATA_TYPE;
int v8dbg_type_AsyncGeneratorRequest__ASYNC_GENERATOR_REQUEST_TYPE = ASYNC_GENERATOR_REQUEST_TYPE;
int v8dbg_type_BigIntBase__BIG_INT_BASE_TYPE = BIG_INT_BASE_TYPE;
int v8dbg_type_BreakPointInfo__BREAK_POINT_INFO_TYPE = BREAK_POINT_INFO_TYPE;
int v8dbg_type_BreakPoint__BREAK_POINT_TYPE = BREAK_POINT_TYPE;
int v8dbg_type_BytecodeArray__BYTECODE_ARRAY_TYPE = BYTECODE_ARRAY_TYPE;
int v8dbg_type_ByteArray__BYTE_ARRAY_TYPE = BYTE_ARRAY_TYPE;
int v8dbg_type_CachedTemplateObject__CACHED_TEMPLATE_OBJECT_TYPE = CACHED_TEMPLATE_OBJECT_TYPE;
int v8dbg_type_CallableTask__CALLABLE_TASK_TYPE = CALLABLE_TASK_TYPE;
int v8dbg_type_CallbackTask__CALLBACK_TASK_TYPE = CALLBACK_TASK_TYPE;
int v8dbg_type_CallHandlerInfo__CALL_HANDLER_INFO_TYPE = CALL_HANDLER_INFO_TYPE;
int v8dbg_type_Cell__CELL_TYPE = CELL_TYPE;
int v8dbg_type_ClassPositions__CLASS_POSITIONS_TYPE = CLASS_POSITIONS_TYPE;
int v8dbg_type_CodeDataContainer__CODE_DATA_CONTAINER_TYPE = CODE_DATA_CONTAINER_TYPE;
int v8dbg_type_Code__CODE_TYPE = CODE_TYPE;
int v8dbg_type_ConsString__CONS_ONE_BYTE_STRING_TYPE = CONS_ONE_BYTE_STRING_TYPE;
int v8dbg_type_ConsString__CONS_STRING_TYPE = CONS_STRING_TYPE;
int v8dbg_type_CoverageInfo__COVERAGE_INFO_TYPE = COVERAGE_INFO_TYPE;
int v8dbg_type_DebugInfo__DEBUG_INFO_TYPE = DEBUG_INFO_TYPE;
int v8dbg_type_DescriptorArray__DESCRIPTOR_ARRAY_TYPE = DESCRIPTOR_ARRAY_TYPE;
int v8dbg_type_EmbedderDataArray__EMBEDDER_DATA_ARRAY_TYPE = EMBEDDER_DATA_ARRAY_TYPE;
int v8dbg_type_EnumCache__ENUM_CACHE_TYPE = ENUM_CACHE_TYPE;
int v8dbg_type_ExportedSubClass__EXPORTED_SUB_CLASS_TYPE = EXPORTED_SUB_CLASS_TYPE;
int v8dbg_type_ExternalOneByteString__EXTERNAL_ONE_BYTE_STRING_TYPE = EXTERNAL_ONE_BYTE_STRING_TYPE;
int v8dbg_type_ExternalTwoByteString__EXTERNAL_STRING_TYPE = EXTERNAL_STRING_TYPE;
int v8dbg_type_FeedbackCell__FEEDBACK_CELL_TYPE = FEEDBACK_CELL_TYPE;
int v8dbg_type_FeedbackVector__FEEDBACK_VECTOR_TYPE = FEEDBACK_VECTOR_TYPE;
int v8dbg_type_FixedArray__FIXED_ARRAY_TYPE = FIXED_ARRAY_TYPE;
int v8dbg_type_FixedDoubleArray__FIXED_DOUBLE_ARRAY_TYPE = FIXED_DOUBLE_ARRAY_TYPE;
int v8dbg_type_Foreign__FOREIGN_TYPE = FOREIGN_TYPE;
int v8dbg_type_FreeSpace__FREE_SPACE_TYPE = FREE_SPACE_TYPE;
int v8dbg_type_FunctionTemplateInfo__FUNCTION_TEMPLATE_INFO_TYPE = FUNCTION_TEMPLATE_INFO_TYPE;
int v8dbg_type_FunctionTemplateRareData__FUNCTION_TEMPLATE_RARE_DATA_TYPE = FUNCTION_TEMPLATE_RARE_DATA_TYPE;
int v8dbg_type_HeapNumber__HEAP_NUMBER_TYPE = HEAP_NUMBER_TYPE;
int v8dbg_type_InterceptorInfo__INTERCEPTOR_INFO_TYPE = INTERCEPTOR_INFO_TYPE;
int v8dbg_type_InternalClass__INTERNAL_CLASS_TYPE = INTERNAL_CLASS_TYPE;
int v8dbg_type_InternalClassWithSmiElements__INTERNAL_CLASS_WITH_SMI_ELEMENTS_TYPE = INTERNAL_CLASS_WITH_SMI_ELEMENTS_TYPE;
int v8dbg_type_InternalClassWithStructElements__INTERNAL_CLASS_WITH_STRUCT_ELEMENTS_TYPE = INTERNAL_CLASS_WITH_STRUCT_ELEMENTS_TYPE;
int v8dbg_type_InterpreterData__INTERPRETER_DATA_TYPE = INTERPRETER_DATA_TYPE;
int v8dbg_type_JSAggregateError__JS_AGGREGATE_ERROR_TYPE = JS_AGGREGATE_ERROR_TYPE;
int v8dbg_type_JSArgumentsObject__JS_ARGUMENTS_OBJECT_TYPE = JS_ARGUMENTS_OBJECT_TYPE;
int v8dbg_type_JSArrayBuffer__JS_ARRAY_BUFFER_TYPE = JS_ARRAY_BUFFER_TYPE;
int v8dbg_type_JSArrayIterator__JS_ARRAY_ITERATOR_TYPE = JS_ARRAY_ITERATOR_TYPE;
int v8dbg_type_JSArray__JS_ARRAY_TYPE = JS_ARRAY_TYPE;
int v8dbg_type_JSAsyncFromSyncIterator__JS_ASYNC_FROM_SYNC_ITERATOR_TYPE = JS_ASYNC_FROM_SYNC_ITERATOR_TYPE;
int v8dbg_type_JSAsyncFunctionObject__JS_ASYNC_FUNCTION_OBJECT_TYPE = JS_ASYNC_FUNCTION_OBJECT_TYPE;
int v8dbg_type_JSAsyncGeneratorObject__JS_ASYNC_GENERATOR_OBJECT_TYPE = JS_ASYNC_GENERATOR_OBJECT_TYPE;
int v8dbg_type_JSBoundFunction__JS_BOUND_FUNCTION_TYPE = JS_BOUND_FUNCTION_TYPE;
int v8dbg_type_JSCollator__JS_COLLATOR_TYPE = JS_COLLATOR_TYPE;
int v8dbg_type_JSDataView__JS_DATA_VIEW_TYPE = JS_DATA_VIEW_TYPE;
int v8dbg_type_JSDateTimeFormat__JS_DATE_TIME_FORMAT_TYPE = JS_DATE_TIME_FORMAT_TYPE;
int v8dbg_type_JSDate__JS_DATE_TYPE = JS_DATE_TYPE;
int v8dbg_type_JSDisplayNames__JS_DISPLAY_NAMES_TYPE = JS_DISPLAY_NAMES_TYPE;
int v8dbg_type_JSFinalizationRegistry__JS_FINALIZATION_REGISTRY_TYPE = JS_FINALIZATION_REGISTRY_TYPE;
int v8dbg_type_JSFunction__JS_FUNCTION_TYPE = JS_FUNCTION_TYPE;
int v8dbg_type_JSGlobalObject__JS_GLOBAL_OBJECT_TYPE = JS_GLOBAL_OBJECT_TYPE;
int v8dbg_type_JSGlobalProxy__JS_GLOBAL_PROXY_TYPE = JS_GLOBAL_PROXY_TYPE;
int v8dbg_type_JSListFormat__JS_LIST_FORMAT_TYPE = JS_LIST_FORMAT_TYPE;
int v8dbg_type_JSLocale__JS_LOCALE_TYPE = JS_LOCALE_TYPE;
int v8dbg_type_JSMap__JS_MAP_TYPE = JS_MAP_TYPE;
int v8dbg_type_JSMessageObject__JS_MESSAGE_OBJECT_TYPE = JS_MESSAGE_OBJECT_TYPE;
int v8dbg_type_JSModuleNamespace__JS_MODULE_NAMESPACE_TYPE = JS_MODULE_NAMESPACE_TYPE;
int v8dbg_type_JSNumberFormat__JS_NUMBER_FORMAT_TYPE = JS_NUMBER_FORMAT_TYPE;
int v8dbg_type_JSObject__JS_OBJECT_TYPE = JS_OBJECT_TYPE;
int v8dbg_type_JSPluralRules__JS_PLURAL_RULES_TYPE = JS_PLURAL_RULES_TYPE;
int v8dbg_type_JSPrimitiveWrapper__JS_PRIMITIVE_WRAPPER_TYPE = JS_PRIMITIVE_WRAPPER_TYPE;
int v8dbg_type_JSPromise__JS_PROMISE_TYPE = JS_PROMISE_TYPE;
int v8dbg_type_JSProxy__JS_PROXY_TYPE = JS_PROXY_TYPE;
int v8dbg_type_JSRegExpStringIterator__JS_REG_EXP_STRING_ITERATOR_TYPE = JS_REG_EXP_STRING_ITERATOR_TYPE;
int v8dbg_type_JSRegExp__JS_REG_EXP_TYPE = JS_REG_EXP_TYPE;
int v8dbg_type_JSRelativeTimeFormat__JS_RELATIVE_TIME_FORMAT_TYPE = JS_RELATIVE_TIME_FORMAT_TYPE;
int v8dbg_type_JSSegmenter__JS_SEGMENTER_TYPE = JS_SEGMENTER_TYPE;
int v8dbg_type_JSSegmentIterator__JS_SEGMENT_ITERATOR_TYPE = JS_SEGMENT_ITERATOR_TYPE;
int v8dbg_type_JSSet__JS_SET_TYPE = JS_SET_TYPE;
int v8dbg_type_JSStringIterator__JS_STRING_ITERATOR_TYPE = JS_STRING_ITERATOR_TYPE;
int v8dbg_type_JSTypedArray__JS_TYPED_ARRAY_TYPE = JS_TYPED_ARRAY_TYPE;
int v8dbg_type_JSV8BreakIterator__JS_V8_BREAK_ITERATOR_TYPE = JS_V8_BREAK_ITERATOR_TYPE;
int v8dbg_type_JSWeakMap__JS_WEAK_MAP_TYPE = JS_WEAK_MAP_TYPE;
int v8dbg_type_JSWeakRef__JS_WEAK_REF_TYPE = JS_WEAK_REF_TYPE;
int v8dbg_type_JSWeakSet__JS_WEAK_SET_TYPE = JS_WEAK_SET_TYPE;
int v8dbg_type_Map__MAP_TYPE = MAP_TYPE;
int v8dbg_type_ObjectTemplateInfo__OBJECT_TEMPLATE_INFO_TYPE = OBJECT_TEMPLATE_INFO_TYPE;
int v8dbg_type_Oddball__ODDBALL_TYPE = ODDBALL_TYPE;
int v8dbg_type_InternalizedString__ONE_BYTE_INTERNALIZED_STRING_TYPE = ONE_BYTE_INTERNALIZED_STRING_TYPE;
int v8dbg_type_SeqOneByteString__ONE_BYTE_STRING_TYPE = ONE_BYTE_STRING_TYPE;
int v8dbg_type_PreparseData__PREPARSE_DATA_TYPE = PREPARSE_DATA_TYPE;
int v8dbg_type_PromiseCapability__PROMISE_CAPABILITY_TYPE = PROMISE_CAPABILITY_TYPE;
int v8dbg_type_PromiseFulfillReactionJobTask__PROMISE_FULFILL_REACTION_JOB_TASK_TYPE = PROMISE_FULFILL_REACTION_JOB_TASK_TYPE;
int v8dbg_type_PromiseReaction__PROMISE_REACTION_TYPE = PROMISE_REACTION_TYPE;
int v8dbg_type_PromiseRejectReactionJobTask__PROMISE_REJECT_REACTION_JOB_TASK_TYPE = PROMISE_REJECT_REACTION_JOB_TASK_TYPE;
int v8dbg_type_PromiseResolveThenableJobTask__PROMISE_RESOLVE_THENABLE_JOB_TASK_TYPE = PROMISE_RESOLVE_THENABLE_JOB_TASK_TYPE;
int v8dbg_type_PropertyArray__PROPERTY_ARRAY_TYPE = PROPERTY_ARRAY_TYPE;
int v8dbg_type_PropertyCell__PROPERTY_CELL_TYPE = PROPERTY_CELL_TYPE;
int v8dbg_type_PropertyDescriptorObject__PROPERTY_DESCRIPTOR_OBJECT_TYPE = PROPERTY_DESCRIPTOR_OBJECT_TYPE;
int v8dbg_type_PrototypeInfo__PROTOTYPE_INFO_TYPE = PROTOTYPE_INFO_TYPE;
int v8dbg_type_ScopeInfo__SCOPE_INFO_TYPE = SCOPE_INFO_TYPE;
int v8dbg_type_Script__SCRIPT_TYPE = SCRIPT_TYPE;
int v8dbg_type_SharedFunctionInfo__SHARED_FUNCTION_INFO_TYPE = SHARED_FUNCTION_INFO_TYPE;
int v8dbg_type_SlicedString__SLICED_ONE_BYTE_STRING_TYPE = SLICED_ONE_BYTE_STRING_TYPE;
int v8dbg_type_SlicedString__SLICED_STRING_TYPE = SLICED_STRING_TYPE;
int v8dbg_type_SmallOrderedHashMap__SMALL_ORDERED_HASH_MAP_TYPE = SMALL_ORDERED_HASH_MAP_TYPE;
int v8dbg_type_SmallOrderedHashSet__SMALL_ORDERED_HASH_SET_TYPE = SMALL_ORDERED_HASH_SET_TYPE;
int v8dbg_type_SmallOrderedNameDictionary__SMALL_ORDERED_NAME_DICTIONARY_TYPE = SMALL_ORDERED_NAME_DICTIONARY_TYPE;
int v8dbg_type_SmiBox__SMI_BOX_TYPE = SMI_BOX_TYPE;
int v8dbg_type_SmiPair__SMI_PAIR_TYPE = SMI_PAIR_TYPE;
int v8dbg_type_SortState__SORT_STATE_TYPE = SORT_STATE_TYPE;
int v8dbg_type_SourceTextModuleInfoEntry__SOURCE_TEXT_MODULE_INFO_ENTRY_TYPE = SOURCE_TEXT_MODULE_INFO_ENTRY_TYPE;
int v8dbg_type_SourceTextModule__SOURCE_TEXT_MODULE_TYPE = SOURCE_TEXT_MODULE_TYPE;
int v8dbg_type_StackFrameInfo__STACK_FRAME_INFO_TYPE = STACK_FRAME_INFO_TYPE;
int v8dbg_type_StackTraceFrame__STACK_TRACE_FRAME_TYPE = STACK_TRACE_FRAME_TYPE;
int v8dbg_type_SeqTwoByteString__STRING_TYPE = STRING_TYPE;
int v8dbg_type_Symbol__SYMBOL_TYPE = SYMBOL_TYPE;
int v8dbg_type_SyntheticModule__SYNTHETIC_MODULE_TYPE = SYNTHETIC_MODULE_TYPE;
int v8dbg_type_TemplateObjectDescription__TEMPLATE_OBJECT_DESCRIPTION_TYPE = TEMPLATE_OBJECT_DESCRIPTION_TYPE;
int v8dbg_type_Tuple2__TUPLE2_TYPE = TUPLE2_TYPE;
int v8dbg_type_UncompiledDataWithoutPreparseData__UNCOMPILED_DATA_WITHOUT_PREPARSE_DATA_TYPE = UNCOMPILED_DATA_WITHOUT_PREPARSE_DATA_TYPE;
int v8dbg_type_UncompiledDataWithPreparseData__UNCOMPILED_DATA_WITH_PREPARSE_DATA_TYPE = UNCOMPILED_DATA_WITH_PREPARSE_DATA_TYPE;
int v8dbg_type_WasmArray__WASM_ARRAY_TYPE = WASM_ARRAY_TYPE;
int v8dbg_type_WasmCapiFunctionData__WASM_CAPI_FUNCTION_DATA_TYPE = WASM_CAPI_FUNCTION_DATA_TYPE;
int v8dbg_type_WasmDebugInfo__WASM_DEBUG_INFO_TYPE = WASM_DEBUG_INFO_TYPE;
int v8dbg_type_WasmExceptionObject__WASM_EXCEPTION_OBJECT_TYPE = WASM_EXCEPTION_OBJECT_TYPE;
int v8dbg_type_WasmExceptionTag__WASM_EXCEPTION_TAG_TYPE = WASM_EXCEPTION_TAG_TYPE;
int v8dbg_type_WasmExportedFunctionData__WASM_EXPORTED_FUNCTION_DATA_TYPE = WASM_EXPORTED_FUNCTION_DATA_TYPE;
int v8dbg_type_WasmGlobalObject__WASM_GLOBAL_OBJECT_TYPE = WASM_GLOBAL_OBJECT_TYPE;
int v8dbg_type_WasmIndirectFunctionTable__WASM_INDIRECT_FUNCTION_TABLE_TYPE = WASM_INDIRECT_FUNCTION_TABLE_TYPE;
int v8dbg_type_WasmJSFunctionData__WASM_JS_FUNCTION_DATA_TYPE = WASM_JS_FUNCTION_DATA_TYPE;
int v8dbg_type_WasmMemoryObject__WASM_MEMORY_OBJECT_TYPE = WASM_MEMORY_OBJECT_TYPE;
int v8dbg_type_WasmModuleObject__WASM_MODULE_OBJECT_TYPE = WASM_MODULE_OBJECT_TYPE;
int v8dbg_type_WasmStruct__WASM_STRUCT_TYPE = WASM_STRUCT_TYPE;
int v8dbg_type_WasmTableObject__WASM_TABLE_OBJECT_TYPE = WASM_TABLE_OBJECT_TYPE;
int v8dbg_type_WasmValue__WASM_VALUE_TYPE = WASM_VALUE_TYPE;
int v8dbg_type_WeakArrayList__WEAK_ARRAY_LIST_TYPE = WEAK_ARRAY_LIST_TYPE;
int v8dbg_type_WeakCell__WEAK_CELL_TYPE = WEAK_CELL_TYPE;
int v8dbg_type_WeakFixedArray__WEAK_FIXED_ARRAY_TYPE = WEAK_FIXED_ARRAY_TYPE;

/* class hierarchy information */
int v8dbg_parent_AbstractCode__HeapObject = 0;
int v8dbg_parent_AccessorPair__Struct = 0;
int v8dbg_parent_AllocationMemento__Struct = 0;
int v8dbg_parent_AllocationSite__Struct = 0;
int v8dbg_parent_ArrayList__FixedArray = 0;
int v8dbg_parent_ByteArray__FixedArrayBase = 0;
int v8dbg_parent_BytecodeArray__FixedArrayBase = 0;
int v8dbg_parent_Cell__HeapObject = 0;
int v8dbg_parent_ClassPositions__Struct = 0;
int v8dbg_parent_Code__HeapObject = 0;
int v8dbg_parent_CodeDataContainer__HeapObject = 0;
int v8dbg_parent_ConsString__String = 0;
int v8dbg_parent_DataHandler__Struct = 0;
int v8dbg_parent_DeoptimizationData__FixedArray = 0;
int v8dbg_parent_DependentCode__WeakFixedArray = 0;
int v8dbg_parent_DescriptorArray__HeapObject = 0;
int v8dbg_parent_EnumCache__Struct = 0;
int v8dbg_parent_ExternalOneByteString__ExternalString = 0;
int v8dbg_parent_ExternalString__String = 0;
int v8dbg_parent_ExternalTwoByteString__ExternalString = 0;
int v8dbg_parent_FeedbackCell__Struct = 0;
int v8dbg_parent_FixedArray__FixedArrayBase = 0;
int v8dbg_parent_FixedArrayBase__HeapObject = 0;
int v8dbg_parent_FixedArrayExactfinal__FixedArray = 0;
int v8dbg_parent_FixedDoubleArray__FixedArrayBase = 0;
int v8dbg_parent_HeapNumber__PrimitiveHeapObject = 0;
int v8dbg_parent_HeapObject__Object = 0;
int v8dbg_parent_InternalizedString__String = 0;
int v8dbg_parent_InterpreterData__Struct = 0;
int v8dbg_parent_JSAccessorPropertyDescriptor__JSObject = 0;
int v8dbg_parent_JSAggregateError__JSObject = 0;
int v8dbg_parent_JSArray__JSObject = 0;
int v8dbg_parent_JSArrayBuffer__JSObject = 0;
int v8dbg_parent_JSArrayBufferView__JSObject = 0;
int v8dbg_parent_JSArrayIterator__JSObject = 0;
int v8dbg_parent_JSAsyncFromSyncIterator__JSObject = 0;
int v8dbg_parent_JSBoundFunction__JSFunctionOrBoundFunction = 0;
int v8dbg_parent_JSCustomElementsObject__JSObject = 0;
int v8dbg_parent_JSDataPropertyDescriptor__JSObject = 0;
int v8dbg_parent_JSDataView__JSArrayBufferView = 0;
int v8dbg_parent_JSDate__JSObject = 0;
int v8dbg_parent_JSFunction__JSFunctionOrBoundFunction = 0;
int v8dbg_parent_JSFunctionOrBoundFunction__JSObject = 0;
int v8dbg_parent_JSGlobalObject__JSSpecialObject = 0;
int v8dbg_parent_JSGlobalProxy__JSSpecialObject = 0;
int v8dbg_parent_JSIteratorResult__JSObject = 0;
int v8dbg_parent_JSMessageObject__JSObject = 0;
int v8dbg_parent_JSObject__JSReceiver = 0;
int v8dbg_parent_JSPrimitiveWrapper__JSCustomElementsObject = 0;
int v8dbg_parent_JSPromise__JSObject = 0;
int v8dbg_parent_JSReceiver__HeapObject = 0;
int v8dbg_parent_JSRegExp__JSObject = 0;
int v8dbg_parent_JSRegExpResult__JSArray = 0;
int v8dbg_parent_JSRegExpResultIndices__JSArray = 0;
int v8dbg_parent_JSRegExpStringIterator__JSObject = 0;
int v8dbg_parent_JSSpecialObject__JSCustomElementsObject = 0;
int v8dbg_parent_JSStringIterator__JSObject = 0;
int v8dbg_parent_JSTypedArray__JSArrayBufferView = 0;
int v8dbg_parent_Map__HeapObject = 0;
int v8dbg_parent_Name__PrimitiveHeapObject = 0;
int v8dbg_parent_NormalizedMapCache__WeakFixedArray = 0;
int v8dbg_parent_Object__TaggedImpl = 0;
int v8dbg_parent_Oddball__PrimitiveHeapObject = 0;
int v8dbg_parent_PodArray__ByteArray = 0;
int v8dbg_parent_PreparseData__HeapObject = 0;
int v8dbg_parent_PrimitiveHeapObject__HeapObject = 0;
int v8dbg_parent_ScopeInfo__FixedArray = 0;
int v8dbg_parent_Script__Struct = 0;
int v8dbg_parent_SeqOneByteString__SeqString = 0;
int v8dbg_parent_SeqString__String = 0;
int v8dbg_parent_SeqTwoByteString__SeqString = 0;
int v8dbg_parent_SharedFunctionInfo__HeapObject = 0;
int v8dbg_parent_SlicedString__String = 0;
int v8dbg_parent_String__Name = 0;
int v8dbg_parent_Struct__HeapObject = 0;
int v8dbg_parent_Symbol__Name = 0;
int v8dbg_parent_TemplateList__FixedArray = 0;
int v8dbg_parent_ThinString__String = 0;
int v8dbg_parent_Tuple2__Struct = 0;
int v8dbg_parent_UncompiledData__HeapObject = 0;
int v8dbg_parent_UncompiledDataWithPreparseData__UncompiledData = 0;
int v8dbg_parent_UncompiledDataWithoutPreparseData__UncompiledData = 0;
int v8dbg_parent_WeakArrayList__HeapObject = 0;
int v8dbg_parent_WeakFixedArray__HeapObject = 0;

/* field information */
int v8dbg_class_AllocationSite__transition_info_or_boilerplate__Object = AllocationSite::kTransitionInfoOrBoilerplateOffset;
int v8dbg_class_AllocationSite__nested_site__Object = AllocationSite::kNestedSiteOffset;
int v8dbg_class_AllocationSite__dependent_code__DependentCode = AllocationSite::kDependentCodeOffset;
int v8dbg_class_AllocationSite__weak_next__Object = AllocationSite::kWeakNextOffset;
int v8dbg_class_AllocationMemento__allocation_site__Object = AllocationMemento::kAllocationSiteOffset;
int v8dbg_class_CodeDataContainer__next_code_link__Object = CodeDataContainer::kNextCodeLinkOffset;
int v8dbg_class_BytecodeArray__constant_pool__FixedArray = BytecodeArray::kConstantPoolOffset;
int v8dbg_class_BytecodeArray__handler_table__ByteArray = BytecodeArray::kHandlerTableOffset;
int v8dbg_class_BytecodeArray__source_position_table__Object = BytecodeArray::kSourcePositionTableOffset;
int v8dbg_class_DataHandler__smi_handler__Object = DataHandler::kSmiHandlerOffset;
int v8dbg_class_DataHandler__validity_cell__Object = DataHandler::kValidityCellOffset;
int v8dbg_class_DataHandler__data1__weak = DataHandler::kData1Offset;
int v8dbg_class_DataHandler__data2__weak = DataHandler::kData2Offset;
int v8dbg_class_DataHandler__data3__weak = DataHandler::kData3Offset;
int v8dbg_class_JSArray__length__Object = JSArray::kLengthOffset;
int v8dbg_class_JSArrayIterator__iterated_object__Object = JSArrayIterator::kIteratedObjectOffset;
int v8dbg_class_JSArrayIterator__next_index__Object = JSArrayIterator::kNextIndexOffset;
int v8dbg_class_JSArrayIterator__raw_kind__SMI = JSArrayIterator::kKindOffset;
int v8dbg_class_JSReceiver__raw_properties_or_hash__Object = JSReceiver::kPropertiesOrHashOffset;
int v8dbg_class_JSFunction__raw_feedback_cell__FeedbackCell = JSFunction::kFeedbackCellOffset;
int v8dbg_class_JSGlobalObject__native_context__NativeContext = JSGlobalObject::kNativeContextOffset;
int v8dbg_class_JSGlobalObject__global_proxy__JSGlobalProxy = JSGlobalObject::kGlobalProxyOffset;
int v8dbg_class_JSFunction__prototype_or_initial_map__HeapObject = JSFunction::kPrototypeOrInitialMapOffset;
int v8dbg_class_JSMessageObject__argument__Object = JSMessageObject::kArgumentsOffset;
int v8dbg_class_JSMessageObject__script__Script = JSMessageObject::kScriptOffset;
int v8dbg_class_JSMessageObject__stack_frames__Object = JSMessageObject::kStackFramesOffset;
int v8dbg_class_JSMessageObject__shared_info__HeapObject = JSMessageObject::kSharedInfoOffset;
int v8dbg_class_JSMessageObject__bytecode_offset__Smi = JSMessageObject::kBytecodeOffsetOffset;
int v8dbg_class_JSMessageObject__start_position__SMI = JSMessageObject::kStartPositionOffset;
int v8dbg_class_JSMessageObject__end_position__SMI = JSMessageObject::kEndPositionOffset;
int v8dbg_class_JSMessageObject__error_level__SMI = JSMessageObject::kErrorLevelOffset;
int v8dbg_class_JSMessageObject__raw_type__SMI = JSMessageObject::kMessageTypeOffset;
int v8dbg_class_JSIteratorResult__value__Object = JSIteratorResult::kValueOffset;
int v8dbg_class_JSIteratorResult__done__Object = JSIteratorResult::kDoneOffset;
int v8dbg_class_JSRegExp__last_index__Object = JSRegExp::kLastIndexOffset;
int v8dbg_class_Map__synchronized_instance_descriptors__DescriptorArray = Map::kInstanceDescriptorsOffset;
int v8dbg_class_Map__layout_descriptor__LayoutDescriptor = Map::kLayoutDescriptorOffset;
int v8dbg_class_Map__raw_transitions__weak = Map::kTransitionsOrPrototypeInfoOffset;
int v8dbg_class_Map__prototype__HeapObject = Map::kPrototypeOffset;
int v8dbg_class_Map__prototype_info__Object = Map::kTransitionsOrPrototypeInfoOffset;
int v8dbg_class_Map__dependent_code__DependentCode = Map::kDependentCodeOffset;
int v8dbg_class_Map__prototype_validity_cell__Object = Map::kPrototypeValidityCellOffset;
int v8dbg_class_Map__constructor_or_backpointer__Object = Map::kConstructorOrBackPointerOrNativeContextOffset;
int v8dbg_class_Map__native_context__NativeContext = Map::kConstructorOrBackPointerOrNativeContextOffset;
int v8dbg_class_Map__wasm_type_info__Foreign = Map::kConstructorOrBackPointerOrNativeContextOffset;
int v8dbg_class_Script__source__Object = Script::kSourceOffset;
int v8dbg_class_Script__name__Object = Script::kNameOffset;
int v8dbg_class_Script__id__SMI = Script::kIdOffset;
int v8dbg_class_Script__line_offset__SMI = Script::kLineOffsetOffset;
int v8dbg_class_Script__column_offset__SMI = Script::kColumnOffsetOffset;
int v8dbg_class_Script__context_data__Object = Script::kContextOffset;
int v8dbg_class_Script__type__SMI = Script::kScriptTypeOffset;
int v8dbg_class_Script__line_ends__Object = Script::kLineEndsOffset;
int v8dbg_class_Script__eval_from_shared_or_wrapped_arguments__Object = Script::kEvalFromSharedOrWrappedArgumentsOffset;
int v8dbg_class_Script__eval_from_position__SMI = Script::kEvalFromPositionOffset;
int v8dbg_class_Script__flags__SMI = Script::kFlagsOffset;
int v8dbg_class_Script__source_url__Object = Script::kSourceUrlOffset;
int v8dbg_class_Script__source_mapping_url__Object = Script::kSourceMappingUrlOffset;
int v8dbg_class_Script__host_defined_options__FixedArray = Script::kHostDefinedOptionsOffset;
int v8dbg_class_Script__wasm_breakpoint_infos__FixedArray = Script::kEvalFromSharedOrWrappedArgumentsOffset;
int v8dbg_class_Script__wasm_managed_native_module__Object = Script::kEvalFromPositionOffset;
int v8dbg_class_Script__wasm_weak_instance_list__WeakArrayList = Script::kSharedFunctionInfosOffset;
int v8dbg_class_InterpreterData__bytecode_array__BytecodeArray = InterpreterData::kBytecodeArrayOffset;
int v8dbg_class_InterpreterData__interpreter_trampoline__Code = InterpreterData::kInterpreterTrampolineOffset;
int v8dbg_class_SharedFunctionInfo__name_or_scope_info__Object = SharedFunctionInfo::kNameOrScopeInfoOffset;
int v8dbg_class_SharedFunctionInfo__script_or_debug_info__HeapObject = SharedFunctionInfo::kScriptOrDebugInfoOffset;
int v8dbg_class_SharedFunctionInfo__raw_outer_scope_info_or_feedback_metadata__HeapObject = SharedFunctionInfo::kOuterScopeInfoOrFeedbackMetadataOffset;
int v8dbg_class_JSFunction__context__Context = JSFunction::kContextOffset;
int v8dbg_class_JSFunction__shared__SharedFunctionInfo = JSFunction::kSharedFunctionInfoOffset;
int v8dbg_class_HeapObject__map__Map = HeapObject::kMapOffset;
int v8dbg_class_JSObject__elements__Object = JSObject::kElementsOffset;
int v8dbg_class_JSObject__internal_fields__uintptr_t = JSObject::kHeaderSize;
int v8dbg_class_FixedArray__data__uintptr_t = FixedArray::kHeaderSize;
int v8dbg_class_JSArrayBuffer__backing_store__uintptr_t = JSArrayBuffer::kBackingStoreOffset;
int v8dbg_class_JSArrayBuffer__byte_length__size_t = JSArrayBuffer::kByteLengthOffset;
int v8dbg_class_JSArrayBufferView__byte_length__size_t = JSArrayBufferView::kByteLengthOffset;
int v8dbg_class_JSArrayBufferView__byte_offset__size_t = JSArrayBufferView::kByteOffsetOffset;
int v8dbg_class_JSDate__value__Object = JSDate::kValueOffset;
int v8dbg_class_JSRegExp__source__Object = JSRegExp::kSourceOffset;
int v8dbg_class_JSTypedArray__external_pointer__uintptr_t = JSTypedArray::kExternalPointerOffset;
int v8dbg_class_JSTypedArray__length__Object = JSTypedArray::kLengthOffset;
int v8dbg_class_Map__instance_size_in_words__char = Map::kInstanceSizeInWordsOffset;
int v8dbg_class_Map__inobject_properties_start_or_constructor_function_index__char = Map::kInObjectPropertiesStartOrConstructorFunctionIndexOffset;
int v8dbg_class_Map__instance_type__uint16_t = Map::kInstanceTypeOffset;
int v8dbg_class_Map__bit_field__char = Map::kBitFieldOffset;
int v8dbg_class_Map__bit_field2__char = Map::kBitField2Offset;
int v8dbg_class_Map__bit_field3__int = Map::kBitField3Offset;
int v8dbg_class_Map__prototype__Object = Map::kPrototypeOffset;
int v8dbg_class_Oddball__kind_offset__int = Oddball::kKindOffset;
int v8dbg_class_HeapNumber__value__double = HeapNumber::kValueOffset;
int v8dbg_class_ExternalString__resource__Object = ExternalString::kResourceOffset;
int v8dbg_class_SeqOneByteString__chars__char = SeqOneByteString::kHeaderSize;
int v8dbg_class_SeqTwoByteString__chars__char = SeqTwoByteString::kHeaderSize;
int v8dbg_class_UncompiledData__start_position__int32_t = UncompiledData::kStartPositionOffset;
int v8dbg_class_UncompiledData__end_position__int32_t = UncompiledData::kEndPositionOffset;
int v8dbg_class_SharedFunctionInfo__raw_function_token_offset__int16_t = SharedFunctionInfo::kFunctionTokenOffsetOffset;
int v8dbg_class_SharedFunctionInfo__internal_formal_parameter_count__uint16_t = SharedFunctionInfo::kFormalParameterCountOffset;
int v8dbg_class_SharedFunctionInfo__flags__int = SharedFunctionInfo::kFlagsOffset;
int v8dbg_class_SharedFunctionInfo__length__uint16_t = SharedFunctionInfo::kLengthOffset;
int v8dbg_class_SlicedString__parent__String = SlicedString::kParentOffset;
int v8dbg_class_Code__instruction_start__uintptr_t = Code::kHeaderSize;
int v8dbg_class_Code__instruction_size__int = Code::kInstructionSizeOffset;
int v8dbg_class_String__length__int32_t = String::kLengthOffset;
int v8dbg_class_DescriptorArray__header_size__uintptr_t = DescriptorArray::kHeaderSize;
int v8dbg_class_ConsString__first__String = ConsString::kFirstOffset;
int v8dbg_class_ConsString__second__String = ConsString::kSecondOffset;
int v8dbg_class_SlicedString__offset__SMI = SlicedString::kOffsetOffset;
int v8dbg_class_ThinString__actual__String = ThinString::kActualOffset;
int v8dbg_class_Symbol__name__Object = Symbol::kDescriptionOffset;
int v8dbg_class_FixedArrayBase__length__SMI = FixedArrayBase::kLengthOffset;


}

}
}