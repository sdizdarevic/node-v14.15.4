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

TNode<SharedFunctionInfo> LoadFeedbackVectorSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<SharedFunctionInfo> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<SharedFunctionInfo>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<SharedFunctionInfo>{tmp1};
}

void StoreFeedbackVectorSharedFunctionInfo_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<SharedFunctionInfo> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<SharedFunctionInfo>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<MaybeObject> LoadFeedbackVectorOptimizedCodeWeakOrSmi_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<MaybeObject> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<MaybeObject>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<MaybeObject>{tmp1};
}

void StoreFeedbackVectorOptimizedCodeWeakOrSmi_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<MaybeObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<MaybeObject>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<FixedArray> LoadFeedbackVectorClosureFeedbackCellArray_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<FixedArray> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<FixedArray>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<FixedArray>{tmp1};
}

void StoreFeedbackVectorClosureFeedbackCellArray_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<FixedArray> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<FixedArray>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Int32T> LoadFeedbackVectorLength_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> LoadFeedbackVectorInvocationCount_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

void StoreFeedbackVectorInvocationCount_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Int32T> LoadFeedbackVectorProfilerTicks_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

void StoreFeedbackVectorProfilerTicks_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Uint32T> LoadFeedbackVectorPadding_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Uint32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp1 = CodeStubAssembler(state_).LoadReference<Uint32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Uint32T>{tmp1};
}

void StoreFeedbackVectorPadding_0(compiler::CodeAssemblerState* state_, TNode<FeedbackVector> p_o, TNode<Uint32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    CodeStubAssembler(state_).StoreReference<Uint32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

}  // namespace internal
}  // namespace v8

