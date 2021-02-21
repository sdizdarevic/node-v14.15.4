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

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementRemainingSlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementCapabilitySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementValuesArraySlot_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TNode<Int32T> FromConstexpr_PromiseAllResolveElementContextSlots_constexpr_kPromiseAllResolveElementLength_0(compiler::CodeAssemblerState* state_, PromiseBuiltins::PromiseAllResolveElementContextSlots p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.Int32Constant(CastToUnderlyingTypeIfEnum(p_o));
    tmp1 = (TNode<Int32T>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

TF_BUILTIN(PromiseAllResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0{});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(PromiseAllSettledResolveElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0{});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TF_BUILTIN(PromiseAllSettledRejectElementClosure, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<JSFunction> parameter2 = UncheckedCast<JSFunction>(Parameter(Descriptor::kJSTarget));
USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(state_, TNode<Context>{parameter0}, TNode<Object>{parameter3}, TNode<JSFunction>{parameter2}, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0{});
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{p_context});
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Oddball> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block1, tmp1);
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp3}, tmp2);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{p_function}, &label5);
    ca_.Goto(&block15);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Object> tmp8;
  TNode<JSArray> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<FixedArrayBase> tmp11;
  TNode<FixedArray> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<Number> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<BoolT> tmp16;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp6});
    tmp8 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp9 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp10});
    tmp12 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp11});
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp14 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp9, tmp13});
    tmp15 = Convert_intptr_Number_0(state_, TNode<Number>{tmp14});
    tmp16 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp15});
    ca_.Branch(tmp16, &block21, std::vector<Node*>{}, &block22, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Smi> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp19});
    tmp21 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp20});
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block28, std::vector<Node*>{}, &block29, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp27}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp28, tmp29}, p_value);
    ca_.Goto(&block23);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<BoolT> tmp33;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp31 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp30});
    tmp32 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp12});
    tmp33 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp32});
    ca_.Branch(tmp33, &block31, std::vector<Node*>{}, &block32, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp34;
  TNode<Smi> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<Smi> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<UintPtrT> tmp41;
  TNode<UintPtrT> tmp42;
  TNode<BoolT> tmp43;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp35 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp31});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp34}, tmp35);
    tmp36 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp39 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp38});
    tmp40 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp39});
    tmp41 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp42 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp40});
    tmp43 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp41}, TNode<UintPtrT>{tmp42});
    ca_.Branch(tmp43, &block38, std::vector<Node*>{}, &block39, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<IntPtrT> tmp46;
  TNode<HeapObject> tmp47;
  TNode<IntPtrT> tmp48;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    tmp44 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp45 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp44});
    tmp46 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp36}, TNode<IntPtrT>{tmp45});
    std::tie(tmp47, tmp48) = NewReference_Object_0(state_, TNode<HeapObject>{tmp12}, TNode<IntPtrT>{tmp46}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp47, tmp48}, p_value);
    ca_.Goto(&block33);
  }

  if (block39.is_used()) {
    ca_.Bind(&block39);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<FixedArray> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<Smi> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<UintPtrT> tmp59;
  TNode<UintPtrT> tmp60;
  TNode<BoolT> tmp61;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp49 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp31});
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    tmp51 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp49}, TNode<IntPtrT>{tmp50});
    tmp52 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp53 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp12}, TNode<IntPtrT>{tmp52}, TNode<IntPtrT>{tmp32}, TNode<IntPtrT>{tmp51});
    tmp54 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp57 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp53, tmp56});
    tmp58 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp57});
    tmp59 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    tmp60 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp58});
    tmp61 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp59}, TNode<UintPtrT>{tmp60});
    ca_.Branch(tmp61, &block53, std::vector<Node*>{}, &block54, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<HeapObject> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<Smi> tmp69;
  if (block53.is_used()) {
    ca_.Bind(&block53);
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp63 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp7}, TNode<IntPtrT>{tmp62});
    tmp64 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp54}, TNode<IntPtrT>{tmp63});
    std::tie(tmp65, tmp66) = NewReference_Object_0(state_, TNode<HeapObject>{tmp53}, TNode<IntPtrT>{tmp64}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp65, tmp66}, p_value);
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp9, tmp67}, tmp53);
    tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp69 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp31});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp9, tmp68}, tmp69);
    ca_.Goto(&block33);
  }

  if (block54.is_used()) {
    ca_.Bind(&block54);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.Goto(&block23);
  }

  TNode<Object> tmp70;
  TNode<Smi> tmp71;
  TNode<Smi> tmp72;
  TNode<Smi> tmp73;
  TNode<Smi> tmp74;
  TNode<BoolT> tmp75;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp70 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp71 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp70});
    tmp72 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp73 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp71}, TNode<Smi>{tmp72});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp73});
    tmp74 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp75 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp73}, TNode<Smi>{tmp74});
    ca_.Branch(tmp75, &block56, std::vector<Node*>{}, &block57, std::vector<Node*>{});
  }

  TNode<Object> tmp76;
  TNode<PromiseCapability> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<Object> tmp79;
  TNode<Object> tmp80;
  TNode<Oddball> tmp81;
  TNode<Object> tmp82;
  if (block56.is_used()) {
    ca_.Bind(&block56);
    tmp76 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    tmp77 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp76});
    tmp78 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp79 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp77, tmp78});
    tmp80 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp79});
    tmp81 = Undefined_0(state_);
    tmp82 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp80}, TNode<Object>{tmp81}, TNode<Object>{tmp9});
    ca_.Goto(&block57);
  }

  TNode<Oddball> tmp83;
  if (block57.is_used()) {
    ca_.Bind(&block57);
    tmp83 = Undefined_0(state_);
    ca_.Goto(&block1, tmp83);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block58, phi_bb1_3);
  }

  TNode<Object> phi_bb58_3;
    ca_.Bind(&block58, &phi_bb58_3);
  return TNode<Object>{phi_bb58_3};
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsFulfilledFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsFulfilledFunctor_0 p_wrapResultFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{p_context});
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Oddball> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block1, tmp1);
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<JSFunction> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<HeapObject> tmp8;
  TNode<Map> tmp9;
  TNode<JSObject> tmp10;
  TNode<String> tmp11;
  TNode<String> tmp12;
  TNode<Object> tmp13;
  TNode<String> tmp14;
  TNode<Object> tmp15;
  TNode<IntPtrT> tmp16;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp3}, tmp2);
    tmp4 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    tmp5 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp4});
    tmp6 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp8 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp6, tmp7});
    tmp9 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp9});
    tmp11 = CodeStubAssembler(state_).StringConstant("status");
    tmp12 = CodeStubAssembler(state_).StringConstant("fulfilled");
    tmp13 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp10, tmp11, tmp12);
    tmp14 = CodeStubAssembler(state_).StringConstant("value");
    tmp15 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp10, tmp14, p_value);
    compiler::CodeAssemblerLabel label17(&ca_);
    tmp16 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{p_function}, &label17);
    ca_.Goto(&block15);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Object> tmp20;
  TNode<JSArray> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<FixedArrayBase> tmp23;
  TNode<FixedArray> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Number> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<BoolT> tmp28;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp19 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp18});
    tmp20 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp21 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp23 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp21, tmp22});
    tmp24 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp23});
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp26 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp21, tmp25});
    tmp27 = Convert_intptr_Number_0(state_, TNode<Number>{tmp26});
    tmp28 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp27});
    ca_.Branch(tmp28, &block21, std::vector<Node*>{}, &block22, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Smi> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<UintPtrT> tmp34;
  TNode<UintPtrT> tmp35;
  TNode<BoolT> tmp36;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp32 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp24, tmp31});
    tmp33 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp32});
    tmp34 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp35 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp33});
    tmp36 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp34}, TNode<UintPtrT>{tmp35});
    ca_.Branch(tmp36, &block28, std::vector<Node*>{}, &block29, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<HeapObject> tmp40;
  TNode<IntPtrT> tmp41;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp38 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp37});
    tmp39 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp38});
    std::tie(tmp40, tmp41) = NewReference_Object_0(state_, TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp39}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp40, tmp41}, tmp10);
    ca_.Goto(&block23);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<BoolT> tmp45;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp43 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp42});
    tmp44 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp45 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp44});
    ca_.Branch(tmp45, &block31, std::vector<Node*>{}, &block32, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp46;
  TNode<Smi> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<Smi> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<UintPtrT> tmp54;
  TNode<BoolT> tmp55;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp47 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp43});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp21, tmp46}, tmp47);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp51 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp24, tmp50});
    tmp52 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp51});
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp54 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp52});
    tmp55 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp53}, TNode<UintPtrT>{tmp54});
    ca_.Branch(tmp55, &block38, std::vector<Node*>{}, &block39, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<HeapObject> tmp59;
  TNode<IntPtrT> tmp60;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp57 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp56});
    tmp58 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp48}, TNode<IntPtrT>{tmp57});
    std::tie(tmp59, tmp60) = NewReference_Object_0(state_, TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp58}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp59, tmp60}, tmp10);
    ca_.Goto(&block33);
  }

  if (block39.is_used()) {
    ca_.Bind(&block39);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<FixedArray> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<Smi> tmp69;
  TNode<IntPtrT> tmp70;
  TNode<UintPtrT> tmp71;
  TNode<UintPtrT> tmp72;
  TNode<BoolT> tmp73;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp61 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp43});
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    tmp63 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp61}, TNode<IntPtrT>{tmp62});
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp65 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp24}, TNode<IntPtrT>{tmp64}, TNode<IntPtrT>{tmp44}, TNode<IntPtrT>{tmp63});
    tmp66 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp69 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp65, tmp68});
    tmp70 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp69});
    tmp71 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp72 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp70});
    tmp73 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp71}, TNode<UintPtrT>{tmp72});
    ca_.Branch(tmp73, &block53, std::vector<Node*>{}, &block54, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp74;
  TNode<IntPtrT> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<HeapObject> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<IntPtrT> tmp80;
  TNode<Smi> tmp81;
  if (block53.is_used()) {
    ca_.Bind(&block53);
    tmp74 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp75 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp74});
    tmp76 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp66}, TNode<IntPtrT>{tmp75});
    std::tie(tmp77, tmp78) = NewReference_Object_0(state_, TNode<HeapObject>{tmp65}, TNode<IntPtrT>{tmp76}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp77, tmp78}, tmp10);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp21, tmp79}, tmp65);
    tmp80 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp81 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp43});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp21, tmp80}, tmp81);
    ca_.Goto(&block33);
  }

  if (block54.is_used()) {
    ca_.Bind(&block54);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.Goto(&block23);
  }

  TNode<Object> tmp82;
  TNode<Smi> tmp83;
  TNode<Smi> tmp84;
  TNode<Smi> tmp85;
  TNode<Smi> tmp86;
  TNode<BoolT> tmp87;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp82 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp83 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp82});
    tmp84 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp85 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp83}, TNode<Smi>{tmp84});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp85});
    tmp86 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp87 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp85}, TNode<Smi>{tmp86});
    ca_.Branch(tmp87, &block56, std::vector<Node*>{}, &block57, std::vector<Node*>{});
  }

  TNode<Object> tmp88;
  TNode<PromiseCapability> tmp89;
  TNode<IntPtrT> tmp90;
  TNode<Object> tmp91;
  TNode<Object> tmp92;
  TNode<Oddball> tmp93;
  TNode<Object> tmp94;
  if (block56.is_used()) {
    ca_.Bind(&block56);
    tmp88 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    tmp89 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp88});
    tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp91 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp89, tmp90});
    tmp92 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp91});
    tmp93 = Undefined_0(state_);
    tmp94 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp92}, TNode<Object>{tmp93}, TNode<Object>{tmp21});
    ca_.Goto(&block57);
  }

  TNode<Oddball> tmp95;
  if (block57.is_used()) {
    ca_.Bind(&block57);
    tmp95 = Undefined_0(state_);
    ca_.Goto(&block1, tmp95);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block58, phi_bb1_3);
  }

  TNode<Object> phi_bb58_3;
    ca_.Bind(&block58, &phi_bb58_3);
  return TNode<Object>{phi_bb58_3};
}

