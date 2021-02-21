#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins-wasm-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/heap/factory-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/js-aggregate-error.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/ordered-hash-table.h"
#include "src/objects/property-array.h"
#include "src/objects/property-descriptor-object.h"
#include "src/objects/source-text-module.h"
#include "src/objects/stack-frame-info.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "src/torque/runtime-support.h"
#include "torque-generated/../../deps/v8/src/builtins/array-copywithin-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-every-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-filter-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-find-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-foreach-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-from-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-join-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-map-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-reduce-right-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-reduce-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-some-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-unshift-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/base-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/bigint-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/boolean-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/collections-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/cast-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/convert-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/console-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/data-view-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/finalization-registry-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/frames-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/ic-callable-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/ic-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/internal-coverage-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/math-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/number-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/object-fromentries-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-all-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-all-element-closure-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-any-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-finally-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-misc-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-race-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-reaction-job-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-resolve-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-then-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/promise-jobs-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-constructor-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-get-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-has-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-revocable-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-revoke-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-set-property-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/proxy-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/reflect-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-search-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-source-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-split-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-test-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/regexp-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-endswith-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-html-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-pad-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-repeat-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-replaceall-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-slice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-startswith-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-substring-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/string-substr-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/symbol-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-find-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-findindex-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-foreach-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-of-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-reduce-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-reduceright-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-set-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-some-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/builtins/wasm-tq-csa.h"
#include "torque-generated/../../deps/v8/src/ic/handler-configuration-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/allocation-site-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/api-callbacks-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/arguments-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/cell-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/code-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/contexts-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/data-handler-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/debug-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/embedder-data-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/feedback-cell-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/foreign-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/free-space-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/heap-number-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/heap-object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-aggregate-error-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-collection-iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-collection-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-generator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-promise-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-regexp-string-iterator-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/js-weak-refs-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/literal-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/map-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/microtask-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/module-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/name-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/oddball-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/primitive-heap-object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/promise-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/property-array-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/property-cell-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/property-descriptor-object-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/prototype-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/scope-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/script-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/shared-function-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/source-text-module-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/stack-frame-info-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/string-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/struct-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/synthetic-module-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/template-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/template-tq-csa.h"
#include "torque-generated/../../deps/v8/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/../../deps/v8/test/torque/test-torque-tq-csa.h"
#include "torque-generated/../../deps/v8/third_party/v8/builtins/array-sort-tq-csa.h"
#include "torque-generated/../../deps/v8/src/objects/intl-objects-tq-csa.h"

namespace v8 {
namespace internal {

TNode<Map> kSmallOrderedHashSetMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Map> tmp0;
    tmp0 = CodeStubAssembler(state_).SmallOrderedHashSetMapConstant();
  return TNode<Map>{tmp0};
}

TNode<SmallOrderedHashSet> AllocateSmallOrderedHashSet_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Map> tmp2;
  TNode<Uint8T> tmp3;
  TNode<Uint8T> tmp4;
  TNode<Uint8T> tmp5;
  TNode<Oddball> tmp6;
  TNode<Oddball> tmp7;
  TNode<Uint8T> tmp8;
  TNode<Uint8T> tmp9;
  TNode<Uint8T> tmp10;
  TNode<Uint8T> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<HeapObject> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Uint8T> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<Uint8T> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<SmallOrderedHashSet> tmp38;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp1 = CodeStubAssembler(state_).IntPtrDiv(TNode<IntPtrT>{p_capacity}, TNode<IntPtrT>{tmp0});
    tmp2 = kSmallOrderedHashSetMap_0(state_);
    tmp3 = Convert_uint8_intptr_0(state_, TNode<IntPtrT>{tmp1});
    tmp4 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    std::tie(tmp5) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp4}).Flatten();
    tmp6 = TheHole_0(state_);
    std::tie(tmp7) = ConstantIterator_TheHole_0(state_, TNode<Oddball>{tmp6}).Flatten();
    tmp8 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp9) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp8}).Flatten();
    tmp10 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp11) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp10}).Flatten();
    tmp12 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp14 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp12}, kUInt8Size);
    tmp15 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp17 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp15}, TNode<IntPtrT>{tmp16});
    tmp18 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp17});
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp20 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp18}, kTaggedSize);
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp22 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp21}, kUInt8Size);
    tmp23 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp25 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp24});
    tmp26 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp25});
    tmp27 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26}, kUInt8Size);
    tmp28 = AlignTagged_0(state_, TNode<IntPtrT>{tmp27});
    tmp29 = Allocate_0(state_, TNode<IntPtrT>{tmp28}, TNode<Map>{tmp2});
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp29, tmp30}, tmp2);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp32 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp29, tmp31}, tmp32);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp34 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp29, tmp33}, tmp34);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp29, tmp35}, tmp3);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp29}, TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp12}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp5}});
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_ConstantIterator_TheHole_0(state_, TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0{TNode<HeapObject>{tmp29}, TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp18}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_TheHole_0{TNode<Oddball>{tmp7}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp29}, TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp21}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp9}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp29}, TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp26}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp11}});
    tmp38 = TORQUE_CAST(TNode<HeapObject>{tmp29});
    ca_.Goto(&block9);
  }

    ca_.Bind(&block9);
  return TNode<SmallOrderedHashSet>{tmp38};
}