TNode<Object> PromiseAllResolveElementClosure_PromiseAllSettledWrapResultAsRejectedFunctor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_value, TNode<JSFunction> p_function, TorqueStructPromiseAllSettledWrapResultAsRejectedFunctor_0 p_wrapResultFunctor) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block56(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block57(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block58(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).IsNativeContext(TNode<HeapObject>{p_context});
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Oddball> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block1, tmp1);
  }

  TNode<NativeContext> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Object> tmp5;
  TNode<JSFunction> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<HeapObject> tmp8;
  TNode<Map> tmp9;
  TNode<JSObject> tmp10;
  TNode<String> tmp11;
  TNode<String> tmp12;
  TNode<Object> tmp13;
  TNode<String> tmp14;
  TNode<Object> tmp15;
  TNode<IntPtrT> tmp16;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{p_context});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Context>(CodeStubAssembler::Reference{p_function, tmp3}, tmp2);
    tmp4 = FromConstexpr_NativeContextSlot_constexpr_OBJECT_FUNCTION_INDEX_0(state_, Context::Field::OBJECT_FUNCTION_INDEX);
    tmp5 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp2}, TNode<IntPtrT>{tmp4});
    tmp6 = UnsafeCast_JSFunction_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp5});
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 28);
    tmp8 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp6, tmp7});
    tmp9 = UnsafeCast_Map_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp8});
    tmp10 = CodeStubAssembler(state_).AllocateJSObjectFromMap(TNode<Map>{tmp9});
    tmp11 = CodeStubAssembler(state_).StringConstant("status");
    tmp12 = CodeStubAssembler(state_).StringConstant("rejected");
    tmp13 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp10, tmp11, tmp12);
    tmp14 = CodeStubAssembler(state_).StringConstant("reason");
    tmp15 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, p_context, tmp10, tmp14, p_value);
    compiler::CodeAssemblerLabel label17(&ca_);
    tmp16 = CodeStubAssembler(state_).LoadJSReceiverIdentityHash(TNode<Object>{p_function}, &label17);
    ca_.Goto(&block15);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Object> tmp20;
  TNode<JSArray> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<FixedArrayBase> tmp23;
  TNode<FixedArray> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<Number> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<BoolT> tmp28;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp19 = CodeStubAssembler(state_).IntPtrSub(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp18});
    tmp20 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementValuesArraySlot);
    tmp21 = UnsafeCast_JSArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp20});
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp23 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp21, tmp22});
    tmp24 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp23});
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp26 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp21, tmp25});
    tmp27 = Convert_intptr_Number_0(state_, TNode<Number>{tmp26});
    tmp28 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp27});
    ca_.Branch(tmp28, &block21, std::vector<Node*>{}, &block22, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Smi> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<UintPtrT> tmp34;
  TNode<UintPtrT> tmp35;
  TNode<BoolT> tmp36;
  if (block21.is_used()) {
    ca_.Bind(&block21);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp32 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp24, tmp31});
    tmp33 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp32});
    tmp34 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp35 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp33});
    tmp36 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp34}, TNode<UintPtrT>{tmp35});
    ca_.Branch(tmp36, &block28, std::vector<Node*>{}, &block29, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<IntPtrT> tmp39;
  TNode<HeapObject> tmp40;
  TNode<IntPtrT> tmp41;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp38 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp37});
    tmp39 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp38});
    std::tie(tmp40, tmp41) = NewReference_Object_0(state_, TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp39}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp40, tmp41}, tmp10);
    ca_.Goto(&block23);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<BoolT> tmp45;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp43 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp42});
    tmp44 = CodeStubAssembler(state_).LoadAndUntagFixedArrayBaseLength(TNode<FixedArrayBase>{tmp24});
    tmp45 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp44});
    ca_.Branch(tmp45, &block31, std::vector<Node*>{}, &block32, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp46;
  TNode<Smi> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<IntPtrT> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<Smi> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<UintPtrT> tmp54;
  TNode<BoolT> tmp55;
  if (block31.is_used()) {
    ca_.Bind(&block31);
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp47 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp43});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp21, tmp46}, tmp47);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp51 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp24, tmp50});
    tmp52 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp51});
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp54 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp52});
    tmp55 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp53}, TNode<UintPtrT>{tmp54});
    ca_.Branch(tmp55, &block38, std::vector<Node*>{}, &block39, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<HeapObject> tmp59;
  TNode<IntPtrT> tmp60;
  if (block38.is_used()) {
    ca_.Bind(&block38);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp57 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp56});
    tmp58 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp48}, TNode<IntPtrT>{tmp57});
    std::tie(tmp59, tmp60) = NewReference_Object_0(state_, TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp58}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp59, tmp60}, tmp10);
    ca_.Goto(&block33);
  }

  if (block39.is_used()) {
    ca_.Bind(&block39);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<FixedArray> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<Smi> tmp69;
  TNode<IntPtrT> tmp70;
  TNode<UintPtrT> tmp71;
  TNode<UintPtrT> tmp72;
  TNode<BoolT> tmp73;
  if (block32.is_used()) {
    ca_.Bind(&block32);
    tmp61 = CodeStubAssembler(state_).CalculateNewElementsCapacity(TNode<IntPtrT>{tmp43});
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, (CodeStubAssembler(state_).ConstexprInt31Add(PropertyArray::HashField::kMax, 1)));
    tmp63 = CodeStubAssembler(state_).IntPtrMin(TNode<IntPtrT>{tmp61}, TNode<IntPtrT>{tmp62});
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp65 = ExtractFixedArray_0(state_, TNode<FixedArray>{tmp24}, TNode<IntPtrT>{tmp64}, TNode<IntPtrT>{tmp44}, TNode<IntPtrT>{tmp63});
    tmp66 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp67 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp68 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp69 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp65, tmp68});
    tmp70 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp69});
    tmp71 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    tmp72 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp70});
    tmp73 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp71}, TNode<UintPtrT>{tmp72});
    ca_.Branch(tmp73, &block53, std::vector<Node*>{}, &block54, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp74;
  TNode<IntPtrT> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<HeapObject> tmp77;
  TNode<IntPtrT> tmp78;
  TNode<IntPtrT> tmp79;
  TNode<IntPtrT> tmp80;
  TNode<Smi> tmp81;
  if (block53.is_used()) {
    ca_.Bind(&block53);
    tmp74 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp75 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp74});
    tmp76 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp66}, TNode<IntPtrT>{tmp75});
    std::tie(tmp77, tmp78) = NewReference_Object_0(state_, TNode<HeapObject>{tmp65}, TNode<IntPtrT>{tmp76}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp77, tmp78}, tmp10);
    tmp79 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp21, tmp79}, tmp65);
    tmp80 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp81 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp43});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp21, tmp80}, tmp81);
    ca_.Goto(&block33);
  }

  if (block54.is_used()) {
    ca_.Bind(&block54);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    ca_.Goto(&block23);
  }

  TNode<Object> tmp82;
  TNode<Smi> tmp83;
  TNode<Smi> tmp84;
  TNode<Smi> tmp85;
  TNode<Smi> tmp86;
  TNode<BoolT> tmp87;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp82 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot);
    tmp83 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp82});
    tmp84 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp85 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp83}, TNode<Smi>{tmp84});
    CodeStubAssembler(state_).StoreContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementRemainingSlot, TNode<Object>{tmp85});
    tmp86 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp87 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp85}, TNode<Smi>{tmp86});
    ca_.Branch(tmp87, &block56, std::vector<Node*>{}, &block57, std::vector<Node*>{});
  }

  TNode<Object> tmp88;
  TNode<PromiseCapability> tmp89;
  TNode<IntPtrT> tmp90;
  TNode<Object> tmp91;
  TNode<Object> tmp92;
  TNode<Oddball> tmp93;
  TNode<Object> tmp94;
  if (block56.is_used()) {
    ca_.Bind(&block56);
    tmp88 = CodeStubAssembler(state_).LoadContextElement(TNode<Context>{p_context}, PromiseBuiltins::PromiseAllResolveElementContextSlots::kPromiseAllResolveElementCapabilitySlot);
    tmp89 = UnsafeCast_PromiseCapability_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp88});
    tmp90 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp91 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp89, tmp90});
    tmp92 = UnsafeCast_JSAny_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp91});
    tmp93 = Undefined_0(state_);
    tmp94 = CodeStubAssembler(state_).Call(TNode<Context>{p_context}, TNode<Object>{tmp92}, TNode<Object>{tmp93}, TNode<Object>{tmp21});
    ca_.Goto(&block57);
  }

  TNode<Oddball> tmp95;
  if (block57.is_used()) {
    ca_.Bind(&block57);
    tmp95 = Undefined_0(state_);
    ca_.Goto(&block1, tmp95);
  }

  TNode<Object> phi_bb1_3;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_3);
    ca_.Goto(&block58, phi_bb1_3);
  }

  TNode<Object> phi_bb58_3;
    ca_.Bind(&block58, &phi_bb58_3);
  return TNode<Object>{phi_bb58_3};
}

}  // namespace internal
}  // namespace v8