TNode<Map> kSmallOrderedHashMapMap_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Map> tmp0;
    tmp0 = CodeStubAssembler(state_).SmallOrderedHashMapMapConstant();
  return TNode<Map>{tmp0};
}

TNode<SmallOrderedHashMap> AllocateSmallOrderedHashMap_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_capacity) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<Map> tmp2;
  TNode<Uint8T> tmp3;
  TNode<Uint8T> tmp4;
  TNode<Uint8T> tmp5;
  TNode<Oddball> tmp6;
  TNode<Oddball> tmp7;
  TNode<Object> tmp8;
  TNode<Object> tmp9;
  TNode<Uint8T> tmp10;
  TNode<Uint8T> tmp11;
  TNode<Uint8T> tmp12;
  TNode<Uint8T> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<HeapObject> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<Uint8T> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<Uint8T> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<SmallOrderedHashMap> tmp40;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp1 = CodeStubAssembler(state_).IntPtrDiv(TNode<IntPtrT>{p_capacity}, TNode<IntPtrT>{tmp0});
    tmp2 = kSmallOrderedHashMapMap_0(state_);
    tmp3 = Convert_uint8_intptr_0(state_, TNode<IntPtrT>{tmp1});
    tmp4 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    std::tie(tmp5) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp4}).Flatten();
    tmp6 = TheHole_0(state_);
    tmp7 = TheHole_0(state_);
    std::tie(tmp8, tmp9) = ConstantIterator_HashMapEntry_0(state_, TorqueStructHashMapEntry_0{TNode<Object>{tmp6}, TNode<Object>{tmp7}}).Flatten();
    tmp10 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp11) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp10}).Flatten();
    tmp12 = FromConstexpr_uint8_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kNotFound);
    std::tie(tmp13) = ConstantIterator_uint8_0(state_, TNode<Uint8T>{tmp12}).Flatten();
    tmp14 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp16 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp15}, TNode<IntPtrT>{tmp14}, kUInt8Size);
    tmp17 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp19 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp18});
    tmp20 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp22 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp20}, 8);
    tmp23 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp24 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23}, kUInt8Size);
    tmp25 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp27 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp26});
    tmp28 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp27});
    tmp29 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp28}, kUInt8Size);
    tmp30 = AlignTagged_0(state_, TNode<IntPtrT>{tmp29});
    tmp31 = Allocate_0(state_, TNode<IntPtrT>{tmp30}, TNode<Map>{tmp2});
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp31, tmp32}, tmp2);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp34 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp31, tmp33}, tmp34);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp36 = FromConstexpr_uint8_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp31, tmp35}, tmp36);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp31, tmp37}, tmp3);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp31}, TNode<IntPtrT>{tmp38}, TNode<IntPtrT>{tmp14}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp5}});
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_HashMapEntry_ConstantIterator_HashMapEntry_0(state_, TorqueStructSlice_HashMapEntry_0{TNode<HeapObject>{tmp31}, TNode<IntPtrT>{tmp39}, TNode<IntPtrT>{tmp20}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_HashMapEntry_0{TorqueStructHashMapEntry_0{TNode<Object>{tmp8}, TNode<Object>{tmp9}}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp31}, TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp11}});
    InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(state_, TorqueStructSlice_uint8_0{TNode<HeapObject>{tmp31}, TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp28}, TorqueStructUnsafe_0{}}, TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{tmp13}});
    tmp40 = TORQUE_CAST(TNode<HeapObject>{tmp31});
    ca_.Goto(&block9);
  }

    ca_.Bind(&block9);
  return TNode<SmallOrderedHashMap>{tmp40};
}

TNode<Uint8T> LoadSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

void StoreSmallOrderedHashSetNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

void StoreSmallOrderedHashSetNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedHashSetNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

TNode<Uint8T> LoadSmallOrderedHashSetPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Uint8T> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp8 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp8});
    std::tie(tmp10, tmp11) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp9}).Flatten();
    tmp12 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp10, tmp11});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp12};
}

void StoreSmallOrderedHashSetPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp8 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp8});
    std::tie(tmp10, tmp11) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp9}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp10, tmp11}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Object> LoadSmallOrderedHashSetDataTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint8T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<UintPtrT> tmp8;
  TNode<UintPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp6 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<HeapObject> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<Object> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp12 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp11});
    tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp12});
    std::tie(tmp14, tmp15) = NewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp13}).Flatten();
    tmp16 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp14, tmp15});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Object>{tmp16};
}

void StoreSmallOrderedHashSetDataTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint8T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<UintPtrT> tmp8;
  TNode<UintPtrT> tmp9;
  TNode<BoolT> tmp10;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp6 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<HeapObject> tmp14;
  TNode<IntPtrT> tmp15;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp12 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp11});
    tmp13 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp12});
    std::tie(tmp14, tmp15) = NewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp13}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp14, tmp15}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Uint8T> LoadSmallOrderedHashSetHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<Uint8T> tmp30;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp27}).Flatten();
    tmp30 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp28, tmp29});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp30};
}

void StoreSmallOrderedHashSetHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp27}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp28, tmp29}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Uint8T> LoadSmallOrderedHashSetChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Uint8T> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<BoolT> tmp34;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp23 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22});
    tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp23});
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp27 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp26});
    tmp28 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp27});
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp30 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp29});
    tmp31 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp30});
    tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp31});
    tmp34 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp33});
    ca_.Branch(tmp34, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<HeapObject> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Uint8T> tmp40;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp36 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp35});
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp36});
    std::tie(tmp38, tmp39) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp37}).Flatten();
    tmp40 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp38, tmp39});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp40};
}

void StoreSmallOrderedHashSetChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashSet> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Uint8T> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<BoolT> tmp34;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp23 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22});
    tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp23});
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp27 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp26});
    tmp28 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp27});
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp30 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp29});
    tmp31 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp30});
    tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp31});
    tmp34 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp33});
    ca_.Branch(tmp34, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<HeapObject> tmp38;
  TNode<IntPtrT> tmp39;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp36 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp35});
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp36});
    std::tie(tmp38, tmp39) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp37}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp38, tmp39}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Uint8T> LoadSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

void StoreSmallOrderedHashMapNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

void StoreSmallOrderedHashMapNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedHashMapNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

TNode<Uint8T> LoadSmallOrderedHashMapPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Uint8T> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp8 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp8});
    std::tie(tmp10, tmp11) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp9}).Flatten();
    tmp12 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp10, tmp11});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp12};
}

void StoreSmallOrderedHashMapPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp3});
    tmp6 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp4}, TNode<UintPtrT>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<HeapObject> tmp10;
  TNode<IntPtrT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp8 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp7});
    tmp9 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp8});
    std::tie(tmp10, tmp11) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp9}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp10, tmp11}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Uint8T> LoadSmallOrderedHashMapHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<Uint8T> tmp30;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp27}).Flatten();
    tmp30 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp28, tmp29});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp30};
}

void StoreSmallOrderedHashMapHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp27}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp28, tmp29}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Uint8T> LoadSmallOrderedHashMapChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Uint8T> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<BoolT> tmp34;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp23 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22});
    tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp23});
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp27 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp26});
    tmp28 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp27});
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp30 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp29});
    tmp31 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp30});
    tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp31});
    tmp34 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp33});
    ca_.Branch(tmp34, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<HeapObject> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<Uint8T> tmp40;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp36 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp35});
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp36});
    std::tie(tmp38, tmp39) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp37}).Flatten();
    tmp40 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp38, tmp39});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp40};
}

void StoreSmallOrderedHashMapChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedHashMap> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Uint8T> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Uint8T> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<BoolT> tmp34;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 7);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp3 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp5 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    tmp6 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp10 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp9});
    tmp11 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp10});
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp13 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp12});
    tmp14 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp23 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22});
    tmp24 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp23});
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 6);
    tmp27 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp26});
    tmp28 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp27});
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp30 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp29});
    tmp31 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp30});
    tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp33 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp31});
    tmp34 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp32}, TNode<UintPtrT>{tmp33});
    ca_.Branch(tmp34, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<HeapObject> tmp38;
  TNode<IntPtrT> tmp39;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp35 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp36 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp35});
    tmp37 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp36});
    std::tie(tmp38, tmp39) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp37}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp38, tmp39}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Int32T> LoadSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

void StoreSmallOrderedNameDictionaryHash_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

void StoreSmallOrderedNameDictionaryNumberOfElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 9);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

void StoreSmallOrderedNameDictionaryNumberOfDeletedElements_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 9);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryNumberOfBuckets_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint8T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 11);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint8T>{tmp1};
}

void StoreSmallOrderedNameDictionaryPadding_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 11);
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint8T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Uint8T> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<UintPtrT> tmp15;
  TNode<UintPtrT> tmp16;
  TNode<BoolT> tmp17;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp6 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp13 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp12});
    tmp14 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp13});
    tmp15 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp16 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp14});
    tmp17 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp15}, TNode<UintPtrT>{tmp16});
    ca_.Branch(tmp17, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<HeapObject> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<Uint8T> tmp23;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp19 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp18});
    tmp20 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp19});
    std::tie(tmp21, tmp22) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp20}).Flatten();
    tmp23 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp21, tmp22});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp23};
}

void StoreSmallOrderedNameDictionaryHashTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint8T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Uint8T> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<UintPtrT> tmp15;
  TNode<UintPtrT> tmp16;
  TNode<BoolT> tmp17;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp6 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp13 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp12});
    tmp14 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp13});
    tmp15 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp16 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp14});
    tmp17 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp15}, TNode<UintPtrT>{tmp16});
    ca_.Branch(tmp17, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<HeapObject> tmp21;
  TNode<IntPtrT> tmp22;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp19 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp18});
    tmp20 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp19});
    std::tie(tmp21, tmp22) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp20}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp21, tmp22}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Uint8T> LoadSmallOrderedNameDictionaryChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint8T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Uint8T> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp6 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp13 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp12});
    tmp14 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<Uint8T> tmp30;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp27}).Flatten();
    tmp30 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{tmp28, tmp29});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Uint8T>{tmp30};
}

void StoreSmallOrderedNameDictionaryChainTable_0(compiler::CodeAssemblerState* state_, TNode<SmallOrderedNameDictionary> p_o, TNode<IntPtrT> p_i, TNode<Uint8T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Uint8T> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Uint8T> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Uint8T> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp3 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, SmallOrderedHashTable<int>::kLoadFactor);
    tmp6 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    tmp7 = Convert_intptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp13 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp12});
    tmp14 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp13});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp14}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp16});
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 10);
    tmp20 = CodeStubAssembler(state_).LoadReference<Uint8T>(CodeStubAssembler::Reference{p_o, tmp19});
    tmp21 = Convert_intptr_uint8_0(state_, TNode<Uint8T>{tmp20});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_uint8_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp27}).Flatten();
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp28, tmp29}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TorqueStructConstantIterator_uint8_0 ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructConstantIterator_uint8_0{TNode<Uint8T>{p_value}};
}

void InitializeFieldsFromIterator_uint8_ConstantIterator_uint8_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_uint8_0 p_target, TorqueStructConstantIterator_uint8_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_5}, &block4, std::vector<Node*>{phi_bb5_5});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_5}, &block10, std::vector<Node*>{phi_bb3_5});
  }

  TNode<IntPtrT> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.Goto(&block4, phi_bb9_5);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    std::tie(tmp5, tmp6) = NewReference_uint8_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kUInt8Size);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp7});
    CodeStubAssembler(state_).StoreReference<Uint8T>(CodeStubAssembler::Reference{tmp5, tmp6}, p_originIterator.value);
    ca_.Goto(&block5, tmp8);
  }

  TNode<IntPtrT> phi_bb4_5;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

void InitializeFieldsFromIterator_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_ConstantIterator_TheHole_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0 p_target, TorqueStructConstantIterator_TheHole_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_5}, &block4, std::vector<Node*>{phi_bb5_5});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_5}, &block10, std::vector<Node*>{phi_bb3_5});
  }

  TNode<IntPtrT> phi_bb9_5;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5);
    ca_.Goto(&block4, phi_bb9_5);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5);
    std::tie(tmp5, tmp6) = NewReference_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp7});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, p_originIterator.value);
    ca_.Goto(&block5, tmp8);
  }

  TNode<IntPtrT> phi_bb4_5;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

TorqueStructConstantIterator_HashMapEntry_0 ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructHashMapEntry_0 p_value) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructConstantIterator_HashMapEntry_0{TorqueStructHashMapEntry_0{TNode<Object>{p_value.key}, TNode<Object>{p_value.value}}};
}

void InitializeFieldsFromIterator_HashMapEntry_ConstantIterator_HashMapEntry_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_HashMapEntry_0 p_target, TorqueStructConstantIterator_HashMapEntry_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset);
  }

  TNode<IntPtrT> phi_bb5_6;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_6);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_6}, &block4, std::vector<Node*>{phi_bb5_6});
  }

  TNode<IntPtrT> phi_bb3_6;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_6);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_6}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_6}, &block10, std::vector<Node*>{phi_bb3_6});
  }

  TNode<IntPtrT> phi_bb9_6;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_6);
    ca_.Goto(&block4, phi_bb9_6);
  }

  TNode<IntPtrT> phi_bb10_6;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_6);
    std::tie(tmp5, tmp6) = NewReference_HashMapEntry_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_6}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_6}, TNode<IntPtrT>{tmp7});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, p_originIterator.value.key);
    tmp9 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp9});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp10}, p_originIterator.value.value);
    ca_.Goto(&block5, tmp8);
  }

  TNode<IntPtrT> phi_bb4_6;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_6);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

}  // namespace internal
}  // namespace v8

