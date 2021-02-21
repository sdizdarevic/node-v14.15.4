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

TNode<BoolT> ElementsKindTestHelper1_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT8_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT16_ELEMENTS))))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  TNode<BoolT> tmp0;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp0);
  }

  TNode<BoolT> tmp1;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp1);
  }

  TNode<BoolT> phi_bb1_0;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_0);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<BoolT>{phi_bb1_0};
}

bool ElementsKindTestHelper2_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return ((CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT8_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, ElementsKind::UINT16_ELEMENTS)));
}

void LabelTestHelper1_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(label_Label1);
  }
}

void LabelTestHelper2_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label2, compiler::TypedCodeAssemblerVariable<Smi>* label_Label2_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    *label_Label2_parameter_0 = tmp0;
    ca_.Goto(label_Label2);
  }
}

void LabelTestHelper3_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label3, compiler::TypedCodeAssemblerVariable<Oddball>* label_Label3_parameter_0, compiler::TypedCodeAssemblerVariable<Smi>* label_Label3_parameter_1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Null_0(state_);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    *label_Label3_parameter_1 = tmp1;
    *label_Label3_parameter_0 = tmp0;
    ca_.Goto(label_Label3);
  }
}

void TestConstexpr1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).IsFastElementsKind(ElementsKind::PACKED_SMI_ELEMENTS)));
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( IsFastElementsKind(ElementsKind::PACKED_SMI_ELEMENTS))' failed", "../../deps/v8/test/torque/test-torque.tq", 44);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

void TestConstexprIf_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ElementsKindTestHelper1_0(state_, ElementsKind::UINT8_ELEMENTS);
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ElementsKindTestHelper1(ElementsKind::UINT8_ELEMENTS)' failed", "../../deps/v8/test/torque/test-torque.tq", 50);
  }

  TNode<BoolT> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = ElementsKindTestHelper1_0(state_, ElementsKind::UINT16_ELEMENTS);
    ca_.Branch(tmp1, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ElementsKindTestHelper1(ElementsKind::UINT16_ELEMENTS)' failed", "../../deps/v8/test/torque/test-torque.tq", 51);
  }

  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = ElementsKindTestHelper1_0(state_, ElementsKind::UINT32_ELEMENTS);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert '!ElementsKindTestHelper1(ElementsKind::UINT32_ELEMENTS)' failed", "../../deps/v8/test/torque/test-torque.tq", 52);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestConstexprReturn_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, ElementsKind::UINT8_ELEMENTS)));
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( ElementsKindTestHelper2(ElementsKind::UINT8_ELEMENTS))' failed", "../../deps/v8/test/torque/test-torque.tq", 57);
  }

  TNode<BoolT> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, ElementsKind::UINT16_ELEMENTS)));
    ca_.Branch(tmp1, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( ElementsKindTestHelper2(ElementsKind::UINT16_ELEMENTS))' failed", "../../deps/v8/test/torque/test-torque.tq", 59);
  }

  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, ElementsKind::UINT32_ELEMENTS)));
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert '!FromConstexpr<bool>( ElementsKindTestHelper2(ElementsKind::UINT32_ELEMENTS))' failed", "../../deps/v8/test/torque/test-torque.tq", 61);
  }

  TNode<BoolT> tmp4;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprBoolNot((ElementsKindTestHelper2_0(state_, ElementsKind::UINT32_ELEMENTS)))));
    ca_.Branch(tmp4, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>( !ElementsKindTestHelper2(ElementsKind::UINT32_ELEMENTS))' failed", "../../deps/v8/test/torque/test-torque.tq", 63);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

TNode<Oddball> TestGotoLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper1_0(state_, &label0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4);
    }
  }

  TNode<Oddball> tmp1;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp1 = True_0(state_);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<Oddball>{tmp1};
}

TNode<Oddball> TestGotoLabelWithOneParameter_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Smi> tmp1(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper2_0(state_, &label0, &tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4);
    }
  }

  TNode<Smi> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    tmp3 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp1.value()}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).FailAssert("Torque assert 'smi == 42' failed", "../../deps/v8/test/torque/test-torque.tq", 81);
  }

  TNode<Oddball> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp4 = True_0(state_);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
  return TNode<Oddball>{tmp4};
}

TNode<Oddball> TestGotoLabelWithTwoParameters_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    compiler::TypedCodeAssemblerVariable<Oddball> tmp1(&ca_);
    compiler::TypedCodeAssemblerVariable<Smi> tmp2(&ca_);
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper3_0(state_, &label0, &tmp1, &tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4);
    }
  }

  TNode<Oddball> tmp3;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = Null_0(state_);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp1.value()}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o == Null' failed", "../../deps/v8/test/torque/test-torque.tq", 91);
  }

  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp2.value()}, TNode<Smi>{tmp5});
    ca_.Branch(tmp6, &block7, std::vector<Node*>{}, &block8, std::vector<Node*>{});
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'smi == 7' failed", "../../deps/v8/test/torque/test-torque.tq", 92);
  }

  TNode<Oddball> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp7 = True_0(state_);
    ca_.Goto(&block9);
  }

    ca_.Bind(&block9);
  return TNode<Oddball>{tmp7};
}

TF_BUILTIN(GenericBuiltinTest_JSAny_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Object> parameter0 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).Return(parameter0);
  }
}

void TestBuiltinSpecialization_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Object> tmp1;
  TNode<Oddball> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_Smi_0, TNode<Object>(), tmp0);
    tmp2 = Null_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<Smi>(0) == Null' failed", "../../deps/v8/test/torque/test-torque.tq", 107);
  }

  TNode<Smi> tmp4;
  TNode<Object> tmp5;
  TNode<Oddball> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp5 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_Smi_0, TNode<Object>(), tmp4);
    tmp6 = Null_0(state_);
    tmp7 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<Smi>(1) == Null' failed", "../../deps/v8/test/torque/test-torque.tq", 108);
  }

  TNode<Oddball> tmp8;
  TNode<Object> tmp9;
  TNode<Oddball> tmp10;
  TNode<BoolT> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = Undefined_0(state_);
    tmp9 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_JSAny_0, TNode<Object>(), tmp8);
    tmp10 = Undefined_0(state_);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp9}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp11, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<JSAny>(Undefined) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 109);
  }

  TNode<Oddball> tmp12;
  TNode<Object> tmp13;
  TNode<Oddball> tmp14;
  TNode<BoolT> tmp15;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp12 = Undefined_0(state_);
    tmp13 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_JSAny_0, TNode<Object>(), tmp12);
    tmp14 = Undefined_0(state_);
    tmp15 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp13}, TNode<HeapObject>{tmp14});
    ca_.Branch(tmp15, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<JSAny>(Undefined) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 110);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

void LabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag, compiler::CodeAssemblerLabel* label_Label4, compiler::CodeAssemblerLabel* label_Label5) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((p_flag)) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(label_Label4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_Label5);
  }
}

TNode<BoolT> CallLabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    LabelTestHelper4_0(state_, p_flag, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7);
    }
  }

  TNode<BoolT> tmp2;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_0;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_0);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<BoolT>{phi_bb1_0};
}

TNode<Oddball> TestPartiallyUnusedLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CallLabelTestHelper4_0(state_, true);
    tmp1 = CallLabelTestHelper4_0(state_, false);
    ca_.Branch(tmp0, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    ca_.Goto(&block6, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp3);
  }

  TNode<BoolT> phi_bb6_3;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_3);
    ca_.Branch(phi_bb6_3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Oddball> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = True_0(state_);
    ca_.Goto(&block1, tmp4);
  }

  TNode<Oddball> tmp5;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp5 = False_0(state_);
    ca_.Goto(&block1, tmp5);
  }

  TNode<Oddball> phi_bb1_0;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_0);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<Oddball>{phi_bb1_0};
}

TNode<Object> GenericMacroTest_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{p_param2};
}

TNode<Object> GenericMacroTestWithLabels_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2, compiler::CodeAssemblerLabel* label_Y) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{p_param2}, &label1);
    ca_.Goto(&block3);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_Y);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<Object>{tmp0};
}

void TestMacroSpecialization_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  TNode<Object> tmp2;
  TNode<Oddball> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp2 = GenericMacroTest_Smi_0(state_, TNode<Smi>{tmp1});
    tmp3 = Undefined_0(state_);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Smi>(0) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 166);
  }

  TNode<Smi> tmp5;
  TNode<Object> tmp6;
  TNode<Oddball> tmp7;
  TNode<BoolT> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp6 = GenericMacroTest_Smi_0(state_, TNode<Smi>{tmp5});
    tmp7 = Undefined_0(state_);
    tmp8 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp6}, TNode<HeapObject>{tmp7});
    ca_.Branch(tmp8, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Smi>(1) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 167);
  }

  TNode<Oddball> tmp9;
  TNode<Object> tmp10;
  TNode<Oddball> tmp11;
  TNode<BoolT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp9 = Null_0(state_);
    tmp10 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp9});
    tmp11 = Null_0(state_);
    tmp12 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp10}, TNode<HeapObject>{tmp11});
    ca_.Branch(tmp12, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(Null) == Null' failed", "../../deps/v8/test/torque/test-torque.tq", 168);
  }

  TNode<Oddball> tmp13;
  TNode<Object> tmp14;
  TNode<Oddball> tmp15;
  TNode<BoolT> tmp16;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp13 = False_0(state_);
    tmp14 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp13});
    tmp15 = False_0(state_);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block10, std::vector<Node*>{}, &block11, std::vector<Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(False) == False' failed", "../../deps/v8/test/torque/test-torque.tq", 169);
  }

  TNode<Oddball> tmp17;
  TNode<Object> tmp18;
  TNode<Oddball> tmp19;
  TNode<BoolT> tmp20;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp17 = True_0(state_);
    tmp18 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp17});
    tmp19 = True_0(state_);
    tmp20 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp18}, TNode<HeapObject>{tmp19});
    ca_.Branch(tmp20, &block12, std::vector<Node*>{}, &block13, std::vector<Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(True) == True' failed", "../../deps/v8/test/torque/test-torque.tq", 170);
  }

  TNode<Smi> tmp21;
  TNode<Object> tmp22;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerLabel label23(&ca_);
    tmp22 = GenericMacroTestWithLabels_Smi_0(state_, TNode<Smi>{tmp21}, &label23);
    ca_.Goto(&block16);
    if (label23.is_used()) {
      ca_.Bind(&label23);
      ca_.Goto(&block17);
    }
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    ca_.Goto(&block3);
  }

  TNode<Oddball> tmp24;
  TNode<BoolT> tmp25;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp24 = Undefined_0(state_);
    tmp25 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp22}, TNode<HeapObject>{tmp24});
    ca_.Branch(tmp25, &block14, std::vector<Node*>{}, &block15, std::vector<Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).FailAssert("Torque assert '(GenericMacroTestWithLabels<Smi>(0) otherwise Fail) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 171);
  }

  TNode<Smi> tmp26;
  TNode<Object> tmp27;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp26 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerLabel label28(&ca_);
    tmp27 = GenericMacroTestWithLabels_Smi_0(state_, TNode<Smi>{tmp26}, &label28);
    ca_.Goto(&block20);
    if (label28.is_used()) {
      ca_.Bind(&label28);
      ca_.Goto(&block21);
    }
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(&block3);
  }

  TNode<Oddball> tmp29;
  TNode<BoolT> tmp30;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp29 = Undefined_0(state_);
    tmp30 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp27}, TNode<HeapObject>{tmp29});
    ca_.Branch(tmp30, &block18, std::vector<Node*>{}, &block19, std::vector<Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).FailAssert("Torque assert '(GenericMacroTestWithLabels<Smi>(0) otherwise Fail) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 172);
  }

  TNode<Oddball> tmp31;
  TNode<Object> tmp32;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp31 = False_0(state_);
    compiler::CodeAssemblerLabel label33(&ca_);
    tmp32 = GenericMacroTestWithLabels_Object_0(state_, TNode<Object>{tmp31}, &label33);
    ca_.Goto(&block24);
    if (label33.is_used()) {
      ca_.Bind(&label33);
      ca_.Goto(&block25);
    }
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    ca_.Goto(&block22);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.Goto(&block22);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    ca_.Goto(&block26);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block26);
}

TF_BUILTIN(TestHelperPlus1, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp1 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{parameter0}, TNode<Smi>{tmp0});
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TF_BUILTIN(TestHelperPlus2, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    tmp1 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{parameter0}, TNode<Smi>{tmp0});
    CodeStubAssembler(state_).Return(tmp1);
  }
}

TNode<Oddball> TestFunctionPointers_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(10)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus1)), TNode<Object>(), tmp0));
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 43);
    tmp3 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr(42) == 43' failed", "../../deps/v8/test/torque/test-torque.tq", 191);
  }

  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
tmp5 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(10)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus2)), TNode<Object>(), tmp4));
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 44);
    tmp7 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp5}, TNode<Smi>{tmp6});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr(42) == 44' failed", "../../deps/v8/test/torque/test-torque.tq", 193);
  }

  TNode<Oddball> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = True_0(state_);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<Oddball>{tmp8};
}

TNode<Oddball> TestVariableRedeclaration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(42, 0)));
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Int32T> tmp1;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = FromConstexpr_int31_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp1);
  }

  TNode<Int32T> tmp2;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp2 = FromConstexpr_int31_constexpr_int31_0(state_, 1);
    ca_.Goto(&block4, tmp2);
  }

  TNode<Int32T> phi_bb4_1;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_1);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(42, 0)));
    ca_.Branch(tmp3, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<Int32T> tmp4;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp4 = FromConstexpr_int31_constexpr_int31_0(state_, 1);
    ca_.Goto(&block8, tmp4);
  }

  TNode<Int32T> tmp5;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp5 = FromConstexpr_int31_constexpr_int31_0(state_, 0);
    ca_.Goto(&block8, tmp5);
  }

  TNode<Int32T> phi_bb8_2;
  TNode<Oddball> tmp6;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_2);
    tmp6 = True_0(state_);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TNode<Oddball>{tmp6};
}

TNode<Smi> TestTernaryOperator_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{p_x}, TNode<Smi>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp3);
  }

  TNode<BoolT> phi_bb4_1;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_1);
    ca_.Branch(phi_bb4_1, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp5 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{p_x}, TNode<Smi>{tmp4});
    ca_.Goto(&block8, tmp5);
  }

  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 100);
    tmp7 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_x}, TNode<Smi>{tmp6});
    ca_.Goto(&block8, tmp7);
  }

  TNode<Smi> phi_bb8_2;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_2);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
  return TNode<Smi>{phi_bb8_2};
}

void TestFunctionPointerToGeneric_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Object> tmp1;
  TNode<Oddball> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
tmp1 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(11)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_Smi_0)), TNode<Object>(), tmp0);
    tmp2 = Null_0(state_);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp1}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr1(0) == Null' failed", "../../deps/v8/test/torque/test-torque.tq", 215);
  }

  TNode<Smi> tmp4;
  TNode<Object> tmp5;
  TNode<Oddball> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
tmp5 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(11)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_Smi_0)), TNode<Object>(), tmp4);
    tmp6 = Null_0(state_);
    tmp7 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr1(1) == Null' failed", "../../deps/v8/test/torque/test-torque.tq", 216);
  }

  TNode<Oddball> tmp8;
  TNode<Object> tmp9;
  TNode<Oddball> tmp10;
  TNode<BoolT> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = Undefined_0(state_);
tmp9 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(12)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_JSAny_0)), TNode<Object>(), tmp8);
    tmp10 = Undefined_0(state_);
    tmp11 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp9}, TNode<HeapObject>{tmp10});
    ca_.Branch(tmp11, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr2(Undefined) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 217);
  }

  TNode<Oddball> tmp12;
  TNode<Object> tmp13;
  TNode<Oddball> tmp14;
  TNode<BoolT> tmp15;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp12 = Undefined_0(state_);
tmp13 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(12)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_JSAny_0)), TNode<Object>(), tmp12);
    tmp14 = Undefined_0(state_);
    tmp15 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp13}, TNode<HeapObject>{tmp14});
    ca_.Branch(tmp15, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr2(Undefined) == Undefined' failed", "../../deps/v8/test/torque/test-torque.tq", 218);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

TNode<BuiltinPtr> TestTypeAlias_0(compiler::CodeAssemblerState* state_, TNode<BuiltinPtr> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<BuiltinPtr>{p_x};
}

TNode<Oddball> TestUnsafeCast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{p_n});
    ca_.Branch(tmp0, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp1 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{p_n});
    tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kTestHelperPlus1, TNode<Object>(), tmp1));
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    tmp4 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestHelperPlus1(m) == 11' failed", "../../deps/v8/test/torque/test-torque.tq", 232);
  }

  TNode<Oddball> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp5 = True_0(state_);
    ca_.Goto(&block1, tmp5);
  }

  TNode<Oddball> tmp6;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp6 = False_0(state_);
    ca_.Goto(&block1, tmp6);
  }

  TNode<Oddball> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<Oddball>{phi_bb1_2};
}

void TestHexLiteral_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_intptr_constexpr_int31_0(state_, 65535);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 65536);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(0xffff) + 1 == 0x10000' failed", "../../deps/v8/test/torque/test-torque.tq", 240);
  }

  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp5 = Convert_intptr_constexpr_int31_0(state_, -65535);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, -65535);
    tmp7 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp6});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(-0xffff) == -65535' failed", "../../deps/v8/test/torque/test-torque.tq", 241);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestLargeIntegerLiterals_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, 1.07374e+09);
    tmp1 = FromConstexpr_int32_constexpr_int32_0(state_, 2.14748e+09);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void TestMultilineAssert_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp2 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp4 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp3});
    ca_.Goto(&block6, tmp4);
  }

  TNode<BoolT> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp5);
  }

  TNode<BoolT> phi_bb6_2;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_2);
    ca_.Branch(phi_bb6_2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'someVeryLongVariableNameThatWillCauseLineBreaks > 0 && someVeryLongVariableNameThatWillCauseLineBreaks < 10' failed", "../../deps/v8/test/torque/test-torque.tq", 253);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
}

void TestNewlineInString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).Print("Hello, World!\n");
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

int31_t kConstexprConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  return 5;
}

TNode<IntPtrT> kIntptrConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<IntPtrT> tmp0;
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
  return TNode<IntPtrT>{tmp0};
}

TNode<Smi> kSmiConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
  TNode<Smi> tmp0;
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
  return TNode<Smi>{tmp0};
}

void TestModuleConstBindings_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).Int32Constant(5);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, kConstexprConst_0(state_));
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp0});
    ca_.Branch(tmp2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kConstexprConst == Int32Constant(5)' failed", "../../deps/v8/test/torque/test-torque.tq", 269);
  }

  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = kIntptrConst_0(state_);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp5 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp5, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kIntptrConst == 4' failed", "../../deps/v8/test/torque/test-torque.tq", 270);
  }

  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<BoolT> tmp8;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp6 = kSmiConst_0(state_);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp8 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kSmiConst == 3' failed", "../../deps/v8/test/torque/test-torque.tq", 271);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestLocalConstBindings_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  TNode<Smi> tmp3;
  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp2}, TNode<Smi>{tmp1});
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp5 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp4});
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.Branch(tmp6, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi + 1' failed", "../../deps/v8/test/torque/test-torque.tq", 280);
  }

  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp3});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi' failed", "../../deps/v8/test/torque/test-torque.tq", 282);
  }

  TNode<Smi> tmp8;
  TNode<BoolT> tmp9;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 4);
    tmp9 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == 4' failed", "../../deps/v8/test/torque/test-torque.tq", 283);
  }

  TNode<Smi> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp0}, TNode<Smi>{tmp10});
    ca_.Branch(tmp11, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'xSmi == 3' failed", "../../deps/v8/test/torque/test-torque.tq", 285);
  }

  TNode<Smi> tmp12;
  TNode<BoolT> tmp13;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp12 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp13 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp12}, TNode<Smi>{tmp0});
    ca_.Branch(tmp13, &block10, std::vector<Node*>{}, &block11, std::vector<Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi' failed", "../../deps/v8/test/torque/test-torque.tq", 286);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
}

TNode<Smi> TestStruct1_0(compiler::CodeAssemblerState* state_, TorqueStructTestStructA_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{p_i.i};
}

TorqueStructTestStructA_0 TestStruct2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<FixedArray> tmp1;
  TNode<Smi> tmp2;
  TNode<Number> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kEmptyFixedArray_0(state_);
    tmp1 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp0});
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 27);
    tmp3 = FromConstexpr_Number_constexpr_int31_0(state_, 31);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructTestStructA_0{TNode<FixedArray>{tmp1}, TNode<Smi>{tmp2}, TNode<Number>{tmp3}};
}

TorqueStructTestStructA_0 TestStruct3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<FixedArray> tmp1;
  TNode<Smi> tmp2;
  TNode<Number> tmp3;
  TNode<FixedArray> tmp4;
  TNode<Smi> tmp5;
  TNode<Number> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  TNode<FixedArray> tmp9;
  TNode<FixedArray> tmp10;
  TNode<Smi> tmp11;
  TNode<Number> tmp12;
  TNode<FixedArray> tmp13;
  TNode<Smi> tmp14;
  TNode<Number> tmp15;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kEmptyFixedArray_0(state_);
    tmp1 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp0});
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 13);
    tmp3 = FromConstexpr_Number_constexpr_int31_0(state_, 5);
    std::tie(tmp4, tmp5, tmp6) = TestStruct2_0(state_, TNode<Context>{p_context}).Flatten();
    tmp7 = TestStruct1_0(state_, TorqueStructTestStructA_0{TNode<FixedArray>{tmp4}, TNode<Smi>{tmp5}, TNode<Number>{tmp6}});
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp9 = kEmptyFixedArray_0(state_);
    tmp10 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp9});
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 27);
    tmp12 = FromConstexpr_Number_constexpr_int31_0(state_, 31);
    std::tie(tmp13, tmp14, tmp15) = TestStruct2_0(state_, TNode<Context>{p_context}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructTestStructA_0{TNode<FixedArray>{tmp1}, TNode<Smi>{tmp7}, TNode<Number>{tmp7}};
}

TorqueStructTestStructC_0 TestStruct4_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<Smi> tmp1;
  TNode<Number> tmp2;
  TNode<FixedArray> tmp3;
  TNode<Smi> tmp4;
  TNode<Number> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = TestStruct2_0(state_, TNode<Context>{p_context}).Flatten();
    std::tie(tmp3, tmp4, tmp5) = TestStruct2_0(state_, TNode<Context>{p_context}).Flatten();
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructTestStructC_0{TorqueStructTestStructA_0{TNode<FixedArray>{tmp0}, TNode<Smi>{tmp1}, TNode<Number>{tmp2}}, TorqueStructTestStructA_0{TNode<FixedArray>{tmp3}, TNode<Smi>{tmp4}, TNode<Number>{tmp5}}};
}

void CallTestStructInLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<Smi> tmp1;
  TNode<Number> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    std::tie(tmp0, tmp1, tmp2) = TestStruct2_0(state_, TNode<Context>{p_context}).Flatten();
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

void TestForLoop_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block66(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block75(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block84(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  TNode<Smi> phi_bb4_0;
  TNode<Smi> phi_bb4_1;
  TNode<Smi> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_0, &phi_bb4_1);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp3 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb4_1}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{phi_bb4_0, phi_bb4_1}, &block3, std::vector<Node*>{phi_bb4_0, phi_bb4_1});
  }

  TNode<Smi> phi_bb2_0;
  TNode<Smi> phi_bb2_1;
  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_0, &phi_bb2_1);
    tmp4 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb2_0}, TNode<Smi>{phi_bb2_1});
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp6 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb2_1}, TNode<Smi>{tmp5});
    ca_.Goto(&block4, tmp4, tmp6);
  }

  TNode<Smi> phi_bb3_0;
  TNode<Smi> phi_bb3_1;
  TNode<Smi> tmp7;
  TNode<BoolT> tmp8;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_0, &phi_bb3_1);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp8 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb3_0}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block6, std::vector<Node*>{phi_bb3_0}, &block7, std::vector<Node*>{phi_bb3_0});
  }

  TNode<Smi> phi_bb7_0;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_0);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "../../deps/v8/test/torque/test-torque.tq", 362);
  }

  TNode<Smi> phi_bb6_0;
  TNode<Smi> tmp9;
  TNode<Smi> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_0);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block10, tmp9, tmp10);
  }

  TNode<Smi> phi_bb10_0;
  TNode<Smi> phi_bb10_1;
  TNode<Smi> tmp11;
  TNode<BoolT> tmp12;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_0, &phi_bb10_1);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp12 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb10_1}, TNode<Smi>{tmp11});
    ca_.Branch(tmp12, &block8, std::vector<Node*>{phi_bb10_0, phi_bb10_1}, &block9, std::vector<Node*>{phi_bb10_0, phi_bb10_1});
  }

  TNode<Smi> phi_bb8_0;
  TNode<Smi> phi_bb8_1;
  TNode<Smi> tmp13;
  TNode<Smi> tmp14;
  TNode<Smi> tmp15;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_0, &phi_bb8_1);
    tmp13 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb8_0}, TNode<Smi>{phi_bb8_1});
    tmp14 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp15 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb8_1}, TNode<Smi>{tmp14});
    ca_.Goto(&block10, tmp13, tmp15);
  }

  TNode<Smi> phi_bb9_0;
  TNode<Smi> phi_bb9_1;
  TNode<Smi> tmp16;
  TNode<BoolT> tmp17;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_0, &phi_bb9_1);
    tmp16 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp17 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb9_0}, TNode<Smi>{tmp16});
    ca_.Branch(tmp17, &block12, std::vector<Node*>{phi_bb9_0, phi_bb9_1}, &block13, std::vector<Node*>{phi_bb9_0, phi_bb9_1});
  }

  TNode<Smi> phi_bb13_0;
  TNode<Smi> phi_bb13_1;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_0, &phi_bb13_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "../../deps/v8/test/torque/test-torque.tq", 367);
  }

  TNode<Smi> phi_bb12_0;
  TNode<Smi> phi_bb12_1;
  TNode<Smi> tmp18;
  TNode<Smi> tmp19;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_0, &phi_bb12_1);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp19 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block16, tmp18, tmp19);
  }

  TNode<Smi> phi_bb16_0;
  TNode<Smi> phi_bb16_1;
  TNode<Smi> tmp20;
  TNode<BoolT> tmp21;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_0, &phi_bb16_1);
    tmp20 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp21 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb16_1}, TNode<Smi>{tmp20});
    ca_.Branch(tmp21, &block14, std::vector<Node*>{phi_bb16_0, phi_bb16_1}, &block15, std::vector<Node*>{phi_bb16_0, phi_bb16_1});
  }

  TNode<Smi> phi_bb14_0;
  TNode<Smi> phi_bb14_1;
  TNode<Smi> tmp22;
  TNode<Smi> tmp23;
  TNode<Smi> tmp24;
  if (block14.is_used()) {
    ca_.Bind(&block14, &phi_bb14_0, &phi_bb14_1);
    tmp22 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp23 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb14_1}, TNode<Smi>{tmp22});
    tmp24 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb14_0}, TNode<Smi>{phi_bb14_1});
    ca_.Goto(&block16, tmp24, tmp23);
  }

  TNode<Smi> phi_bb15_0;
  TNode<Smi> phi_bb15_1;
  TNode<Smi> tmp25;
  TNode<BoolT> tmp26;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_0, &phi_bb15_1);
    tmp25 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp26 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb15_0}, TNode<Smi>{tmp25});
    ca_.Branch(tmp26, &block17, std::vector<Node*>{phi_bb15_0, phi_bb15_1}, &block18, std::vector<Node*>{phi_bb15_0, phi_bb15_1});
  }

  TNode<Smi> phi_bb18_0;
  TNode<Smi> phi_bb18_1;
  if (block18.is_used()) {
    ca_.Bind(&block18, &phi_bb18_0, &phi_bb18_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "../../deps/v8/test/torque/test-torque.tq", 372);
  }

  TNode<Smi> phi_bb17_0;
  TNode<Smi> phi_bb17_1;
  TNode<Smi> tmp27;
  TNode<Smi> tmp28;
  if (block17.is_used()) {
    ca_.Bind(&block17, &phi_bb17_0, &phi_bb17_1);
    tmp27 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp28 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block21, tmp27, phi_bb17_1, tmp28);
  }

  TNode<Smi> phi_bb21_0;
  TNode<Smi> phi_bb21_1;
  TNode<Smi> phi_bb21_2;
  TNode<Smi> tmp29;
  TNode<BoolT> tmp30;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_0, &phi_bb21_1, &phi_bb21_2);
    tmp29 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp30 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb21_2}, TNode<Smi>{tmp29});
    ca_.Branch(tmp30, &block23, std::vector<Node*>{phi_bb21_0, phi_bb21_1, phi_bb21_2}, &block24, std::vector<Node*>{phi_bb21_0, phi_bb21_1, phi_bb21_2});
  }

  TNode<Smi> phi_bb23_0;
  TNode<Smi> phi_bb23_1;
  TNode<Smi> phi_bb23_2;
  TNode<Smi> tmp31;
  TNode<BoolT> tmp32;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_0, &phi_bb23_1, &phi_bb23_2);
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp32 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb23_0}, TNode<Smi>{tmp31});
    ca_.Branch(tmp32, &block25, std::vector<Node*>{phi_bb23_0, phi_bb23_1}, &block26, std::vector<Node*>{phi_bb23_0, phi_bb23_1});
  }

  TNode<Smi> phi_bb24_0;
  TNode<Smi> phi_bb24_1;
  TNode<Smi> phi_bb24_2;
  TNode<Smi> tmp33;
  TNode<Smi> tmp34;
  TNode<Smi> tmp35;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_0, &phi_bb24_1, &phi_bb24_2);
    tmp33 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb24_0}, TNode<Smi>{phi_bb24_2});
    tmp34 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp35 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb24_2}, TNode<Smi>{tmp34});
    ca_.Goto(&block21, tmp33, phi_bb24_1, tmp35);
  }

  TNode<Smi> phi_bb26_0;
  TNode<Smi> phi_bb26_1;
  if (block26.is_used()) {
    ca_.Bind(&block26, &phi_bb26_0, &phi_bb26_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "../../deps/v8/test/torque/test-torque.tq", 380);
  }

  TNode<Smi> phi_bb25_0;
  TNode<Smi> phi_bb25_1;
  TNode<Smi> tmp36;
  TNode<Smi> tmp37;
  if (block25.is_used()) {
    ca_.Bind(&block25, &phi_bb25_0, &phi_bb25_1);
    tmp36 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp37 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block29, tmp36, tmp37);
  }

  TNode<Smi> phi_bb29_0;
  TNode<Smi> phi_bb29_1;
  TNode<Smi> tmp38;
  TNode<BoolT> tmp39;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_0, &phi_bb29_1);
    tmp38 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp39 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb29_1}, TNode<Smi>{tmp38});
    ca_.Branch(tmp39, &block30, std::vector<Node*>{phi_bb29_0, phi_bb29_1}, &block31, std::vector<Node*>{phi_bb29_0, phi_bb29_1});
  }

  TNode<Smi> phi_bb30_0;
  TNode<Smi> phi_bb30_1;
  TNode<Smi> tmp40;
  TNode<BoolT> tmp41;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_0, &phi_bb30_1);
    tmp40 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp41 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb30_0}, TNode<Smi>{tmp40});
    ca_.Branch(tmp41, &block32, std::vector<Node*>{phi_bb30_0, phi_bb30_1}, &block33, std::vector<Node*>{phi_bb30_0, phi_bb30_1});
  }

  TNode<Smi> phi_bb31_0;
  TNode<Smi> phi_bb31_1;
  TNode<Smi> tmp42;
  TNode<Smi> tmp43;
  TNode<Smi> tmp44;
  if (block31.is_used()) {
    ca_.Bind(&block31, &phi_bb31_0, &phi_bb31_1);
    tmp42 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb31_0}, TNode<Smi>{phi_bb31_1});
    tmp43 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp44 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb31_1}, TNode<Smi>{tmp43});
    ca_.Goto(&block29, tmp42, tmp44);
  }

  TNode<Smi> phi_bb33_0;
  TNode<Smi> phi_bb33_1;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_0, &phi_bb33_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "../../deps/v8/test/torque/test-torque.tq", 389);
  }

  TNode<Smi> phi_bb32_0;
  TNode<Smi> phi_bb32_1;
  TNode<Smi> tmp45;
  TNode<Smi> tmp46;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_0, &phi_bb32_1);
    tmp45 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp46 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block36, tmp45, phi_bb32_1, tmp46);
  }

  TNode<Smi> phi_bb36_0;
  TNode<Smi> phi_bb36_1;
  TNode<Smi> phi_bb36_2;
  TNode<Smi> tmp47;
  TNode<BoolT> tmp48;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_0, &phi_bb36_1, &phi_bb36_2);
    tmp47 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp48 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb36_2}, TNode<Smi>{tmp47});
    ca_.Branch(tmp48, &block34, std::vector<Node*>{phi_bb36_0, phi_bb36_1, phi_bb36_2}, &block35, std::vector<Node*>{phi_bb36_0, phi_bb36_1, phi_bb36_2});
  }

  TNode<Smi> phi_bb34_0;
  TNode<Smi> phi_bb34_1;
  TNode<Smi> phi_bb34_2;
  TNode<Smi> tmp49;
  TNode<BoolT> tmp50;
  if (block34.is_used()) {
    ca_.Bind(&block34, &phi_bb34_0, &phi_bb34_1, &phi_bb34_2);
    tmp49 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp50 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb34_2}, TNode<Smi>{tmp49});
    ca_.Branch(tmp50, &block38, std::vector<Node*>{phi_bb34_0, phi_bb34_1, phi_bb34_2}, &block39, std::vector<Node*>{phi_bb34_0, phi_bb34_1, phi_bb34_2});
  }

  TNode<Smi> phi_bb38_0;
  TNode<Smi> phi_bb38_1;
  TNode<Smi> phi_bb38_2;
  if (block38.is_used()) {
    ca_.Bind(&block38, &phi_bb38_0, &phi_bb38_1, &phi_bb38_2);
    ca_.Goto(&block37, phi_bb38_0, phi_bb38_1, phi_bb38_2);
  }

  TNode<Smi> phi_bb39_0;
  TNode<Smi> phi_bb39_1;
  TNode<Smi> phi_bb39_2;
  TNode<Smi> tmp51;
  if (block39.is_used()) {
    ca_.Bind(&block39, &phi_bb39_0, &phi_bb39_1, &phi_bb39_2);
    tmp51 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb39_0}, TNode<Smi>{phi_bb39_2});
    ca_.Goto(&block37, tmp51, phi_bb39_1, phi_bb39_2);
  }

  TNode<Smi> phi_bb37_0;
  TNode<Smi> phi_bb37_1;
  TNode<Smi> phi_bb37_2;
  TNode<Smi> tmp52;
  TNode<Smi> tmp53;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_0, &phi_bb37_1, &phi_bb37_2);
    tmp52 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp53 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb37_2}, TNode<Smi>{tmp52});
    ca_.Goto(&block36, phi_bb37_0, phi_bb37_1, tmp53);
  }

  TNode<Smi> phi_bb35_0;
  TNode<Smi> phi_bb35_1;
  TNode<Smi> phi_bb35_2;
  TNode<Smi> tmp54;
  TNode<BoolT> tmp55;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_0, &phi_bb35_1, &phi_bb35_2);
    tmp54 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp55 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb35_0}, TNode<Smi>{tmp54});
    ca_.Branch(tmp55, &block40, std::vector<Node*>{phi_bb35_0, phi_bb35_1}, &block41, std::vector<Node*>{phi_bb35_0, phi_bb35_1});
  }

  TNode<Smi> phi_bb41_0;
  TNode<Smi> phi_bb41_1;
  if (block41.is_used()) {
    ca_.Bind(&block41, &phi_bb41_0, &phi_bb41_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "../../deps/v8/test/torque/test-torque.tq", 398);
  }

  TNode<Smi> phi_bb40_0;
  TNode<Smi> phi_bb40_1;
  TNode<Smi> tmp56;
  TNode<Smi> tmp57;
  if (block40.is_used()) {
    ca_.Bind(&block40, &phi_bb40_0, &phi_bb40_1);
    tmp56 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp57 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block44, tmp56, tmp57);
  }

  TNode<Smi> phi_bb44_0;
  TNode<Smi> phi_bb44_1;
  TNode<Smi> tmp58;
  TNode<BoolT> tmp59;
  if (block44.is_used()) {
    ca_.Bind(&block44, &phi_bb44_0, &phi_bb44_1);
    tmp58 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp59 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb44_1}, TNode<Smi>{tmp58});
    ca_.Branch(tmp59, &block42, std::vector<Node*>{phi_bb44_0, phi_bb44_1}, &block43, std::vector<Node*>{phi_bb44_0, phi_bb44_1});
  }

  TNode<Smi> phi_bb42_0;
  TNode<Smi> phi_bb42_1;
  TNode<Smi> tmp60;
  TNode<BoolT> tmp61;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_0, &phi_bb42_1);
    tmp60 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp61 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb42_1}, TNode<Smi>{tmp60});
    ca_.Branch(tmp61, &block46, std::vector<Node*>{phi_bb42_0, phi_bb42_1}, &block47, std::vector<Node*>{phi_bb42_0, phi_bb42_1});
  }

  TNode<Smi> phi_bb46_0;
  TNode<Smi> phi_bb46_1;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_0, &phi_bb46_1);
    ca_.Goto(&block45, phi_bb46_0, phi_bb46_1);
  }

  TNode<Smi> phi_bb47_0;
  TNode<Smi> phi_bb47_1;
  TNode<Smi> tmp62;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_0, &phi_bb47_1);
    tmp62 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb47_0}, TNode<Smi>{phi_bb47_1});
    ca_.Goto(&block45, tmp62, phi_bb47_1);
  }

  TNode<Smi> phi_bb45_0;
  TNode<Smi> phi_bb45_1;
  TNode<Smi> tmp63;
  TNode<Smi> tmp64;
  if (block45.is_used()) {
    ca_.Bind(&block45, &phi_bb45_0, &phi_bb45_1);
    tmp63 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp64 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb45_1}, TNode<Smi>{tmp63});
    ca_.Goto(&block44, phi_bb45_0, tmp64);
  }

  TNode<Smi> phi_bb43_0;
  TNode<Smi> phi_bb43_1;
  TNode<Smi> tmp65;
  TNode<BoolT> tmp66;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_0, &phi_bb43_1);
    tmp65 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp66 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb43_0}, TNode<Smi>{tmp65});
    ca_.Branch(tmp66, &block48, std::vector<Node*>{phi_bb43_0, phi_bb43_1}, &block49, std::vector<Node*>{phi_bb43_0, phi_bb43_1});
  }

  TNode<Smi> phi_bb49_0;
  TNode<Smi> phi_bb49_1;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_0, &phi_bb49_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "../../deps/v8/test/torque/test-torque.tq", 406);
  }

  TNode<Smi> phi_bb48_0;
  TNode<Smi> phi_bb48_1;
  TNode<Smi> tmp67;
  TNode<Smi> tmp68;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_0, &phi_bb48_1);
    tmp67 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp68 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block52, tmp67, tmp68);
  }

  TNode<Smi> phi_bb52_0;
  TNode<Smi> phi_bb52_1;
  TNode<Smi> tmp69;
  TNode<BoolT> tmp70;
  if (block52.is_used()) {
    ca_.Bind(&block52, &phi_bb52_0, &phi_bb52_1);
    tmp69 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp70 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb52_1}, TNode<Smi>{tmp69});
    ca_.Branch(tmp70, &block50, std::vector<Node*>{phi_bb52_0, phi_bb52_1}, &block51, std::vector<Node*>{phi_bb52_0, phi_bb52_1});
  }

  TNode<Smi> phi_bb50_0;
  TNode<Smi> phi_bb50_1;
  TNode<Smi> tmp71;
  TNode<BoolT> tmp72;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_0, &phi_bb50_1);
    tmp71 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp72 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb50_1}, TNode<Smi>{tmp71});
    ca_.Branch(tmp72, &block53, std::vector<Node*>{phi_bb50_0, phi_bb50_1}, &block54, std::vector<Node*>{phi_bb50_0, phi_bb50_1});
  }

  TNode<Smi> phi_bb53_0;
  TNode<Smi> phi_bb53_1;
  TNode<Smi> tmp73;
  TNode<Smi> tmp74;
  if (block53.is_used()) {
    ca_.Bind(&block53, &phi_bb53_0, &phi_bb53_1);
    tmp73 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp74 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb53_1}, TNode<Smi>{tmp73});
    ca_.Goto(&block52, phi_bb53_0, tmp74);
  }

  TNode<Smi> phi_bb54_0;
  TNode<Smi> phi_bb54_1;
  TNode<Smi> tmp75;
  TNode<Smi> tmp76;
  TNode<Smi> tmp77;
  if (block54.is_used()) {
    ca_.Bind(&block54, &phi_bb54_0, &phi_bb54_1);
    tmp75 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb54_0}, TNode<Smi>{phi_bb54_1});
    tmp76 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp77 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb54_1}, TNode<Smi>{tmp76});
    ca_.Goto(&block52, tmp75, tmp77);
  }

  TNode<Smi> phi_bb51_0;
  TNode<Smi> phi_bb51_1;
  TNode<Smi> tmp78;
  TNode<BoolT> tmp79;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_0, &phi_bb51_1);
    tmp78 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp79 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb51_0}, TNode<Smi>{tmp78});
    ca_.Branch(tmp79, &block55, std::vector<Node*>{phi_bb51_0, phi_bb51_1}, &block56, std::vector<Node*>{phi_bb51_0, phi_bb51_1});
  }

  TNode<Smi> phi_bb56_0;
  TNode<Smi> phi_bb56_1;
  if (block56.is_used()) {
    ca_.Bind(&block56, &phi_bb56_0, &phi_bb56_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "../../deps/v8/test/torque/test-torque.tq", 418);
  }

  TNode<Smi> phi_bb55_0;
  TNode<Smi> phi_bb55_1;
  TNode<Smi> tmp80;
  TNode<Smi> tmp81;
  if (block55.is_used()) {
    ca_.Bind(&block55, &phi_bb55_0, &phi_bb55_1);
    tmp80 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp81 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block59, tmp80, phi_bb55_1, tmp81);
  }

  TNode<Smi> phi_bb59_0;
  TNode<Smi> phi_bb59_1;
  TNode<Smi> phi_bb59_2;
  TNode<Smi> tmp82;
  TNode<BoolT> tmp83;
  if (block59.is_used()) {
    ca_.Bind(&block59, &phi_bb59_0, &phi_bb59_1, &phi_bb59_2);
    tmp82 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp83 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb59_2}, TNode<Smi>{tmp82});
    ca_.Branch(tmp83, &block61, std::vector<Node*>{phi_bb59_0, phi_bb59_1, phi_bb59_2}, &block62, std::vector<Node*>{phi_bb59_0, phi_bb59_1, phi_bb59_2});
  }

  TNode<Smi> phi_bb61_0;
  TNode<Smi> phi_bb61_1;
  TNode<Smi> phi_bb61_2;
  if (block61.is_used()) {
    ca_.Bind(&block61, &phi_bb61_0, &phi_bb61_1, &phi_bb61_2);
    ca_.Goto(&block60, phi_bb61_0, phi_bb61_1, phi_bb61_2);
  }

  TNode<Smi> phi_bb62_0;
  TNode<Smi> phi_bb62_1;
  TNode<Smi> phi_bb62_2;
  TNode<Smi> tmp84;
  TNode<BoolT> tmp85;
  if (block62.is_used()) {
    ca_.Bind(&block62, &phi_bb62_0, &phi_bb62_1, &phi_bb62_2);
    tmp84 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp85 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb62_2}, TNode<Smi>{tmp84});
    ca_.Branch(tmp85, &block63, std::vector<Node*>{phi_bb62_0, phi_bb62_1, phi_bb62_2}, &block64, std::vector<Node*>{phi_bb62_0, phi_bb62_1, phi_bb62_2});
  }

  TNode<Smi> phi_bb63_0;
  TNode<Smi> phi_bb63_1;
  TNode<Smi> phi_bb63_2;
  TNode<Smi> tmp86;
  TNode<BoolT> tmp87;
  if (block63.is_used()) {
    ca_.Bind(&block63, &phi_bb63_0, &phi_bb63_1, &phi_bb63_2);
    tmp86 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp87 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb63_0}, TNode<Smi>{tmp86});
    ca_.Branch(tmp87, &block65, std::vector<Node*>{phi_bb63_0, phi_bb63_1}, &block66, std::vector<Node*>{phi_bb63_0, phi_bb63_1});
  }

  TNode<Smi> phi_bb64_0;
  TNode<Smi> phi_bb64_1;
  TNode<Smi> phi_bb64_2;
  TNode<Smi> tmp88;
  if (block64.is_used()) {
    ca_.Bind(&block64, &phi_bb64_0, &phi_bb64_1, &phi_bb64_2);
    tmp88 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb64_0}, TNode<Smi>{phi_bb64_2});
    ca_.Goto(&block60, tmp88, phi_bb64_1, phi_bb64_2);
  }

  TNode<Smi> phi_bb60_0;
  TNode<Smi> phi_bb60_1;
  TNode<Smi> phi_bb60_2;
  TNode<Smi> tmp89;
  TNode<Smi> tmp90;
  if (block60.is_used()) {
    ca_.Bind(&block60, &phi_bb60_0, &phi_bb60_1, &phi_bb60_2);
    tmp89 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp90 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb60_2}, TNode<Smi>{tmp89});
    ca_.Goto(&block59, phi_bb60_0, phi_bb60_1, tmp90);
  }

  TNode<Smi> phi_bb66_0;
  TNode<Smi> phi_bb66_1;
  if (block66.is_used()) {
    ca_.Bind(&block66, &phi_bb66_0, &phi_bb66_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "../../deps/v8/test/torque/test-torque.tq", 426);
  }

  TNode<Smi> phi_bb65_0;
  TNode<Smi> phi_bb65_1;
  TNode<Smi> tmp91;
  TNode<Smi> tmp92;
  if (block65.is_used()) {
    ca_.Bind(&block65, &phi_bb65_0, &phi_bb65_1);
    tmp91 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp92 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block69, tmp91, tmp92);
  }

  TNode<Smi> phi_bb69_0;
  TNode<Smi> phi_bb69_1;
  TNode<Smi> tmp93;
  TNode<BoolT> tmp94;
  if (block69.is_used()) {
    ca_.Bind(&block69, &phi_bb69_0, &phi_bb69_1);
    tmp93 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp94 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb69_1}, TNode<Smi>{tmp93});
    ca_.Branch(tmp94, &block70, std::vector<Node*>{phi_bb69_0, phi_bb69_1}, &block71, std::vector<Node*>{phi_bb69_0, phi_bb69_1});
  }

  TNode<Smi> phi_bb70_0;
  TNode<Smi> phi_bb70_1;
  TNode<Smi> tmp95;
  TNode<Smi> tmp96;
  if (block70.is_used()) {
    ca_.Bind(&block70, &phi_bb70_0, &phi_bb70_1);
    tmp95 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp96 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb70_1}, TNode<Smi>{tmp95});
    ca_.Goto(&block69, phi_bb70_0, tmp96);
  }

  TNode<Smi> phi_bb71_0;
  TNode<Smi> phi_bb71_1;
  TNode<Smi> tmp97;
  TNode<BoolT> tmp98;
  if (block71.is_used()) {
    ca_.Bind(&block71, &phi_bb71_0, &phi_bb71_1);
    tmp97 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp98 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb71_1}, TNode<Smi>{tmp97});
    ca_.Branch(tmp98, &block72, std::vector<Node*>{phi_bb71_0, phi_bb71_1}, &block73, std::vector<Node*>{phi_bb71_0, phi_bb71_1});
  }

  TNode<Smi> phi_bb72_0;
  TNode<Smi> phi_bb72_1;
  TNode<Smi> tmp99;
  TNode<BoolT> tmp100;
  if (block72.is_used()) {
    ca_.Bind(&block72, &phi_bb72_0, &phi_bb72_1);
    tmp99 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp100 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb72_0}, TNode<Smi>{tmp99});
    ca_.Branch(tmp100, &block74, std::vector<Node*>{phi_bb72_0, phi_bb72_1}, &block75, std::vector<Node*>{phi_bb72_0, phi_bb72_1});
  }

  TNode<Smi> phi_bb73_0;
  TNode<Smi> phi_bb73_1;
  TNode<Smi> tmp101;
  TNode<Smi> tmp102;
  TNode<Smi> tmp103;
  if (block73.is_used()) {
    ca_.Bind(&block73, &phi_bb73_0, &phi_bb73_1);
    tmp101 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb73_0}, TNode<Smi>{phi_bb73_1});
    tmp102 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp103 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb73_1}, TNode<Smi>{tmp102});
    ca_.Goto(&block69, tmp101, tmp103);
  }

  TNode<Smi> phi_bb75_0;
  TNode<Smi> phi_bb75_1;
  if (block75.is_used()) {
    ca_.Bind(&block75, &phi_bb75_0, &phi_bb75_1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "../../deps/v8/test/torque/test-torque.tq", 440);
  }

  TNode<Smi> phi_bb74_0;
  TNode<Smi> phi_bb74_1;
  TNode<Smi> tmp104;
  if (block74.is_used()) {
    ca_.Bind(&block74, &phi_bb74_0, &phi_bb74_1);
    tmp104 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block80, phi_bb74_0, tmp104);
  }

  TNode<Smi> phi_bb80_0;
  TNode<Smi> phi_bb80_1;
  TNode<Smi> tmp105;
  TNode<Smi> tmp106;
  TNode<Smi> tmp107;
  TNode<BoolT> tmp108;
  if (block80.is_used()) {
    ca_.Bind(&block80, &phi_bb80_0, &phi_bb80_1);
    tmp105 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp106 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb80_1}, TNode<Smi>{tmp105});
    tmp107 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp108 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp106}, TNode<Smi>{tmp107});
    ca_.Branch(tmp108, &block81, std::vector<Node*>{phi_bb80_0}, &block82, std::vector<Node*>{phi_bb80_0});
  }

  TNode<Smi> phi_bb81_0;
  TNode<Smi> tmp109;
  TNode<BoolT> tmp110;
  if (block81.is_used()) {
    ca_.Bind(&block81, &phi_bb81_0);
    tmp109 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp110 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp106}, TNode<Smi>{tmp109});
    ca_.Branch(tmp110, &block83, std::vector<Node*>{phi_bb81_0}, &block84, std::vector<Node*>{phi_bb81_0});
  }

  TNode<Smi> phi_bb82_0;
  if (block82.is_used()) {
    ca_.Bind(&block82, &phi_bb82_0);
    ca_.Goto(&block80, phi_bb82_0, tmp106);
  }

  TNode<Smi> phi_bb84_0;
  if (block84.is_used()) {
    ca_.Bind(&block84, &phi_bb84_0);
    CodeStubAssembler(state_).FailAssert("Torque assert 'j == 10' failed", "../../deps/v8/test/torque/test-torque.tq", 448);
  }

  TNode<Smi> phi_bb83_0;
  if (block83.is_used()) {
    ca_.Bind(&block83, &phi_bb83_0);
    ca_.Goto(&block76, phi_bb83_0);
  }

  TNode<Smi> phi_bb76_0;
  TNode<Smi> tmp111;
  if (block76.is_used()) {
    ca_.Bind(&block76, &phi_bb76_0);
    tmp111 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block87, phi_bb76_0, tmp111);
  }

  TNode<Smi> phi_bb87_0;
  TNode<Smi> phi_bb87_3;
  TNode<Smi> tmp112;
  TNode<BoolT> tmp113;
  if (block87.is_used()) {
    ca_.Bind(&block87, &phi_bb87_0, &phi_bb87_3);
    tmp112 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp113 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb87_3}, TNode<Smi>{tmp112});
    ca_.Branch(tmp113, &block85, std::vector<Node*>{phi_bb87_0, phi_bb87_3}, &block86, std::vector<Node*>{phi_bb87_0, phi_bb87_3});
  }

  TNode<Smi> phi_bb85_0;
  TNode<Smi> phi_bb85_3;
  TNode<Smi> tmp114;
  TNode<Smi> tmp115;
  if (block85.is_used()) {
    ca_.Bind(&block85, &phi_bb85_0, &phi_bb85_3);
    tmp114 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp115 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb85_3}, TNode<Smi>{tmp114});
    ca_.Goto(&block87, phi_bb85_0, tmp115);
  }

  TNode<Smi> phi_bb86_0;
  TNode<Smi> phi_bb86_3;
  if (block86.is_used()) {
    ca_.Bind(&block86, &phi_bb86_0, &phi_bb86_3);
    ca_.Goto(&block89);
  }

    ca_.Bind(&block89);
}

void TestSubtyping_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Int32T> TypeswitchExample_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Object> tmp1;
  TNode<FixedArray> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    tmp1 = IncrementIfSmi_NumberOrFixedArray_0(state_, TNode<Object>{p_x});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_FixedArray_1(state_, TNode<Context>{p_context}, TNode<Object>{tmp1}, &label3);
    ca_.Goto(&block4);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block5);
    }
  }

  TNode<Int32T> tmp4;
  TNode<Int32T> tmp5;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp4 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    tmp5 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp4});
    ca_.Goto(&block2, tmp5);
  }

  TNode<Int32T> tmp6;
  TNode<Int32T> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp6 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp6});
    ca_.Goto(&block2, tmp7);
  }

  TNode<Int32T> phi_bb2_2;
  TNode<Int32T> tmp8;
  TNode<Int32T> tmp9;
  TNode<Object> tmp10;
  TNode<Smi> tmp11;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_2);
    tmp8 = FromConstexpr_int32_constexpr_int31_0(state_, 10);
    tmp9 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T>{phi_bb2_2}, TNode<Int32T>{tmp8});
    tmp10 = IncrementIfSmi_NumberOrFixedArray_0(state_, TNode<Object>{p_x});
    compiler::CodeAssemblerLabel label12(&ca_);
    tmp11 = Cast_Smi_0(state_, TNode<Object>{tmp10}, &label12);
    ca_.Goto(&block8);
    if (label12.is_used()) {
      ca_.Bind(&label12);
      ca_.Goto(&block9);
    }
  }

  TNode<FixedArray> tmp13;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    compiler::CodeAssemblerLabel label14(&ca_);
    tmp13 = Cast_FixedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp10)}, &label14);
    ca_.Goto(&block12);
    if (label14.is_used()) {
      ca_.Bind(&label14);
      ca_.Goto(&block13);
    }
  }

  TNode<Int32T> tmp15;
  TNode<Int32T> tmp16;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp15 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp11});
    tmp16 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp15});
    ca_.Goto(&block6, tmp16);
  }

  TNode<Int32T> tmp17;
  TNode<Int32T> tmp18;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp17 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    tmp18 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp17});
    ca_.Goto(&block10, tmp18);
  }

  TNode<IntPtrT> tmp19;
  TNode<Smi> tmp20;
  TNode<Int32T> tmp21;
  TNode<Int32T> tmp22;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp13, tmp19});
    tmp21 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp20});
    tmp22 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp21});
    ca_.Goto(&block10, tmp22);
  }

  TNode<Int32T> phi_bb10_2;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_2);
    ca_.Goto(&block6, phi_bb10_2);
  }

  TNode<Int32T> phi_bb6_2;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_2);
    ca_.Goto(&block14, phi_bb6_2);
  }

  TNode<Int32T> phi_bb14_2;
    ca_.Bind(&block14, &phi_bb14_2);
  return TNode<Int32T>{phi_bb14_2};
}

void TestTypeswitch_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp1 = TypeswitchExample_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp0});
    tmp2 = FromConstexpr_int32_constexpr_int31_0(state_, 26);
    tmp3 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(FromConstexpr<Smi>(5)) == 26' failed", "../../deps/v8/test/torque/test-torque.tq", 505);
  }

  TNode<IntPtrT> tmp4;
  TNode<FixedArray> tmp5;
  TNode<Int32T> tmp6;
  TNode<Int32T> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    tmp5 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT>{tmp4});
    tmp6 = TypeswitchExample_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp5});
    tmp7 = FromConstexpr_int32_constexpr_int31_0(state_, 13);
    tmp8 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp6}, TNode<Int32T>{tmp7});
    ca_.Branch(tmp8, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(a) == 13' failed", "../../deps/v8/test/torque/test-torque.tq", 507);
  }

  TNode<Number> tmp9;
  TNode<Int32T> tmp10;
  TNode<Int32T> tmp11;
  TNode<BoolT> tmp12;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp9 = FromConstexpr_Number_constexpr_float64_0(state_, 0.5);
    tmp10 = TypeswitchExample_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp9});
    tmp11 = FromConstexpr_int32_constexpr_int31_0(state_, 27);
    tmp12 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp10}, TNode<Int32T>{tmp11});
    ca_.Branch(tmp12, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(FromConstexpr<Number>(0.5)) == 27' failed", "../../deps/v8/test/torque/test-torque.tq", 508);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestTypeswitchAsanLsanFailure_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{p_obj}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<JSTypedArray> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_obj)}, &label3);
    ca_.Goto(&block8);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block9);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block2);
  }

  TNode<JSReceiver> tmp4;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(p_obj)}, &label5);
    ca_.Goto(&block12);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block13);
    }
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block6);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    ca_.Goto(&block10);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    ca_.Goto(&block10);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
}

void TestGenericOverload_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp1 = ExampleGenericOverload_Smi_0(state_, TNode<Smi>{tmp0});
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 6);
    tmp3 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ExampleGenericOverload<Smi>(xSmi) == 6' failed", "../../deps/v8/test/torque/test-torque.tq", 536);
  }

  TNode<Object> tmp4;
  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = ExampleGenericOverload_Object_0(state_, TNode<Object>{tmp0});
    tmp5 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp4});
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp7 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp5}, TNode<Smi>{tmp6});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'UnsafeCast<Smi>(ExampleGenericOverload<Object>(xObject)) == 5' failed", "../../deps/v8/test/torque/test-torque.tq", 537);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestEquality_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Float64T> tmp0;
  TNode<HeapNumber> tmp1;
  TNode<Float64T> tmp2;
  TNode<HeapNumber> tmp3;
  TNode<BoolT> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    tmp1 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp0});
    tmp2 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    tmp3 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp2});
    tmp4 = IsNumberNotEqual_0(state_, TNode<Number>{tmp1}, TNode<Number>{tmp3});
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp4});
    ca_.Branch(tmp5, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert '!notEqual' failed", "../../deps/v8/test/torque/test-torque.tq", 544);
  }

  TNode<Float64T> tmp6;
  TNode<HeapNumber> tmp7;
  TNode<Float64T> tmp8;
  TNode<HeapNumber> tmp9;
  TNode<BoolT> tmp10;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp6 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    tmp7 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp6});
    tmp8 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    tmp9 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp8});
    tmp10 = IsNumberEqual_0(state_, TNode<Number>{tmp7}, TNode<Number>{tmp9});
    ca_.Branch(tmp10, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'equal' failed", "../../deps/v8/test/torque/test-torque.tq", 547);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

TNode<BoolT> TestOrAnd_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Branch(p_x, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<BoolT> tmp0;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block8, tmp0);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Branch(p_y, &block9, std::vector<Node*>{}, &block10, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    ca_.Goto(&block11, p_z);
  }

  TNode<BoolT> tmp1;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block11, tmp1);
  }

  TNode<BoolT> phi_bb11_5;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_5);
    ca_.Goto(&block8, phi_bb11_5);
  }

  TNode<BoolT> phi_bb8_4;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4);
    ca_.Branch(phi_bb8_4, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp3);
  }

  TNode<BoolT> phi_bb4_3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3);
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
  return TNode<BoolT>{phi_bb4_3};
}

TNode<BoolT> TestAndOr_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Branch(p_x, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8, p_y);
  }

  TNode<BoolT> tmp0;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp0);
  }

  TNode<BoolT> phi_bb8_4;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_4);
    ca_.Branch(phi_bb8_4, &block9, std::vector<Node*>{}, &block10, std::vector<Node*>{});
  }

  TNode<BoolT> tmp1;
  if (block9.is_used()) {
    ca_.Bind(&block9);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp1);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    ca_.Goto(&block11, p_z);
  }

  TNode<BoolT> phi_bb11_4;
  if (block11.is_used()) {
    ca_.Bind(&block11, &phi_bb11_4);
    ca_.Branch(phi_bb11_4, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp3);
  }

  TNode<BoolT> phi_bb4_3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3);
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
  return TNode<BoolT>{phi_bb4_3};
}

void TestLogicalOperators_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  TNode<BoolT> tmp2;
  TNode<BoolT> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp3 = TestAndOr_0(state_, TNode<BoolT>{tmp0}, TNode<BoolT>{tmp1}, TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, true, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 562);
  }

  TNode<BoolT> tmp4;
  TNode<BoolT> tmp5;
  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp7 = TestAndOr_0(state_, TNode<BoolT>{tmp4}, TNode<BoolT>{tmp5}, TNode<BoolT>{tmp6});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, true, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 563);
  }

  TNode<BoolT> tmp8;
  TNode<BoolT> tmp9;
  TNode<BoolT> tmp10;
  TNode<BoolT> tmp11;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp11 = TestAndOr_0(state_, TNode<BoolT>{tmp8}, TNode<BoolT>{tmp9}, TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, false, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 564);
  }

  TNode<BoolT> tmp12;
  TNode<BoolT> tmp13;
  TNode<BoolT> tmp14;
  TNode<BoolT> tmp15;
  TNode<BoolT> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp15 = TestAndOr_0(state_, TNode<BoolT>{tmp12}, TNode<BoolT>{tmp13}, TNode<BoolT>{tmp14});
    tmp16 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp15});
    ca_.Branch(tmp16, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(true, false, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 565);
  }

  TNode<BoolT> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  TNode<BoolT> tmp20;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp20 = TestAndOr_0(state_, TNode<BoolT>{tmp17}, TNode<BoolT>{tmp18}, TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block10, std::vector<Node*>{}, &block11, std::vector<Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(false, true, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 566);
  }

  TNode<BoolT> tmp21;
  TNode<BoolT> tmp22;
  TNode<BoolT> tmp23;
  TNode<BoolT> tmp24;
  TNode<BoolT> tmp25;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp24 = TestAndOr_0(state_, TNode<BoolT>{tmp21}, TNode<BoolT>{tmp22}, TNode<BoolT>{tmp23});
    tmp25 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp24});
    ca_.Branch(tmp25, &block12, std::vector<Node*>{}, &block13, std::vector<Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(false, true, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 567);
  }

  TNode<BoolT> tmp26;
  TNode<BoolT> tmp27;
  TNode<BoolT> tmp28;
  TNode<BoolT> tmp29;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp29 = TestAndOr_0(state_, TNode<BoolT>{tmp26}, TNode<BoolT>{tmp27}, TNode<BoolT>{tmp28});
    ca_.Branch(tmp29, &block14, std::vector<Node*>{}, &block15, std::vector<Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(false, false, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 568);
  }

  TNode<BoolT> tmp30;
  TNode<BoolT> tmp31;
  TNode<BoolT> tmp32;
  TNode<BoolT> tmp33;
  TNode<BoolT> tmp34;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp30 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp31 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp32 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp33 = TestAndOr_0(state_, TNode<BoolT>{tmp30}, TNode<BoolT>{tmp31}, TNode<BoolT>{tmp32});
    tmp34 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp33});
    ca_.Branch(tmp34, &block16, std::vector<Node*>{}, &block17, std::vector<Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(false, false, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 569);
  }

  TNode<BoolT> tmp35;
  TNode<BoolT> tmp36;
  TNode<BoolT> tmp37;
  TNode<BoolT> tmp38;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp36 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp38 = TestOrAnd_0(state_, TNode<BoolT>{tmp35}, TNode<BoolT>{tmp36}, TNode<BoolT>{tmp37});
    ca_.Branch(tmp38, &block18, std::vector<Node*>{}, &block19, std::vector<Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, true, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 570);
  }

  TNode<BoolT> tmp39;
  TNode<BoolT> tmp40;
  TNode<BoolT> tmp41;
  TNode<BoolT> tmp42;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp39 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp42 = TestOrAnd_0(state_, TNode<BoolT>{tmp39}, TNode<BoolT>{tmp40}, TNode<BoolT>{tmp41});
    ca_.Branch(tmp42, &block20, std::vector<Node*>{}, &block21, std::vector<Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, true, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 571);
  }

  TNode<BoolT> tmp43;
  TNode<BoolT> tmp44;
  TNode<BoolT> tmp45;
  TNode<BoolT> tmp46;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp43 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp44 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp45 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp46 = TestOrAnd_0(state_, TNode<BoolT>{tmp43}, TNode<BoolT>{tmp44}, TNode<BoolT>{tmp45});
    ca_.Branch(tmp46, &block22, std::vector<Node*>{}, &block23, std::vector<Node*>{});
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, false, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 572);
  }

  TNode<BoolT> tmp47;
  TNode<BoolT> tmp48;
  TNode<BoolT> tmp49;
  TNode<BoolT> tmp50;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp47 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp49 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp50 = TestOrAnd_0(state_, TNode<BoolT>{tmp47}, TNode<BoolT>{tmp48}, TNode<BoolT>{tmp49});
    ca_.Branch(tmp50, &block24, std::vector<Node*>{}, &block25, std::vector<Node*>{});
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, false, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 573);
  }

  TNode<BoolT> tmp51;
  TNode<BoolT> tmp52;
  TNode<BoolT> tmp53;
  TNode<BoolT> tmp54;
  if (block24.is_used()) {
    ca_.Bind(&block24);
    tmp51 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp52 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp53 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp54 = TestOrAnd_0(state_, TNode<BoolT>{tmp51}, TNode<BoolT>{tmp52}, TNode<BoolT>{tmp53});
    ca_.Branch(tmp54, &block26, std::vector<Node*>{}, &block27, std::vector<Node*>{});
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(false, true, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 574);
  }

  TNode<BoolT> tmp55;
  TNode<BoolT> tmp56;
  TNode<BoolT> tmp57;
  TNode<BoolT> tmp58;
  TNode<BoolT> tmp59;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp56 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp57 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp58 = TestOrAnd_0(state_, TNode<BoolT>{tmp55}, TNode<BoolT>{tmp56}, TNode<BoolT>{tmp57});
    tmp59 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp58});
    ca_.Branch(tmp59, &block28, std::vector<Node*>{}, &block29, std::vector<Node*>{});
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, true, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 575);
  }

  TNode<BoolT> tmp60;
  TNode<BoolT> tmp61;
  TNode<BoolT> tmp62;
  TNode<BoolT> tmp63;
  TNode<BoolT> tmp64;
  if (block28.is_used()) {
    ca_.Bind(&block28);
    tmp60 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp61 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp62 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    tmp63 = TestOrAnd_0(state_, TNode<BoolT>{tmp60}, TNode<BoolT>{tmp61}, TNode<BoolT>{tmp62});
    tmp64 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp63});
    ca_.Branch(tmp64, &block30, std::vector<Node*>{}, &block31, std::vector<Node*>{});
  }

  if (block31.is_used()) {
    ca_.Bind(&block31);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, false, true)' failed", "../../deps/v8/test/torque/test-torque.tq", 576);
  }

  TNode<BoolT> tmp65;
  TNode<BoolT> tmp66;
  TNode<BoolT> tmp67;
  TNode<BoolT> tmp68;
  TNode<BoolT> tmp69;
  if (block30.is_used()) {
    ca_.Bind(&block30);
    tmp65 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp66 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp67 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    tmp68 = TestOrAnd_0(state_, TNode<BoolT>{tmp65}, TNode<BoolT>{tmp66}, TNode<BoolT>{tmp67});
    tmp69 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp68});
    ca_.Branch(tmp69, &block32, std::vector<Node*>{}, &block33, std::vector<Node*>{});
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, false, false)' failed", "../../deps/v8/test/torque/test-torque.tq", 577);
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.Goto(&block34);
  }

    ca_.Bind(&block34);
}

TNode<Smi> TestCall_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_i, compiler::CodeAssemblerLabel* label_A) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp1 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{p_i}, TNode<Smi>{tmp0});
    ca_.Branch(tmp1, &block3, std::vector<Node*>{}, &block4, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block5);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_A);
  }

    ca_.Bind(&block5);
  return TNode<Smi>{p_i};
}

void TestOtherwiseWithCode1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  TNode<Smi> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = TestCall_0(state_, TNode<Smi>{tmp2}, &label4);
    ca_.Goto(&block6);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block7);
    }
  }

  TNode<Smi> tmp5;
  TNode<Smi> tmp6;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp6 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp1}, TNode<Smi>{tmp5});
    ca_.Goto(&block2, tmp6, tmp6);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block2, tmp0, tmp1);
  }

  TNode<Smi> phi_bb2_0;
  TNode<Smi> phi_bb2_1;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_0, &phi_bb2_1);
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
}

void TestOtherwiseWithCode2_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  TNode<Smi> phi_bb4_0;
  TNode<Smi> phi_bb4_1;
  TNode<Smi> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_0, &phi_bb4_1);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp3 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb4_1}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{phi_bb4_0, phi_bb4_1}, &block3, std::vector<Node*>{phi_bb4_0, phi_bb4_1});
  }

  TNode<Smi> phi_bb2_0;
  TNode<Smi> phi_bb2_1;
  TNode<Smi> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_0, &phi_bb2_1);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = TestCall_0(state_, TNode<Smi>{phi_bb2_1}, &label5);
    ca_.Goto(&block8, phi_bb2_0, phi_bb2_1, phi_bb2_1);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block9, phi_bb2_0, phi_bb2_1, phi_bb2_1);
    }
  }

  TNode<Smi> phi_bb9_0;
  TNode<Smi> phi_bb9_1;
  TNode<Smi> phi_bb9_2;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_0, &phi_bb9_1, &phi_bb9_2);
    ca_.Goto(&block3, phi_bb9_0, phi_bb9_1);
  }

  TNode<Smi> phi_bb8_0;
  TNode<Smi> phi_bb8_1;
  TNode<Smi> phi_bb8_2;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  TNode<Smi> tmp9;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_0, &phi_bb8_1, &phi_bb8_2);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp7 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb8_0}, TNode<Smi>{tmp6});
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp9 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb8_1}, TNode<Smi>{tmp8});
    ca_.Goto(&block4, tmp7, tmp9);
  }

  TNode<Smi> phi_bb3_0;
  TNode<Smi> phi_bb3_1;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_0, &phi_bb3_1);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
}

void TestOtherwiseWithCode3_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  TNode<Smi> phi_bb4_0;
  TNode<Smi> phi_bb4_1;
  TNode<Smi> tmp2;
  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_0, &phi_bb4_1);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    tmp3 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb4_1}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block2, std::vector<Node*>{phi_bb4_0, phi_bb4_1}, &block3, std::vector<Node*>{phi_bb4_0, phi_bb4_1});
  }

  TNode<Smi> phi_bb2_0;
  TNode<Smi> phi_bb2_1;
  TNode<Smi> tmp4;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_0, &phi_bb2_1);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = TestCall_0(state_, TNode<Smi>{phi_bb2_1}, &label5);
    ca_.Goto(&block8, phi_bb2_0, phi_bb2_1, phi_bb2_0, phi_bb2_1);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block9, phi_bb2_0, phi_bb2_1, phi_bb2_0, phi_bb2_1);
    }
  }

  TNode<Smi> phi_bb9_0;
  TNode<Smi> phi_bb9_1;
  TNode<Smi> phi_bb9_2;
  TNode<Smi> phi_bb9_3;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_0, &phi_bb9_1, &phi_bb9_2, &phi_bb9_3);
    ca_.Goto(&block3, phi_bb9_0, phi_bb9_1);
  }

  TNode<Smi> phi_bb8_0;
  TNode<Smi> phi_bb8_1;
  TNode<Smi> phi_bb8_2;
  TNode<Smi> phi_bb8_3;
  TNode<Smi> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  if (block8.is_used()) {
    ca_.Bind(&block8, &phi_bb8_0, &phi_bb8_1, &phi_bb8_2, &phi_bb8_3);
    tmp6 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb8_2}, TNode<Smi>{tmp4});
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp8 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb8_1}, TNode<Smi>{tmp7});
    ca_.Goto(&block4, tmp6, tmp8);
  }

  TNode<Smi> phi_bb3_0;
  TNode<Smi> phi_bb3_1;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_0, &phi_bb3_1);
    ca_.Goto(&block14);
  }

    ca_.Bind(&block14);
}

void TestForwardLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

void TestQualifiedAccess_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<BoolT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp1 = Is_JSArray_Smi_0(state_, TNode<Context>{p_context}, TNode<Smi>{tmp0});
    tmp2 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp1});
    ca_.Branch(tmp2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert '!Is<JSArray>(s)' failed", "../../deps/v8/test/torque/test-torque.tq", 631);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

TNode<Smi> TestCatch1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
      TNode<Object> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerExceptionHandlerLabel catch1__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch1__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kInvalidArrayLength);
    }
    if (catch1__label.is_used()) {
      compiler::CodeAssemblerLabel catch1_skip(&ca_);
      ca_.Bind(&catch1__label, &tmp2);
      ca_.Goto(&block4);
    }
  }

  TNode<Smi> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<Smi>{tmp3};
}

void TestCatch2Wrapper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kInvalidArrayLength);
  }
}

TNode<Smi> TestCatch2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
      TNode<Object> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerExceptionHandlerLabel catch1__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch1__label);
    TestCatch2Wrapper_0(state_, TNode<Context>{p_context});
    }
    if (catch1__label.is_used()) {
      compiler::CodeAssemblerLabel catch1_skip(&ca_);
      ca_.Bind(&catch1__label, &tmp2);
      ca_.Goto(&block4);
    }
  }

  TNode<Smi> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
  return TNode<Smi>{tmp3};
}

void TestCatch3WrapperWithLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, compiler::CodeAssemblerLabel* label__Abort) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{p_context}, MessageTemplate::kInvalidArrayLength);
  }
}

TNode<Smi> TestCatch3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
      TNode<Object> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerLabel label1(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::ScopedExceptionHandler s(&ca_, &catch2__label);
    TestCatch3WrapperWithLabel_0(state_, TNode<Context>{p_context}, &label1);
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      ca_.Bind(&catch2__label, &tmp3);
      ca_.Goto(&block7);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block6);
    }
  }

  TNode<Smi> tmp4;
  if (block7.is_used()) {
    ca_.Bind(&block7);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    ca_.Goto(&block1, tmp4);
  }

  TNode<Smi> tmp5;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp5);
  }

  TNode<Smi> phi_bb1_1;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_1);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<Smi>{phi_bb1_1};
}

void TestIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Map> p_map) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Object> tmp0;
  TNode<JSReceiver> tmp1;
  TNode<Object> tmp2;
  TNode<JSReceiver> tmp3;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = IteratorBuiltinsAssembler(state_).GetIteratorMethod(TNode<Context>{p_context}, TNode<Object>{p_o});
    std::tie(tmp1, tmp2) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{p_context}, TNode<Object>{p_o}).Flatten();
    compiler::CodeAssemblerLabel label4(&ca_);
    tmp3 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, &label4);
    ca_.Goto(&block4);
    if (label4.is_used()) {
      ca_.Bind(&label4);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block3);
  }

  TNode<JSReceiver> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerLabel label6(&ca_);
    tmp5 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}}, TNode<Map>{p_map}, &label6);
    ca_.Goto(&block6);
    if (label6.is_used()) {
      ca_.Bind(&label6);
      ca_.Goto(&block7);
    }
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    ca_.Goto(&block3);
  }

  TNode<Object> tmp7;
  TNode<Object> tmp8;
  TNode<JSArray> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{p_context}, TNode<JSReceiver>{p_o});
    tmp8 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{p_context}, TNode<JSReceiver>{p_o}, TNode<Map>{p_map});
    tmp9 = IteratorBuiltinsAssembler(state_).IterableToList(TNode<Context>{p_context}, TNode<Object>{tmp0}, TNode<Object>{tmp0});
    IteratorCloseOnException_0(state_, TNode<Context>{p_context}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp1}, TNode<Object>{tmp2}});
    ca_.Goto(&block2);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(&block2);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestFrame1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<Object> tmp1;
  TNode<Smi> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadFramePointer();
    tmp1 = LoadContextOrFrameTypeFromFrame_0(state_, TNode<Context>{p_context}, TNode<RawPtrT>{tmp0});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_FrameType_0(state_, TNode<Object>{tmp1}, &label3);
    ca_.Goto(&block4);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<RawPtrT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    compiler::CodeAssemblerLabel label5(&ca_);
    tmp4 = Cast_StandardFrame_0(state_, TNode<Context>{p_context}, TNode<RawPtrT>{tmp0}, &label5);
    ca_.Goto(&block16);
    if (label5.is_used()) {
      ca_.Bind(&label5);
      ca_.Goto(&block17);
    }
  }

  TNode<RawPtrT> tmp6;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    compiler::CodeAssemblerLabel label7(&ca_);
    tmp6 = Cast_ArgumentsAdaptorFrame_0(state_, TNode<Context>{p_context}, TNode<RawPtrT>{ca_.UncheckedCast<RawPtrT>(tmp0)}, &label7);
    ca_.Goto(&block20);
    if (label7.is_used()) {
      ca_.Bind(&label7);
      ca_.Goto(&block21);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    ca_.Goto(&block22);
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block22);
}

void TestNew_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = NewJSArray_1(state_, TNode<Context>{p_context});
    tmp1 = Method_JSArray_IsEmpty_0(state_, TNode<JSArray>{tmp0});
    ca_.Branch(tmp1, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'f.IsEmpty()' failed", "../../deps/v8/test/torque/test-torque.tq", 725);
  }

  TNode<IntPtrT> tmp2;
  TNode<Number> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp3 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp0, tmp2}, tmp3);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

void TestStructConstructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Int32T> tmp1;
  TNode<Int32T> tmp2;
  TNode<Int32T> tmp3;
  TNode<Int32T> tmp4;
  TNode<BoolT> tmp5;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int31_0(state_, 6);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    tmp2 = FromConstexpr_int32_constexpr_int31_0(state_, 5);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    tmp4 = FromConstexpr_int32_constexpr_int31_0(state_, 5);
    tmp5 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp2}, TNode<Int32T>{tmp4});
    ca_.Branch(tmp5, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.a == 5' failed", "../../deps/v8/test/torque/test-torque.tq", 750);
  }

  TNode<Int32T> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp6 = FromConstexpr_int32_constexpr_int31_0(state_, 6);
    tmp7 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp0}, TNode<Int32T>{tmp6});
    ca_.Branch(tmp7, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 6' failed", "../../deps/v8/test/torque/test-torque.tq", 751);
  }

  TNode<Int32T> tmp8;
  TNode<BoolT> tmp9;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp8 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.y == 7' failed", "../../deps/v8/test/torque/test-torque.tq", 752);
  }

  TNode<Int32T> tmp10;
  TNode<BoolT> tmp11;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp10 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    tmp11 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp10});
    ca_.Branch(tmp11, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.c == 8' failed", "../../deps/v8/test/torque/test-torque.tq", 753);
  }

  TNode<Int32T> tmp12;
  TNode<Int32T> tmp13;
  TNode<BoolT> tmp14;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp12 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp13 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp14 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp12}, TNode<Int32T>{tmp13});
    ca_.Branch(tmp14, &block10, std::vector<Node*>{}, &block11, std::vector<Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 1' failed", "../../deps/v8/test/torque/test-torque.tq", 755);
  }

  TNode<Int32T> tmp15;
  TNode<Int32T> tmp16;
  TNode<BoolT> tmp17;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp15 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    tmp16 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    tmp17 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp15}, TNode<Int32T>{tmp16});
    ca_.Branch(tmp17, &block13, std::vector<Node*>{}, &block14, std::vector<Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 2' failed", "../../deps/v8/test/torque/test-torque.tq", 757);
  }

  TNode<Int32T> tmp18;
  TNode<BoolT> tmp19;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp18 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    tmp19 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp15}, TNode<Int32T>{tmp18});
    ca_.Branch(tmp19, &block15, std::vector<Node*>{}, &block16, std::vector<Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.GetX() == 2' failed", "../../deps/v8/test/torque/test-torque.tq", 758);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    ca_.Goto(&block18);
  }

    ca_.Bind(&block18);
}

TNode<InternalClass> NewInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  TNode<Map> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<HeapObject> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<InternalClass> tmp8;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp1 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_x}, TNode<Smi>{tmp0});
    tmp2 = CodeStubAssembler(state_).GetInstanceTypeMap(INTERNAL_CLASS_TYPE);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp4 = Allocate_0(state_, TNode<IntPtrT>{tmp3}, TNode<Map>{tmp2});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp4, tmp5}, tmp2);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp6}, p_x);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{tmp4, tmp7}, tmp1);
    tmp8 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<InternalClass>{tmp8};
}

void TestInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<InternalClass> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp1 = NewInternalClass_0(state_, TNode<Smi>{tmp0});
    compiler::CodeAssemblerLabel label2(&ca_);
    Method_InternalClass_Flip_0(state_, TNode<InternalClass>{tmp1}, &label2);
    ca_.Goto(&block4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp3;
  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp3});
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 6);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp4}, TNode<Smi>{tmp5});
    ca_.Branch(tmp6, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o.a == 6' failed", "../../deps/v8/test/torque/test-torque.tq", 779);
  }

  TNode<IntPtrT> tmp7;
  TNode<Number> tmp8;
  TNode<Number> tmp9;
  TNode<BoolT> tmp10;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp1, tmp7});
    tmp9 = FromConstexpr_Number_constexpr_int31_0(state_, 5);
    tmp10 = IsNumberEqual_0(state_, TNode<Number>{tmp8}, TNode<Number>{tmp9});
    ca_.Branch(tmp10, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o.b == 5' failed", "../../deps/v8/test/torque/test-torque.tq", 780);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

void TestConstInStructs_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<Int32T> tmp1;
  TNode<Oddball> tmp2;
  TNode<Int32T> tmp3;
  TNode<Oddball> tmp4;
  TNode<Int32T> tmp5;
  TNode<BoolT> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Null_0(state_);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp2 = Null_0(state_);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp4 = Undefined_0(state_);
    tmp5 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x.TestMethod1() == 1' failed", "../../deps/v8/test/torque/test-torque.tq", 801);
  }

  TNode<Oddball> tmp7;
  TNode<BoolT> tmp8;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp7 = Null_0(state_);
    tmp8 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp0}, TNode<HeapObject>{tmp7});
    ca_.Branch(tmp8, &block5, std::vector<Node*>{}, &block6, std::vector<Node*>{});
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x.TestMethod2() == Null' failed", "../../deps/v8/test/torque/test-torque.tq", 802);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestParentFrameArguments_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<RawPtrT> tmp0;
  TNode<RawPtrT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadParentFramePointer();
    compiler::CodeAssemblerLabel label2(&ca_);
    tmp1 = Cast_StandardFrame_0(state_, TNode<Context>{p_context}, TNode<RawPtrT>{tmp0}, &label2);
    ca_.Goto(&block4);
    if (label2.is_used()) {
      ca_.Bind(&label2);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp3;
  TNode<RawPtrT> tmp4;
  TNode<RawPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    std::tie(tmp4, tmp5, tmp6) = CodeStubAssembler(state_).GetFrameArguments(TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp3}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

TNode<Object> TestNewFixedArrayFromSpread_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Map> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<FixedArray> tmp10;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp1 = kFixedArrayMap_0(state_);
    tmp2 = Convert_intptr_constexpr_int31_0(state_, 5);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp4 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2}, kTaggedSize);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp1});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp8);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_TestIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp5}, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}}, TorqueStructTestIterator_0{TNode<Smi>{tmp0}});
    tmp10 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp10};
}

void TestReferences_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Smi> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Smi> tmp7;
  TNode<SmiPair> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Smi> tmp10;
  TNode<Smi> tmp11;
  TNode<Smi> tmp12;
  TNode<Smi> tmp13;
  TNode<Smi> tmp14;
  TNode<Smi> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<HeapObject> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Smi> tmp20;
  TNode<Smi> tmp21;
  TNode<BoolT> tmp22;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).GetInstanceTypeMap(SMI_PAIR_TYPE);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp2 = Allocate_0(state_, TNode<IntPtrT>{tmp1}, TNode<Map>{tmp0});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp0);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp4}, tmp5);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp6}, tmp7);
    tmp8 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp10 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9});
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp12 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp11}, TNode<Smi>{tmp10});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9}, tmp12);
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9});
    tmp14 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp15 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp13}, TNode<Smi>{tmp14});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp9}, tmp15);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    std::tie(tmp17, tmp18) = Method_SmiPair_GetA_0(state_, TNode<SmiPair>{tmp8}).Flatten();
    Swap_Smi_0(state_, TorqueStructReference_Smi_0{TNode<HeapObject>{tmp8}, TNode<IntPtrT>{tmp16}, TorqueStructUnsafe_0{}}, TorqueStructReference_Smi_0{TNode<HeapObject>{tmp17}, TNode<IntPtrT>{tmp18}, TorqueStructUnsafe_0{}});
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp19});
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    tmp22 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp20}, TNode<Smi>{tmp21});
    ca_.Branch(tmp22, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.a == 2' failed", "../../deps/v8/test/torque/test-torque.tq", 848);
  }

  TNode<IntPtrT> tmp23;
  TNode<Smi> tmp24;
  TNode<Smi> tmp25;
  TNode<BoolT> tmp26;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp24 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp8, tmp23});
    tmp25 = FromConstexpr_Smi_constexpr_int31_0(state_, 9);
    tmp26 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp24}, TNode<Smi>{tmp25});
    ca_.Branch(tmp26, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.b == 9' failed", "../../deps/v8/test/torque/test-torque.tq", 849);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestSlices_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Map> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<FixedArray> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<Smi> tmp12;
  TNode<Smi> tmp13;
  TNode<BoolT> tmp14;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp1 = kFixedArrayMap_0(state_);
    tmp2 = Convert_intptr_constexpr_int31_0(state_, 3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp4 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp2}, kTaggedSize);
    tmp5 = Allocate_0(state_, TNode<IntPtrT>{tmp4}, TNode<Map>{tmp1});
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp1);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp7}, tmp8);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    InitializeFieldsFromIterator_Object_TestIterator_0(state_, TorqueStructSlice_Object_0{TNode<HeapObject>{tmp5}, TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp2}, TorqueStructUnsafe_0{}}, TorqueStructTestIterator_0{TNode<Smi>{tmp0}});
    tmp10 = TORQUE_CAST(TNode<HeapObject>{tmp5});
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp12 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp11});
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp12}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.length == 3' failed", "../../deps/v8/test/torque/test-torque.tq", 856);
  }

  TNode<Smi> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<Smi> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<BoolT> tmp24;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp15 = Convert_Smi_constexpr_int31_0(state_, 123);
    tmp16 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp18 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp19 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp18});
    tmp20 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp19});
    tmp21 = Convert_intptr_constexpr_int31_0(state_, 0);
    tmp22 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    tmp23 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp20});
    tmp24 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp22}, TNode<UintPtrT>{tmp23});
    ca_.Branch(tmp24, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<HeapObject> tmp28;
  TNode<IntPtrT> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<Smi> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<UintPtrT> tmp36;
  TNode<UintPtrT> tmp37;
  TNode<BoolT> tmp38;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp25});
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp16}, TNode<IntPtrT>{tmp26});
    std::tie(tmp28, tmp29) = NewReference_Object_0(state_, TNode<HeapObject>{tmp10}, TNode<IntPtrT>{tmp27}).Flatten();
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp28, tmp29}, tmp15);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp33 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp32});
    tmp34 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp33});
    tmp35 = Convert_intptr_constexpr_int31_0(state_, 0);
    tmp36 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp35});
    tmp37 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp34});
    tmp38 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp36}, TNode<UintPtrT>{tmp37});
    ca_.Branch(tmp38, &block15, std::vector<Node*>{}, &block16, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<HeapObject> tmp42;
  TNode<IntPtrT> tmp43;
  TNode<Object> tmp44;
  TNode<BoolT> tmp45;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp39 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp40 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp35}, TNode<IntPtrT>{tmp39});
    tmp41 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp40});
    std::tie(tmp42, tmp43) = NewReference_Object_0(state_, TNode<HeapObject>{tmp10}, TNode<IntPtrT>{tmp41}).Flatten();
    tmp44 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp42, tmp43});
    tmp45 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp44}, TNode<MaybeObject>{tmp15});
    ca_.Branch(tmp45, &block18, std::vector<Node*>{}, &block19, std::vector<Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(* firstRef, oneTwoThree)' failed", "../../deps/v8/test/torque/test-torque.tq", 861);
  }

  TNode<IntPtrT> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<IntPtrT> tmp48;
  TNode<Smi> tmp49;
  TNode<IntPtrT> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<UintPtrT> tmp52;
  TNode<UintPtrT> tmp53;
  TNode<BoolT> tmp54;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp48 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp49 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp48});
    tmp50 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp49});
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp52 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp51});
    tmp53 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp50});
    tmp54 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp52}, TNode<UintPtrT>{tmp53});
    ca_.Branch(tmp54, &block23, std::vector<Node*>{}, &block24, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp55;
  TNode<IntPtrT> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<HeapObject> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<Object> tmp60;
  TNode<BoolT> tmp61;
  if (block23.is_used()) {
    ca_.Bind(&block23);
    tmp55 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp56 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp51}, TNode<IntPtrT>{tmp55});
    tmp57 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp46}, TNode<IntPtrT>{tmp56});
    std::tie(tmp58, tmp59) = NewReference_Object_0(state_, TNode<HeapObject>{tmp10}, TNode<IntPtrT>{tmp57}).Flatten();
    tmp60 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp58, tmp59});
    tmp61 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp60}, TNode<MaybeObject>{tmp15});
    ca_.Branch(tmp61, &block26, std::vector<Node*>{}, &block27, std::vector<Node*>{});
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(* firstRefAgain, oneTwoThree)' failed", "../../deps/v8/test/torque/test-torque.tq", 865);
  }

  TNode<Smi> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  TNode<IntPtrT> tmp65;
  TNode<Smi> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<IntPtrT> tmp68;
  TNode<UintPtrT> tmp69;
  TNode<UintPtrT> tmp70;
  TNode<BoolT> tmp71;
  if (block26.is_used()) {
    ca_.Bind(&block26);
    tmp62 = Convert_Smi_constexpr_int31_0(state_, 321);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp58, tmp59}, tmp62);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp64 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp65 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp66 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp65});
    tmp67 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp66});
    tmp68 = Convert_intptr_constexpr_int31_0(state_, 0);
    tmp69 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp68});
    tmp70 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp67});
    tmp71 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp69}, TNode<UintPtrT>{tmp70});
    ca_.Branch(tmp71, &block34, std::vector<Node*>{}, &block35, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp72;
  TNode<IntPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<HeapObject> tmp75;
  TNode<IntPtrT> tmp76;
  TNode<Object> tmp77;
  TNode<BoolT> tmp78;
  if (block34.is_used()) {
    ca_.Bind(&block34);
    tmp72 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp73 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp68}, TNode<IntPtrT>{tmp72});
    tmp74 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp63}, TNode<IntPtrT>{tmp73});
    std::tie(tmp75, tmp76) = NewReference_Object_0(state_, TNode<HeapObject>{tmp10}, TNode<IntPtrT>{tmp74}).Flatten();
    tmp77 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp75, tmp76});
    tmp78 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp77}, TNode<MaybeObject>{tmp62});
    ca_.Branch(tmp78, &block28, std::vector<Node*>{}, &block29, std::vector<Node*>{});
  }

  if (block35.is_used()) {
    ca_.Bind(&block35);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(a.objects[0], threeTwoOne)' failed", "../../deps/v8/test/torque/test-torque.tq", 869);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    ca_.Goto(&block37);
  }

    ca_.Bind(&block37);
}

TNode<Oddball> TestSliceEnumeration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block51(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<FixedArray> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    tmp1 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT>{tmp0});
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp2);
  }

  TNode<IntPtrT> phi_bb4_2;
  TNode<IntPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_2);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    tmp4 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb4_2}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<Node*>{phi_bb4_2}, &block3, std::vector<Node*>{phi_bb4_2});
  }

  TNode<IntPtrT> phi_bb2_2;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<UintPtrT> tmp10;
  TNode<UintPtrT> tmp11;
  TNode<BoolT> tmp12;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_2);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp7});
    tmp9 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp8});
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb2_2});
    tmp11 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp9});
    tmp12 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp10}, TNode<UintPtrT>{tmp11});
    ca_.Branch(tmp12, &block12, std::vector<Node*>{phi_bb2_2, phi_bb2_2, phi_bb2_2, phi_bb2_2, phi_bb2_2}, &block13, std::vector<Node*>{phi_bb2_2, phi_bb2_2, phi_bb2_2, phi_bb2_2, phi_bb2_2});
  }

  TNode<IntPtrT> phi_bb12_2;
  TNode<IntPtrT> phi_bb12_7;
  TNode<IntPtrT> phi_bb12_8;
  TNode<IntPtrT> phi_bb12_12;
  TNode<IntPtrT> phi_bb12_13;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<HeapObject> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Object> tmp18;
  TNode<Smi> tmp19;
  TNode<Smi> tmp20;
  TNode<BoolT> tmp21;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_2, &phi_bb12_7, &phi_bb12_8, &phi_bb12_12, &phi_bb12_13);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp14 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{phi_bb12_13}, TNode<IntPtrT>{tmp13});
    tmp15 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp14});
    std::tie(tmp16, tmp17) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{tmp15}).Flatten();
    tmp18 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp16, tmp17});
    tmp19 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp18});
    tmp20 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp21 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp19}, TNode<Smi>{tmp20});
    ca_.Branch(tmp21, &block6, std::vector<Node*>{phi_bb12_2}, &block7, std::vector<Node*>{phi_bb12_2});
  }

  TNode<IntPtrT> phi_bb13_2;
  TNode<IntPtrT> phi_bb13_7;
  TNode<IntPtrT> phi_bb13_8;
  TNode<IntPtrT> phi_bb13_12;
  TNode<IntPtrT> phi_bb13_13;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_7, &phi_bb13_8, &phi_bb13_12, &phi_bb13_13);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb7_2;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_2);
    CodeStubAssembler(state_).FailAssert("Torque assert 'UnsafeCast<Smi>(fixedArray.objects[i]) == 0' failed", "../../deps/v8/test/torque/test-torque.tq", 884);
  }

  TNode<IntPtrT> phi_bb6_2;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<Smi> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<UintPtrT> tmp27;
  TNode<UintPtrT> tmp28;
  TNode<BoolT> tmp29;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_2);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp25 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp24});
    tmp26 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp25});
    tmp27 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb6_2});
    tmp28 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp26});
    tmp29 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp27}, TNode<UintPtrT>{tmp28});
    ca_.Branch(tmp29, &block19, std::vector<Node*>{phi_bb6_2, phi_bb6_2, phi_bb6_2, phi_bb6_2, phi_bb6_2}, &block20, std::vector<Node*>{phi_bb6_2, phi_bb6_2, phi_bb6_2, phi_bb6_2, phi_bb6_2});
  }

  TNode<IntPtrT> phi_bb19_2;
  TNode<IntPtrT> phi_bb19_7;
  TNode<IntPtrT> phi_bb19_8;
  TNode<IntPtrT> phi_bb19_12;
  TNode<IntPtrT> phi_bb19_13;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<HeapObject> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<Smi> tmp35;
  TNode<Smi> tmp36;
  TNode<Smi> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<IntPtrT> tmp39;
  if (block19.is_used()) {
    ca_.Bind(&block19, &phi_bb19_2, &phi_bb19_7, &phi_bb19_8, &phi_bb19_12, &phi_bb19_13);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp31 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{phi_bb19_13}, TNode<IntPtrT>{tmp30});
    tmp32 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp31});
    std::tie(tmp33, tmp34) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{tmp32}).Flatten();
    tmp35 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{phi_bb19_2});
    tmp36 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp37 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp35}, TNode<Smi>{tmp36});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp33, tmp34}, tmp37);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp39 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb19_2}, TNode<IntPtrT>{tmp38});
    ca_.Goto(&block4, tmp39);
  }

  TNode<IntPtrT> phi_bb20_2;
  TNode<IntPtrT> phi_bb20_7;
  TNode<IntPtrT> phi_bb20_8;
  TNode<IntPtrT> phi_bb20_12;
  TNode<IntPtrT> phi_bb20_13;
  if (block20.is_used()) {
    ca_.Bind(&block20, &phi_bb20_2, &phi_bb20_7, &phi_bb20_8, &phi_bb20_12, &phi_bb20_13);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb3_2;
  TNode<IntPtrT> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<Smi> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<IntPtrT> tmp45;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_2);
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp41 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp43 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp42});
    tmp44 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp43});
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block24, tmp45);
  }

  TNode<IntPtrT> phi_bb24_5;
  TNode<BoolT> tmp46;
  if (block24.is_used()) {
    ca_.Bind(&block24, &phi_bb24_5);
    tmp46 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{phi_bb24_5}, TNode<IntPtrT>{tmp44});
    ca_.Branch(tmp46, &block22, std::vector<Node*>{phi_bb24_5}, &block23, std::vector<Node*>{phi_bb24_5});
  }

  TNode<IntPtrT> phi_bb22_5;
  TNode<UintPtrT> tmp47;
  TNode<UintPtrT> tmp48;
  TNode<BoolT> tmp49;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_5);
    tmp47 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{phi_bb22_5});
    tmp48 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp44});
    tmp49 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp47}, TNode<UintPtrT>{tmp48});
    ca_.Branch(tmp49, &block29, std::vector<Node*>{phi_bb22_5, phi_bb22_5, phi_bb22_5}, &block30, std::vector<Node*>{phi_bb22_5, phi_bb22_5, phi_bb22_5});
  }

  TNode<IntPtrT> phi_bb29_5;
  TNode<IntPtrT> phi_bb29_6;
  TNode<IntPtrT> phi_bb29_7;
  TNode<IntPtrT> tmp50;
  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<HeapObject> tmp53;
  TNode<IntPtrT> tmp54;
  TNode<Object> tmp55;
  TNode<Smi> tmp56;
  TNode<Smi> tmp57;
  TNode<Smi> tmp58;
  TNode<Smi> tmp59;
  TNode<BoolT> tmp60;
  if (block29.is_used()) {
    ca_.Bind(&block29, &phi_bb29_5, &phi_bb29_6, &phi_bb29_7);
    tmp50 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp51 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{phi_bb29_7}, TNode<IntPtrT>{tmp50});
    tmp52 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp40}, TNode<IntPtrT>{tmp51});
    std::tie(tmp53, tmp54) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{tmp52}).Flatten();
    tmp55 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp53, tmp54});
    tmp56 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp55});
    tmp57 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{phi_bb29_5});
    tmp58 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp59 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp57}, TNode<Smi>{tmp58});
    tmp60 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp56}, TNode<Smi>{tmp59});
    ca_.Branch(tmp60, &block32, std::vector<Node*>{phi_bb29_5}, &block33, std::vector<Node*>{phi_bb29_5});
  }

  TNode<IntPtrT> phi_bb30_5;
  TNode<IntPtrT> phi_bb30_6;
  TNode<IntPtrT> phi_bb30_7;
  if (block30.is_used()) {
    ca_.Bind(&block30, &phi_bb30_5, &phi_bb30_6, &phi_bb30_7);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> phi_bb33_5;
  if (block33.is_used()) {
    ca_.Bind(&block33, &phi_bb33_5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'value == Convert<Smi>(i) + 3' failed", "../../deps/v8/test/torque/test-torque.tq", 892);
  }

  TNode<IntPtrT> phi_bb32_5;
  TNode<Smi> tmp61;
  TNode<Smi> tmp62;
  TNode<IntPtrT> tmp63;
  TNode<IntPtrT> tmp64;
  if (block32.is_used()) {
    ca_.Bind(&block32, &phi_bb32_5);
    tmp61 = FromConstexpr_Smi_constexpr_int31_0(state_, 4);
    tmp62 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp56}, TNode<Smi>{tmp61});
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp53, tmp54}, tmp62);
    tmp63 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp64 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb32_5}, TNode<IntPtrT>{tmp63});
    ca_.Goto(&block24, tmp64);
  }

  TNode<IntPtrT> phi_bb23_5;
  TNode<IntPtrT> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<IntPtrT> tmp67;
  TNode<Smi> tmp68;
  if (block23.is_used()) {
    ca_.Bind(&block23, &phi_bb23_5);
    tmp65 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp66 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp44}, TNode<IntPtrT>{tmp65});
    tmp67 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp40}, TNode<IntPtrT>{tmp66});
    tmp68 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block37, tmp40, tmp68);
  }

  TNode<IntPtrT> phi_bb37_6;
  TNode<Smi> phi_bb37_8;
  TNode<BoolT> tmp69;
  if (block37.is_used()) {
    ca_.Bind(&block37, &phi_bb37_6, &phi_bb37_8);
    tmp69 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp69, &block35, std::vector<Node*>{phi_bb37_6, phi_bb37_8}, &block36, std::vector<Node*>{phi_bb37_6, phi_bb37_8});
  }

  TNode<IntPtrT> phi_bb35_6;
  TNode<Smi> phi_bb35_8;
  TNode<BoolT> tmp70;
  if (block35.is_used()) {
    ca_.Bind(&block35, &phi_bb35_6, &phi_bb35_8);
    tmp70 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb35_6}, TNode<IntPtrT>{tmp67});
    ca_.Branch(tmp70, &block42, std::vector<Node*>{phi_bb35_6, phi_bb35_8}, &block43, std::vector<Node*>{phi_bb35_6, phi_bb35_8});
  }

  TNode<IntPtrT> phi_bb42_6;
  TNode<Smi> phi_bb42_8;
  if (block42.is_used()) {
    ca_.Bind(&block42, &phi_bb42_6, &phi_bb42_8);
    ca_.Goto(&block36, phi_bb42_6, phi_bb42_8);
  }

  TNode<IntPtrT> phi_bb43_6;
  TNode<Smi> phi_bb43_8;
  TNode<HeapObject> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<IntPtrT> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<Object> tmp75;
  TNode<Smi> tmp76;
  TNode<Smi> tmp77;
  TNode<Smi> tmp78;
  TNode<BoolT> tmp79;
  if (block43.is_used()) {
    ca_.Bind(&block43, &phi_bb43_6, &phi_bb43_8);
    std::tie(tmp71, tmp72) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{phi_bb43_6}).Flatten();
    tmp73 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp74 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb43_6}, TNode<IntPtrT>{tmp73});
    tmp75 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp71, tmp72});
    tmp76 = UnsafeCast_Smi_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp75});
    tmp77 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    tmp78 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb43_8}, TNode<Smi>{tmp77});
    tmp79 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp76}, TNode<Smi>{tmp78});
    ca_.Branch(tmp79, &block46, std::vector<Node*>{phi_bb43_8}, &block47, std::vector<Node*>{phi_bb43_8});
  }

  TNode<Smi> phi_bb47_8;
  if (block47.is_used()) {
    ca_.Bind(&block47, &phi_bb47_8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'value == count + 7' failed", "../../deps/v8/test/torque/test-torque.tq", 900);
  }

  TNode<Smi> phi_bb46_8;
  TNode<Smi> tmp80;
  TNode<Smi> tmp81;
  if (block46.is_used()) {
    ca_.Bind(&block46, &phi_bb46_8);
    tmp80 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp81 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb46_8}, TNode<Smi>{tmp80});
    ca_.Goto(&block37, tmp74, tmp81);
  }

  TNode<IntPtrT> phi_bb36_6;
  TNode<Smi> phi_bb36_8;
  TNode<Smi> tmp82;
  TNode<BoolT> tmp83;
  if (block36.is_used()) {
    ca_.Bind(&block36, &phi_bb36_6, &phi_bb36_8);
    tmp82 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp83 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb36_8}, TNode<Smi>{tmp82});
    ca_.Branch(tmp83, &block48, std::vector<Node*>{phi_bb36_6, phi_bb36_8}, &block49, std::vector<Node*>{phi_bb36_6, phi_bb36_8});
  }

  TNode<IntPtrT> phi_bb49_6;
  TNode<Smi> phi_bb49_8;
  if (block49.is_used()) {
    ca_.Bind(&block49, &phi_bb49_6, &phi_bb49_8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'count == 3' failed", "../../deps/v8/test/torque/test-torque.tq", 903);
  }

  TNode<IntPtrT> phi_bb48_6;
  TNode<Smi> phi_bb48_8;
  TNode<BoolT> tmp84;
  if (block48.is_used()) {
    ca_.Bind(&block48, &phi_bb48_6, &phi_bb48_8);
    tmp84 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb48_6}, TNode<IntPtrT>{tmp67});
    ca_.Branch(tmp84, &block50, std::vector<Node*>{phi_bb48_6, phi_bb48_8}, &block51, std::vector<Node*>{phi_bb48_6, phi_bb48_8});
  }

  TNode<IntPtrT> phi_bb51_6;
  TNode<Smi> phi_bb51_8;
  if (block51.is_used()) {
    ca_.Bind(&block51, &phi_bb51_6, &phi_bb51_8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'it.Empty()' failed", "../../deps/v8/test/torque/test-torque.tq", 904);
  }

  TNode<IntPtrT> phi_bb50_6;
  TNode<Smi> phi_bb50_8;
  TNode<Oddball> tmp85;
  if (block50.is_used()) {
    ca_.Bind(&block50, &phi_bb50_6, &phi_bb50_8);
    tmp85 = Undefined_0(state_);
    ca_.Goto(&block53);
  }

    ca_.Bind(&block53);
  return TNode<Oddball>{tmp85};
}

void TestStaticAssert_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal((CodeStubAssembler(state_).ConstexprInt31Add(1, 2)), 3)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TF_BUILTIN(NewSmiBox, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Map> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<HeapObject> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Smi> tmp6;
  TNode<SmiBox> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).GetInstanceTypeMap(SMI_BOX_TYPE);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp2 = Allocate_0(state_, TNode<IntPtrT>{tmp1}, TNode<Map>{tmp0});
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp2, tmp3}, tmp0);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp4}, parameter1);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp5}, tmp6);
    tmp7 = TORQUE_CAST(TNode<HeapObject>{tmp2});
    CodeStubAssembler(state_).Return(tmp7);
  }
}

void TestLoadEliminationFixed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<SmiBox> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<Smi> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Smi> tmp7;
  TNode<Smi> tmp8;
  TNode<BoolT> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 123);
    tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, p_context, tmp0));
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp2});
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 999);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp4}, tmp5);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp6});
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp9 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp7}, TNode<Smi>{tmp8});
    ca_.Branch(tmp9, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp10;
  TNode<Smi> tmp11;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp11 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp10});
    ca_.Goto(&block4, tmp11);
  }

  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp12});
    ca_.Goto(&block4, tmp13);
  }

  TNode<Smi> phi_bb4_3;
  TNode<BoolT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<Smi> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<Smi> tmp18;
  TNode<Smi> tmp19;
  TNode<BoolT> tmp20;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_3);
    tmp14 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp3}, TNode<MaybeObject>{phi_bb4_3});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp14});
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp16 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp15}, tmp16);
    tmp17 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp18 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp17});
    tmp19 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    tmp20 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp18}, TNode<MaybeObject>{tmp19});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp20});
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestLoadEliminationVariable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<FixedArray> tmp1;
  TNode<Smi> tmp2;
  TNode<SmiBox> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<Smi> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<Smi> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<UintPtrT> tmp12;
  TNode<UintPtrT> tmp13;
  TNode<BoolT> tmp14;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kEmptyFixedArray_0(state_);
    tmp1 = UnsafeCast_FixedArray_0(state_, TNode<Context>{p_context}, TNode<Object>{tmp0});
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, p_context, tmp2));
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp6});
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp10 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp9});
    tmp11 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp10});
    tmp12 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp11});
    tmp13 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    tmp14 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp12}, TNode<UintPtrT>{tmp13});
    ca_.Branch(tmp14, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<IntPtrT> tmp17;
  TNode<HeapObject> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<Object> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<Smi> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Smi> tmp27;
  TNode<Smi> tmp28;
  TNode<Smi> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<UintPtrT> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<BoolT> tmp33;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp16 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp11}, TNode<IntPtrT>{tmp15});
    tmp17 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp16});
    std::tie(tmp18, tmp19) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{tmp17}).Flatten();
    tmp20 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp18, tmp19});
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp24 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp23});
    tmp25 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp24});
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp27 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp26});
    tmp28 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    tmp29 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp27}, TNode<Smi>{tmp28});
    tmp30 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp29});
    tmp31 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp30});
    tmp32 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp25});
    tmp33 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp31}, TNode<UintPtrT>{tmp32});
    ca_.Branch(tmp33, &block13, std::vector<Node*>{}, &block14, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<IntPtrT> tmp36;
  TNode<HeapObject> tmp37;
  TNode<IntPtrT> tmp38;
  TNode<Object> tmp39;
  TNode<IntPtrT> tmp40;
  TNode<IntPtrT> tmp41;
  TNode<IntPtrT> tmp42;
  TNode<Smi> tmp43;
  TNode<IntPtrT> tmp44;
  TNode<IntPtrT> tmp45;
  TNode<Smi> tmp46;
  TNode<IntPtrT> tmp47;
  TNode<UintPtrT> tmp48;
  TNode<UintPtrT> tmp49;
  TNode<BoolT> tmp50;
  if (block13.is_used()) {
    ca_.Bind(&block13);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp35 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp34});
    tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp35});
    std::tie(tmp37, tmp38) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{tmp36}).Flatten();
    tmp39 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp37, tmp38});
    tmp40 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp41 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp42 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp43 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp42});
    tmp44 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp43});
    tmp45 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp46 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp45});
    tmp47 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp46});
    tmp48 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp47});
    tmp49 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp44});
    tmp50 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp48}, TNode<UintPtrT>{tmp49});
    ca_.Branch(tmp50, &block20, std::vector<Node*>{}, &block21, std::vector<Node*>{});
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp51;
  TNode<IntPtrT> tmp52;
  TNode<IntPtrT> tmp53;
  TNode<HeapObject> tmp54;
  TNode<IntPtrT> tmp55;
  TNode<Object> tmp56;
  TNode<IntPtrT> tmp57;
  TNode<IntPtrT> tmp58;
  TNode<IntPtrT> tmp59;
  TNode<Smi> tmp60;
  TNode<IntPtrT> tmp61;
  TNode<IntPtrT> tmp62;
  TNode<Smi> tmp63;
  TNode<Smi> tmp64;
  TNode<Smi> tmp65;
  TNode<IntPtrT> tmp66;
  TNode<UintPtrT> tmp67;
  TNode<UintPtrT> tmp68;
  TNode<BoolT> tmp69;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp52 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp47}, TNode<IntPtrT>{tmp51});
    tmp53 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp40}, TNode<IntPtrT>{tmp52});
    std::tie(tmp54, tmp55) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{tmp53}).Flatten();
    tmp56 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp54, tmp55});
    tmp57 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp58 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp59 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp60 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp59});
    tmp61 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp60});
    tmp62 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp63 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp62});
    tmp64 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    tmp65 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp63}, TNode<Smi>{tmp64});
    tmp66 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp65});
    tmp67 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp66});
    tmp68 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp61});
    tmp69 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp67}, TNode<UintPtrT>{tmp68});
    ca_.Branch(tmp69, &block27, std::vector<Node*>{}, &block28, std::vector<Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<IntPtrT> tmp70;
  TNode<IntPtrT> tmp71;
  TNode<IntPtrT> tmp72;
  TNode<HeapObject> tmp73;
  TNode<IntPtrT> tmp74;
  TNode<Object> tmp75;
  TNode<BoolT> tmp76;
  TNode<BoolT> tmp77;
  if (block27.is_used()) {
    ca_.Bind(&block27);
    tmp70 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp71 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp66}, TNode<IntPtrT>{tmp70});
    tmp72 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp57}, TNode<IntPtrT>{tmp71});
    std::tie(tmp73, tmp74) = NewReference_Object_0(state_, TNode<HeapObject>{tmp1}, TNode<IntPtrT>{tmp72}).Flatten();
    tmp75 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp73, tmp74});
    tmp76 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp20}, TNode<MaybeObject>{tmp56});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp76});
    tmp77 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp39}, TNode<MaybeObject>{tmp75});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp77});
    ca_.Goto(&block30);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block30);
}

TNode<Smi> TestRedundantArrayElementCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kEmptyFixedArray_0(state_);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp1);
  }

  TNode<Smi> phi_bb4_2;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_2);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp2});
    tmp4 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{phi_bb4_2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<Node*>{phi_bb4_2}, &block3, std::vector<Node*>{phi_bb4_2});
  }

  TNode<Smi> phi_bb2_2;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<UintPtrT> tmp11;
  TNode<UintPtrT> tmp12;
  TNode<BoolT> tmp13;
  if (block2.is_used()) {
    ca_.Bind(&block2, &phi_bb2_2);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp7});
    tmp9 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp8});
    tmp10 = Convert_intptr_Smi_0(state_, TNode<Smi>{phi_bb2_2});
    tmp11 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp10});
    tmp12 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp9});
    tmp13 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp11}, TNode<UintPtrT>{tmp12});
    ca_.Branch(tmp13, &block12, std::vector<Node*>{phi_bb2_2, phi_bb2_2, phi_bb2_2}, &block13, std::vector<Node*>{phi_bb2_2, phi_bb2_2, phi_bb2_2});
  }

  TNode<Smi> phi_bb12_2;
  TNode<Smi> phi_bb12_7;
  TNode<Smi> phi_bb12_8;
  TNode<IntPtrT> tmp14;
  TNode<IntPtrT> tmp15;
  TNode<IntPtrT> tmp16;
  TNode<HeapObject> tmp17;
  TNode<IntPtrT> tmp18;
  TNode<Object> tmp19;
  TNode<Oddball> tmp20;
  TNode<BoolT> tmp21;
  if (block12.is_used()) {
    ca_.Bind(&block12, &phi_bb12_2, &phi_bb12_7, &phi_bb12_8);
    tmp14 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp15 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp14});
    tmp16 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp15});
    std::tie(tmp17, tmp18) = NewReference_Object_0(state_, TNode<HeapObject>{tmp0}, TNode<IntPtrT>{tmp16}).Flatten();
    tmp19 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp17, tmp18});
    tmp20 = TheHole_0(state_);
    tmp21 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp19}, TNode<HeapObject>{tmp20});
    ca_.Branch(tmp21, &block6, std::vector<Node*>{phi_bb12_2}, &block7, std::vector<Node*>{phi_bb12_2});
  }

  TNode<Smi> phi_bb13_2;
  TNode<Smi> phi_bb13_7;
  TNode<Smi> phi_bb13_8;
  if (block13.is_used()) {
    ca_.Bind(&block13, &phi_bb13_2, &phi_bb13_7, &phi_bb13_8);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb6_2;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<IntPtrT> tmp24;
  TNode<Smi> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<IntPtrT> tmp27;
  TNode<UintPtrT> tmp28;
  TNode<UintPtrT> tmp29;
  TNode<BoolT> tmp30;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_2);
    tmp22 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp25 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp24});
    tmp26 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp25});
    tmp27 = Convert_intptr_Smi_0(state_, TNode<Smi>{phi_bb6_2});
    tmp28 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp27});
    tmp29 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp26});
    tmp30 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp28}, TNode<UintPtrT>{tmp29});
    ca_.Branch(tmp30, &block21, std::vector<Node*>{phi_bb6_2, phi_bb6_2, phi_bb6_2}, &block22, std::vector<Node*>{phi_bb6_2, phi_bb6_2, phi_bb6_2});
  }

  TNode<Smi> phi_bb21_2;
  TNode<Smi> phi_bb21_7;
  TNode<Smi> phi_bb21_8;
  TNode<IntPtrT> tmp31;
  TNode<IntPtrT> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<HeapObject> tmp34;
  TNode<IntPtrT> tmp35;
  TNode<Object> tmp36;
  TNode<Oddball> tmp37;
  TNode<BoolT> tmp38;
  if (block21.is_used()) {
    ca_.Bind(&block21, &phi_bb21_2, &phi_bb21_7, &phi_bb21_8);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp32 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp27}, TNode<IntPtrT>{tmp31});
    tmp33 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp32});
    std::tie(tmp34, tmp35) = NewReference_Object_0(state_, TNode<HeapObject>{tmp0}, TNode<IntPtrT>{tmp33}).Flatten();
    tmp36 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp34, tmp35});
    tmp37 = TheHole_0(state_);
    tmp38 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp36}, TNode<HeapObject>{tmp37});
    ca_.Branch(tmp38, &block15, std::vector<Node*>{phi_bb21_2}, &block16, std::vector<Node*>{phi_bb21_2});
  }

  TNode<Smi> phi_bb22_2;
  TNode<Smi> phi_bb22_7;
  TNode<Smi> phi_bb22_8;
  if (block22.is_used()) {
    ca_.Bind(&block22, &phi_bb22_2, &phi_bb22_7, &phi_bb22_8);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> phi_bb15_2;
  TNode<Smi> tmp39;
  if (block15.is_used()) {
    ca_.Bind(&block15, &phi_bb15_2);
    tmp39 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp39);
  }

  TNode<Smi> phi_bb16_2;
  TNode<BoolT> tmp40;
  if (block16.is_used()) {
    ca_.Bind(&block16, &phi_bb16_2);
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp40});
    ca_.Goto(&block7, phi_bb16_2);
  }

  TNode<Smi> phi_bb7_2;
  TNode<Smi> tmp41;
  TNode<Smi> tmp42;
  if (block7.is_used()) {
    ca_.Bind(&block7, &phi_bb7_2);
    tmp41 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp42 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb7_2}, TNode<Smi>{tmp41});
    ca_.Goto(&block4, tmp42);
  }

  TNode<Smi> phi_bb3_2;
  TNode<Smi> tmp43;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_2);
    tmp43 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block1, tmp43);
  }

  TNode<Smi> phi_bb1_1;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_1);
    ca_.Goto(&block25, phi_bb1_1);
  }

  TNode<Smi> phi_bb25_1;
    ca_.Bind(&block25, &phi_bb25_1);
  return TNode<Smi>{phi_bb25_1};
}

TNode<Smi> TestRedundantSmiCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<FixedArray> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<Smi> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<UintPtrT> tmp7;
  TNode<UintPtrT> tmp8;
  TNode<BoolT> tmp9;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = kEmptyFixedArray_0(state_);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp3});
    tmp5 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp4});
    tmp6 = Convert_intptr_constexpr_int31_0(state_, 1);
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    tmp9 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp7}, TNode<UintPtrT>{tmp8});
    ca_.Branch(tmp9, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp10;
  TNode<IntPtrT> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<HeapObject> tmp13;
  TNode<IntPtrT> tmp14;
  TNode<Object> tmp15;
  TNode<Smi> tmp16;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp11 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp10});
    tmp12 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp1}, TNode<IntPtrT>{tmp11});
    std::tie(tmp13, tmp14) = NewReference_Object_0(state_, TNode<HeapObject>{tmp0}, TNode<IntPtrT>{tmp12}).Flatten();
    tmp15 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp13, tmp14});
    compiler::CodeAssemblerLabel label17(&ca_);
    tmp16 = Cast_Smi_0(state_, TNode<Object>{tmp15}, &label17);
    ca_.Goto(&block11);
    if (label17.is_used()) {
      ca_.Bind(&label17);
      ca_.Goto(&block12);
    }
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Smi> tmp18;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block1, tmp18);
  }

  TNode<Smi> tmp19;
  if (block11.is_used()) {
    ca_.Bind(&block11);
    compiler::CodeAssemblerLabel label20(&ca_);
    tmp19 = Cast_Smi_0(state_, TNode<Object>{tmp15}, &label20);
    ca_.Goto(&block15);
    if (label20.is_used()) {
      ca_.Bind(&label20);
      ca_.Goto(&block16);
    }
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    VerifiedUnreachable_0(state_);
  }

  TNode<Smi> tmp21;
  if (block15.is_used()) {
    ca_.Bind(&block15);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp21);
  }

  TNode<Smi> phi_bb1_1;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_1);
    ca_.Goto(&block17, phi_bb1_1);
  }

  TNode<Smi> phi_bb17_1;
    ca_.Bind(&block17, &phi_bb17_1);
  return TNode<Smi>{phi_bb17_1};
}

TNode<IntPtrT> TestGenericStruct1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 123);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 123);
    tmp2 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    ca_.Branch(tmp2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'box.value == 123' failed", "../../deps/v8/test/torque/test-torque.tq", 988);
  }

  TNode<IntPtrT> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<BoolT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    tmp4 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp3});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 246);
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'boxbox.value.value == 246' failed", "../../deps/v8/test/torque/test-torque.tq", 990);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<IntPtrT>{tmp4};
}

TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0 TestGenericStruct2_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  TNode<Smi> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<BoolT> tmp4;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    std::tie(tmp2, tmp3) = TupleSwap_intptr_Smi_0(state_, TorqueStructTestTuple_intptr_Smi_0{TNode<IntPtrT>{tmp0}, TNode<Smi>{tmp1}}).Flatten();
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'intptrAndSmi.fst == smiAndIntptr.snd' failed", "../../deps/v8/test/torque/test-torque.tq", 1009);
  }

  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp5 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    ca_.Branch(tmp5, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'intptrAndSmi.snd == smiAndIntptr.fst' failed", "../../deps/v8/test/torque/test-torque.tq", 1010);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0{TorqueStructTestTuple_intptr_Smi_0{TNode<IntPtrT>{tmp0}, TNode<Smi>{tmp1}}, TorqueStructTestTuple_Smi_intptr_0{TNode<Smi>{tmp2}, TNode<IntPtrT>{tmp3}}};
}

TNode<BoolT> BranchAndWriteResult_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x, TNode<SmiBox> p_box) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    tmp1 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{p_x}, TNode<Smi>{tmp0});
    ca_.Branch(tmp1, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  TNode<BoolT> tmp2;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp2);
  }

  TNode<Smi> tmp3;
  TNode<BoolT> tmp4;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp4 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{p_x}, TNode<Smi>{tmp3});
    ca_.Goto(&block6, tmp4);
  }

  TNode<BoolT> phi_bb6_3;
  if (block6.is_used()) {
    ca_.Bind(&block6, &phi_bb6_3);
    ca_.Branch(phi_bb6_3, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp5;
  TNode<Smi> tmp6;
  TNode<BoolT> tmp7;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_box, tmp5}, tmp6);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7);
  }

  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<BoolT> tmp10;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_box, tmp8}, tmp9);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp10);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
  return TNode<BoolT>{phi_bb1_2};
}

void TestBranchOnBoolOptimization_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_input) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<SmiBox> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp1 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, p_context, tmp0));
    tmp2 = BranchAndWriteResult_0(state_, TNode<Smi>{p_input}, TNode<SmiBox>{tmp1});
    ca_.Branch(tmp2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp3;
  TNode<Smi> tmp4;
  TNode<Smi> tmp5;
  TNode<BoolT> tmp6;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp3});
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp4}, TNode<Smi>{tmp5});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp6});
    ca_.Goto(&block4);
  }

  TNode<IntPtrT> tmp7;
  TNode<Smi> tmp8;
  TNode<Smi> tmp9;
  TNode<BoolT> tmp10;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp7});
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    tmp10 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp8}, TNode<Smi>{tmp9});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp10});
    ca_.Goto(&block4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
}

void TestBitFieldLoad_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_val, TNode<BoolT> p_expectedA, TNode<Uint16T> p_expectedB, TNode<Uint32T> p_expectedC, TNode<BoolT> p_expectedD) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<BoolT> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 0, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp1 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp0}, TNode<BoolT>{p_expectedA});
    ca_.Branch(tmp1, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.a == expectedA' failed", "../../deps/v8/test/torque/test-torque.tq", 1049);
  }

  TNode<Uint16T> tmp2;
  TNode<BoolT> tmp3;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp2 = ca_.UncheckedCast<Uint16T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint16_t, 1, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp3 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp2}, TNode<Uint32T>{p_expectedB});
    ca_.Branch(tmp3, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.b == expectedB' failed", "../../deps/v8/test/torque/test-torque.tq", 1050);
  }

  TNode<Uint32T> tmp4;
  TNode<BoolT> tmp5;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp4 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 4, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp5 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp4}, TNode<Uint32T>{p_expectedC});
    ca_.Branch(tmp5, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.c == expectedC' failed", "../../deps/v8/test/torque/test-torque.tq", 1051);
  }

  TNode<BoolT> tmp6;
  TNode<BoolT> tmp7;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp6 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 7, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp7 = CodeStubAssembler(state_).Word32Equal(TNode<BoolT>{tmp6}, TNode<BoolT>{p_expectedD});
    ca_.Branch(tmp7, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val.d == expectedD' failed", "../../deps/v8/test/torque/test-torque.tq", 1052);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

void TestBitFieldStore_0(compiler::CodeAssemblerState* state_, TNode<Uint8T> p_val) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<BoolT> tmp0;
  TNode<Uint16T> tmp1;
  TNode<Uint32T> tmp2;
  TNode<BoolT> tmp3;
  TNode<BoolT> tmp4;
  TNode<Uint8T> tmp5;
  TNode<BoolT> tmp6;
  TNode<Uint32T> tmp7;
  TNode<Int32T> tmp8;
  TNode<Int32T> tmp9;
  TNode<Int32T> tmp10;
  TNode<Uint32T> tmp11;
  TNode<Uint8T> tmp12;
  TNode<BoolT> tmp13;
  TNode<Uint16T> tmp14;
  TNode<Uint32T> tmp15;
  TNode<BoolT> tmp16;
  TNode<Uint8T> tmp17;
  TNode<BoolT> tmp18;
  TNode<BoolT> tmp19;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 0, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp1 = ca_.UncheckedCast<Uint16T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint16_t, 1, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp2 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 4, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp3 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32<base::BitField<bool, 7, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val)));
    tmp4 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    tmp5 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 0, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(p_val), ca_.UncheckedCast<Uint32T>(tmp4)));
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    TestBitFieldLoad_0(state_, TNode<Uint8T>{tmp5}, TNode<BoolT>{tmp6}, TNode<Uint16T>{tmp1}, TNode<Uint32T>{tmp2}, TNode<BoolT>{tmp3});
    tmp7 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 4, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp5)));
    tmp8 = CodeStubAssembler(state_).Signed(TNode<Uint32T>{tmp7});
    tmp9 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    tmp10 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp8});
    tmp11 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp10});
    tmp12 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<uint32_t, 4, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp5), ca_.UncheckedCast<Uint32T>(tmp11)));
    tmp13 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    TestBitFieldLoad_0(state_, TNode<Uint8T>{tmp12}, TNode<BoolT>{tmp13}, TNode<Uint16T>{tmp1}, TNode<Uint32T>{tmp11}, TNode<BoolT>{tmp3});
    tmp14 = ca_.UncheckedCast<Uint16T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint16_t, 1, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp12)));
    tmp15 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32<base::BitField<uint32_t, 4, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp12)));
    tmp16 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp14}, TNode<Uint32T>{tmp15});
    tmp17 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 7, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp12), ca_.UncheckedCast<Uint32T>(tmp16)));
    tmp18 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp0});
    tmp19 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp1}, TNode<Uint32T>{tmp11});
    TestBitFieldLoad_0(state_, TNode<Uint8T>{tmp17}, TNode<BoolT>{tmp18}, TNode<Uint16T>{tmp1}, TNode<Uint32T>{tmp11}, TNode<BoolT>{tmp19});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void TestBitFieldInit_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_a, TNode<Uint16T> p_b, TNode<Uint32T> p_c, TNode<BoolT> p_d) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Int32T> tmp0;
  TNode<Uint32T> tmp1;
  TNode<Uint8T> tmp2;
  TNode<Uint8T> tmp3;
  TNode<Uint8T> tmp4;
  TNode<Uint8T> tmp5;
  TNode<Uint8T> tmp6;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_int32_constexpr_int32_0(state_, 0);
    tmp1 = CodeStubAssembler(state_).Unsigned(TNode<Int32T>{tmp0});
    tmp2 = ca_.UncheckedCast<Uint8T>(TNode<Uint32T>{tmp1});
    tmp3 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 0, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp2), ca_.UncheckedCast<Uint32T>(p_a), true));
    tmp4 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<uint16_t, 1, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp3), ca_.UncheckedCast<Uint32T>(p_b), true));
    tmp5 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<uint32_t, 4, 3, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp4), ca_.UncheckedCast<Uint32T>(p_c), true));
    tmp6 = ca_.UncheckedCast<Uint8T>(CodeStubAssembler(state_).UpdateWord32<base::BitField<bool, 7, 1, uint8_t>>(ca_.UncheckedCast<Word32T>(tmp5), ca_.UncheckedCast<Uint32T>(p_d), true));
    TestBitFieldLoad_0(state_, TNode<Uint8T>{tmp6}, TNode<BoolT>{p_a}, TNode<Uint16T>{p_b}, TNode<Uint32T>{p_c}, TNode<BoolT>{p_d});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void TestBitFieldUintptrOps_0(compiler::CodeAssemblerState* state_, TNode<Uint32T> p_val2, TNode<UintPtrT> p_val3) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<UintPtrT> tmp0;
  TNode<UintPtrT> tmp1;
  TNode<BoolT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<base::BitField<uintptr_t, 0, 5, uint32_t>>(ca_.UncheckedCast<Word32T>(p_val2)));
    tmp1 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    tmp2 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp0}, TNode<UintPtrT>{tmp1});
    ca_.Branch(tmp2, &block2, std::vector<Node*>{}, &block3, std::vector<Node*>{});
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.a == 3' failed", "../../deps/v8/test/torque/test-torque.tq", 1100);
  }

  TNode<UintPtrT> tmp3;
  TNode<UintPtrT> tmp4;
  TNode<BoolT> tmp5;
  if (block2.is_used()) {
    ca_.Bind(&block2);
    tmp3 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<base::BitField<uintptr_t, 5, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(p_val2)));
    tmp4 = FromConstexpr_uintptr_constexpr_int31_0(state_, 61);
    tmp5 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp3}, TNode<UintPtrT>{tmp4});
    ca_.Branch(tmp5, &block4, std::vector<Node*>{}, &block5, std::vector<Node*>{});
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.b == 61' failed", "../../deps/v8/test/torque/test-torque.tq", 1101);
  }

  TNode<BoolT> tmp6;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp6 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 0, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(p_val3)));
    ca_.Branch(tmp6, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.c' failed", "../../deps/v8/test/torque/test-torque.tq", 1102);
  }

  TNode<Uint32T> tmp7;
  TNode<Uint32T> tmp8;
  TNode<BoolT> tmp9;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp7 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<uint32_t, 1, 9, uintptr_t>>(ca_.UncheckedCast<WordT>(p_val3)));
    tmp8 = FromConstexpr_uint32_constexpr_int31_0(state_, 500);
    tmp9 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp7}, TNode<Uint32T>{tmp8});
    ca_.Branch(tmp9, &block8, std::vector<Node*>{}, &block9, std::vector<Node*>{});
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.d == 500' failed", "../../deps/v8/test/torque/test-torque.tq", 1103);
  }

  TNode<UintPtrT> tmp10;
  TNode<UintPtrT> tmp11;
  TNode<BoolT> tmp12;
  if (block8.is_used()) {
    ca_.Bind(&block8);
    tmp10 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWord<base::BitField<uintptr_t, 10, 17, uintptr_t>>(ca_.UncheckedCast<WordT>(p_val3)));
    tmp11 = FromConstexpr_uintptr_constexpr_int31_0(state_, 460);
    tmp12 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp10}, TNode<UintPtrT>{tmp11});
    ca_.Branch(tmp12, &block10, std::vector<Node*>{}, &block11, std::vector<Node*>{});
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.e == 0x1cc' failed", "../../deps/v8/test/torque/test-torque.tq", 1104);
  }

  TNode<UintPtrT> tmp13;
  TNode<Uint32T> tmp14;
  TNode<UintPtrT> tmp15;
  TNode<UintPtrT> tmp16;
  TNode<BoolT> tmp17;
  if (block10.is_used()) {
    ca_.Bind(&block10);
    tmp13 = FromConstexpr_uintptr_constexpr_int31_0(state_, 16);
    tmp14 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWordInWord32<base::BitField<uintptr_t, 5, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(p_val2), ca_.UncheckedCast<UintPtrT>(tmp13)));
    tmp15 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<base::BitField<uintptr_t, 0, 5, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp14)));
    tmp16 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    tmp17 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp15}, TNode<UintPtrT>{tmp16});
    ca_.Branch(tmp17, &block12, std::vector<Node*>{}, &block13, std::vector<Node*>{});
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.a == 3' failed", "../../deps/v8/test/torque/test-torque.tq", 1107);
  }

  TNode<UintPtrT> tmp18;
  TNode<UintPtrT> tmp19;
  TNode<BoolT> tmp20;
  if (block12.is_used()) {
    ca_.Bind(&block12);
    tmp18 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<base::BitField<uintptr_t, 5, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp14)));
    tmp19 = FromConstexpr_uintptr_constexpr_int31_0(state_, 16);
    tmp20 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp19});
    ca_.Branch(tmp20, &block14, std::vector<Node*>{}, &block15, std::vector<Node*>{});
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.b == 16' failed", "../../deps/v8/test/torque/test-torque.tq", 1108);
  }

  TNode<UintPtrT> tmp21;
  TNode<UintPtrT> tmp22;
  TNode<UintPtrT> tmp23;
  TNode<Uint32T> tmp24;
  TNode<UintPtrT> tmp25;
  TNode<UintPtrT> tmp26;
  TNode<BoolT> tmp27;
  if (block14.is_used()) {
    ca_.Bind(&block14);
    tmp21 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<base::BitField<uintptr_t, 5, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp14)));
    tmp22 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    tmp23 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp21}, TNode<UintPtrT>{tmp22});
    tmp24 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).UpdateWordInWord32<base::BitField<uintptr_t, 5, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp14), ca_.UncheckedCast<UintPtrT>(tmp23)));
    tmp25 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<base::BitField<uintptr_t, 0, 5, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp24)));
    tmp26 = FromConstexpr_uintptr_constexpr_int31_0(state_, 3);
    tmp27 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp25}, TNode<UintPtrT>{tmp26});
    ca_.Branch(tmp27, &block16, std::vector<Node*>{}, &block17, std::vector<Node*>{});
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.a == 3' failed", "../../deps/v8/test/torque/test-torque.tq", 1111);
  }

  TNode<UintPtrT> tmp28;
  TNode<UintPtrT> tmp29;
  TNode<BoolT> tmp30;
  if (block16.is_used()) {
    ca_.Bind(&block16);
    tmp28 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWordFromWord32<base::BitField<uintptr_t, 5, 6, uint32_t>>(ca_.UncheckedCast<Word32T>(tmp24)));
    tmp29 = FromConstexpr_uintptr_constexpr_int31_0(state_, 17);
    tmp30 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp28}, TNode<UintPtrT>{tmp29});
    ca_.Branch(tmp30, &block18, std::vector<Node*>{}, &block19, std::vector<Node*>{});
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val2.b == 17' failed", "../../deps/v8/test/torque/test-torque.tq", 1112);
  }

  TNode<Uint32T> tmp31;
  TNode<UintPtrT> tmp32;
  TNode<UintPtrT> tmp33;
  TNode<UintPtrT> tmp34;
  TNode<BoolT> tmp35;
  if (block18.is_used()) {
    ca_.Bind(&block18);
    tmp31 = FromConstexpr_uint32_constexpr_int31_0(state_, 99);
    tmp32 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).UpdateWord32InWord<base::BitField<uint32_t, 1, 9, uintptr_t>>(ca_.UncheckedCast<WordT>(p_val3), ca_.UncheckedCast<Uint32T>(tmp31)));
    tmp33 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1234);
    tmp34 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).UpdateWord<base::BitField<uintptr_t, 10, 17, uintptr_t>>(ca_.UncheckedCast<WordT>(tmp32), ca_.UncheckedCast<UintPtrT>(tmp33)));
    tmp35 = ca_.UncheckedCast<BoolT>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<bool, 0, 1, uintptr_t>>(ca_.UncheckedCast<WordT>(tmp34)));
    ca_.Branch(tmp35, &block20, std::vector<Node*>{}, &block21, std::vector<Node*>{});
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.c' failed", "../../deps/v8/test/torque/test-torque.tq", 1116);
  }

  TNode<Uint32T> tmp36;
  TNode<Uint32T> tmp37;
  TNode<BoolT> tmp38;
  if (block20.is_used()) {
    ca_.Bind(&block20);
    tmp36 = ca_.UncheckedCast<Uint32T>(CodeStubAssembler(state_).DecodeWord32FromWord<base::BitField<uint32_t, 1, 9, uintptr_t>>(ca_.UncheckedCast<WordT>(tmp34)));
    tmp37 = FromConstexpr_uint32_constexpr_int31_0(state_, 99);
    tmp38 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp36}, TNode<Uint32T>{tmp37});
    ca_.Branch(tmp38, &block22, std::vector<Node*>{}, &block23, std::vector<Node*>{});
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.d == 99' failed", "../../deps/v8/test/torque/test-torque.tq", 1117);
  }

  TNode<UintPtrT> tmp39;
  TNode<UintPtrT> tmp40;
  TNode<BoolT> tmp41;
  if (block22.is_used()) {
    ca_.Bind(&block22);
    tmp39 = ca_.UncheckedCast<UintPtrT>(CodeStubAssembler(state_).DecodeWord<base::BitField<uintptr_t, 10, 17, uintptr_t>>(ca_.UncheckedCast<WordT>(tmp34)));
    tmp40 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1234);
    tmp41 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp39}, TNode<UintPtrT>{tmp40});
    ca_.Branch(tmp41, &block24, std::vector<Node*>{}, &block25, std::vector<Node*>{});
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    CodeStubAssembler(state_).FailAssert("Torque assert 'val3.e == 1234' failed", "../../deps/v8/test/torque/test-torque.tq", 1118);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    ca_.Goto(&block26);
  }

    ca_.Bind(&block26);
}

void TestFullyGeneratedClassWithElements_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block166(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Oddball> tmp1;
  TNode<Smi> tmp2;
  TNode<Map> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<HeapObject> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Smi> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<InternalClassWithSmiElements> tmp14;
  TNode<Oddball> tmp15;
  TNode<Smi> tmp16;
  TNode<Smi> tmp17;
  TNode<Map> tmp18;
  TNode<IntPtrT> tmp19;
  TNode<IntPtrT> tmp20;
  TNode<IntPtrT> tmp21;
  TNode<IntPtrT> tmp22;
  TNode<IntPtrT> tmp23;
  TNode<HeapObject> tmp24;
  TNode<IntPtrT> tmp25;
  TNode<IntPtrT> tmp26;
  TNode<Int32T> tmp27;
  TNode<IntPtrT> tmp28;
  TNode<Int32T> tmp29;
  TNode<IntPtrT> tmp30;
  TNode<IntPtrT> tmp31;
  TNode<Smi> tmp32;
  TNode<IntPtrT> tmp33;
  TNode<IntPtrT> tmp34;
  TNode<InternalClassWithStructElements> tmp35;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Convert_Smi_constexpr_int31_0(state_, 3);
    tmp1 = Undefined_0(state_);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    tmp3 = CodeStubAssembler(state_).GetInstanceTypeMap(INTERNAL_CLASS_WITH_SMI_ELEMENTS_TYPE);
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp0});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp6 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp4}, kTaggedSize);
    tmp7 = Allocate_0(state_, TNode<IntPtrT>{tmp6}, TNode<Map>{tmp3});
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp7, tmp8}, tmp3);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp9}, tmp0);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp10}, tmp11);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Oddball>(CodeStubAssembler::Reference{tmp7, tmp12}, tmp1);
    tmp13 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    InitializeFieldsFromIterator_Smi_SmiGeneratorIterator_0(state_, TorqueStructSlice_Smi_0{TNode<HeapObject>{tmp7}, TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp4}, TorqueStructUnsafe_0{}}, TorqueStructSmiGeneratorIterator_0{TNode<Smi>{tmp2}});
    tmp14 = TORQUE_CAST(TNode<HeapObject>{tmp7});
    tmp15 = Undefined_0(state_);
    tmp16 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp18 = CodeStubAssembler(state_).GetInstanceTypeMap(INTERNAL_CLASS_WITH_STRUCT_ELEMENTS_TYPE);
    tmp19 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp0});
    tmp20 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp21 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp19}, kTaggedSize);
    tmp22 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp0});
    tmp23 = AddIndexedFieldSizeToObjectSize_0(state_, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22}, 8);
    tmp24 = Allocate_0(state_, TNode<IntPtrT>{tmp23}, TNode<Map>{tmp18});
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp24, tmp25}, tmp18);
    tmp26 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp27 = FromConstexpr_int32_constexpr_int31_0(state_, 44);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp24, tmp26}, tmp27);
    tmp28 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp29 = FromConstexpr_int32_constexpr_int31_0(state_, 45);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp24, tmp28}, tmp29);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp24, tmp30}, tmp0);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp32 = FromConstexpr_Smi_constexpr_int31_0(state_, 55);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp24, tmp31}, tmp32);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp24, tmp33}, tmp15);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    InitializeFieldsFromIterator_Smi_SmiGeneratorIterator_0(state_, TorqueStructSlice_Smi_0{TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp19}, TorqueStructUnsafe_0{}}, TorqueStructSmiGeneratorIterator_0{TNode<Smi>{tmp16}});
    InitializeFieldsFromIterator_InternalClassStructElement_InternalClassStructElementGeneratorIterator_0(state_, TorqueStructSlice_InternalClassStructElement_0{TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp22}, TorqueStructUnsafe_0{}}, TorqueStructInternalClassStructElementGeneratorIterator_0{TNode<Smi>{tmp17}});
    tmp35 = TORQUE_CAST(TNode<HeapObject>{tmp24});
    ca_.Goto(&block166);
  }

    ca_.Bind(&block166);
}

TNode<ExportedSubClass> TestFullyGeneratedClassFromCpp_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  TNode<Oddball> tmp1;
  TNode<Map> tmp2;
  TNode<IntPtrT> tmp3;
  TNode<HeapObject> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Int32T> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<Int32T> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  TNode<ExportedSubClass> tmp14;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Null_0(state_);
    tmp1 = Null_0(state_);
    tmp2 = CodeStubAssembler(state_).GetInstanceTypeMap(EXPORTED_SUB_CLASS_TYPE);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp4 = Allocate_0(state_, TNode<IntPtrT>{tmp3}, TNode<Map>{tmp2});
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference<Map>(CodeStubAssembler::Reference{tmp4, tmp5}, tmp2);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp4, tmp6}, tmp0);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{tmp4, tmp7}, tmp1);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp9 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp4, tmp8}, tmp9);
    tmp10 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp11 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{tmp4, tmp10}, tmp11);
    tmp12 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 9);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp12}, tmp13);
    tmp14 = TORQUE_CAST(TNode<HeapObject>{tmp4});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<ExportedSubClass>{tmp14};
}

TNode<Smi> LoadInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Number> LoadInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Number> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Number>{tmp1};
}

void StoreInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

void Method_InternalClass_Flip_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_this, compiler::CodeAssemblerLabel* label_NotASmi) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Number> tmp1;
  TNode<Smi> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{p_this, tmp0});
    compiler::CodeAssemblerLabel label3(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{tmp1}, &label3);
    ca_.Goto(&block3);
    if (label3.is_used()) {
      ca_.Bind(&label3);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_NotASmi);
  }

  TNode<IntPtrT> tmp4;
  TNode<IntPtrT> tmp5;
  TNode<Smi> tmp6;
  TNode<IntPtrT> tmp7;
  if (block3.is_used()) {
    ca_.Bind(&block3);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_this, tmp5});
    CodeStubAssembler(state_).StoreReference<Number>(CodeStubAssembler::Reference{p_this, tmp4}, tmp6);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_this, tmp7}, tmp2);
    ca_.Goto(&block5);
  }

    ca_.Bind(&block5);
}

TNode<Smi> LoadSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TorqueStructReference_Smi_0 Method_SmiPair_GetA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructReference_Smi_0{TNode<HeapObject>{p_this}, TNode<IntPtrT>{tmp0}, TorqueStructUnsafe_0{}};
}

TNode<Smi> LoadSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<HeapObject> LoadExportedSubClassBaseA_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<HeapObject>{tmp1};
}

void StoreExportedSubClassBaseA_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o, TNode<HeapObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<HeapObject> LoadExportedSubClassBaseB_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<HeapObject> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<HeapObject>{tmp1};
}

void StoreExportedSubClassBaseB_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClassBase> p_o, TNode<HeapObject> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<HeapObject>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Int32T> LoadExportedSubClassCField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

void StoreExportedSubClassCField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Int32T> LoadExportedSubClassDField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o) {
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

void StoreExportedSubClassDField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadExportedSubClassEField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreExportedSubClassEField_0(compiler::CodeAssemblerState* state_, TNode<ExportedSubClass> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadInternalClassWithSmiElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreInternalClassWithSmiElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Oddball> LoadInternalClassWithSmiElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Oddball> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Oddball>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Oddball>{tmp1};
}

void StoreInternalClassWithSmiElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<Oddball> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    CodeStubAssembler(state_).StoreReference<Oddball>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadInternalClassWithSmiElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_Smi_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp12});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Smi>{tmp13};
}

void StoreInternalClassWithSmiElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithSmiElements> p_o, TNode<IntPtrT> p_i, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_Smi_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp12}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TNode<Int32T> LoadInternalClassWithStructElementsDummy1_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o) {
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

void StoreInternalClassWithStructElementsDummy1_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Int32T> p_v) {
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

TNode<Int32T> LoadInternalClassWithStructElementsDummy2_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Int32T> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp1 = CodeStubAssembler(state_).LoadReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Int32T>{tmp1};
}

void StoreInternalClassWithStructElementsDummy2_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Int32T> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    CodeStubAssembler(state_).StoreReference<Int32T>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadInternalClassWithStructElementsCount_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

TNode<Smi> LoadInternalClassWithStructElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

void StoreInternalClassWithStructElementsData_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Object> LoadInternalClassWithStructElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<Object> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    tmp1 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{p_o, tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp1};
}

void StoreInternalClassWithStructElementsObject_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<Object> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 20);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{p_o, tmp0}, p_v);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TNode<Smi> LoadInternalClassWithStructElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<IntPtrT> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  TNode<Smi> tmp13;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_Smi_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    tmp13 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp12});
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
  return TNode<Smi>{tmp13};
}

void StoreInternalClassWithStructElementsEntries_0(compiler::CodeAssemblerState* state_, TNode<InternalClassWithStructElements> p_o, TNode<IntPtrT> p_i, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  TNode<Smi> tmp3;
  TNode<IntPtrT> tmp4;
  TNode<UintPtrT> tmp5;
  TNode<UintPtrT> tmp6;
  TNode<BoolT> tmp7;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 24);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    tmp2 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    tmp3 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_o, tmp2});
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp3});
    tmp5 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{p_i});
    tmp6 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp4});
    tmp7 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp5}, TNode<UintPtrT>{tmp6});
    ca_.Branch(tmp7, &block6, std::vector<Node*>{}, &block7, std::vector<Node*>{});
  }

  TNode<IntPtrT> tmp8;
  TNode<IntPtrT> tmp9;
  TNode<IntPtrT> tmp10;
  TNode<HeapObject> tmp11;
  TNode<IntPtrT> tmp12;
  if (block6.is_used()) {
    ca_.Bind(&block6);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp9 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_i}, TNode<IntPtrT>{tmp8});
    tmp10 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp9});
    std::tie(tmp11, tmp12) = NewReference_Smi_0(state_, TNode<HeapObject>{p_o}, TNode<IntPtrT>{tmp10}).Flatten();
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp11, tmp12}, p_v);
    ca_.Goto(&block9);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block9);
}

TF_BUILTIN(GenericBuiltinTest_Smi_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Smi> parameter0 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter0);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Null_0(state_);
    CodeStubAssembler(state_).Return(tmp0);
  }
}

TNode<Object> GenericMacroTest_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{tmp0};
}

TNode<Object> GenericMacroTestWithLabels_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param, compiler::CodeAssemblerLabel* label__X) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Oddball> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = Undefined_0(state_);
    ca_.Goto(&block3);
  }

    ca_.Bind(&block3);
  return TNode<Object>{tmp0};
}

TNode<Object> IncrementIfSmi_NumberOrFixedArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_Smi_0(state_, TNode<Object>{p_x}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    ca_.Goto(&block1, ca_.UncheckedCast<HeapObject>(p_x));
  }

  TNode<Smi> tmp2;
  TNode<Smi> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp2});
    ca_.Goto(&block1, tmp3);
  }

  TNode<Object> phi_bb1_1;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_1);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<Object>{phi_bb1_1};
}

TNode<Smi> ExampleGenericOverload_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp1 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{p_o}, TNode<Smi>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Smi>{tmp1};
}

TNode<Object> ExampleGenericOverload_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TNode<Object>{p_o};
}

TNode<BoolT> Is_JSArray_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<JSArray> tmp0;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label1(&ca_);
    tmp0 = Cast_JSArray_1(state_, TNode<Context>{p_context}, TNode<Object>{p_o}, &label1);
    ca_.Goto(&block4);
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block5);
    }
  }

  TNode<BoolT> tmp2;
  if (block5.is_used()) {
    ca_.Bind(&block5);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp2);
  }

  TNode<BoolT> tmp3;
  if (block4.is_used()) {
    ca_.Bind(&block4);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp3);
  }

  TNode<BoolT> phi_bb1_2;
  if (block1.is_used()) {
    ca_.Bind(&block1, &phi_bb1_2);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
  return TNode<BoolT>{phi_bb1_2};
}

void InitializeFieldsFromIterator_Object_TestIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Object_0 p_target, TorqueStructTestIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<IntPtrT> tmp0;
  TNode<IntPtrT> tmp1;
  TNode<IntPtrT> tmp2;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp1 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{p_target.length}, TNode<IntPtrT>{tmp0});
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{p_target.offset}, TNode<IntPtrT>{tmp1});
    ca_.Goto(&block5, p_target.offset, p_originIterator.count);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<Smi> phi_bb5_7;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5, &phi_bb5_7);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_5, phi_bb5_7}, &block4, std::vector<Node*>{phi_bb5_5, phi_bb5_7});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<Smi> phi_bb3_7;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_7);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_5, phi_bb3_7}, &block10, std::vector<Node*>{phi_bb3_5, phi_bb3_7});
  }

  TNode<IntPtrT> phi_bb9_5;
  TNode<Smi> phi_bb9_7;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_7);
    ca_.Goto(&block4, phi_bb9_5, phi_bb9_7);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<Smi> phi_bb10_7;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<Smi> tmp10;
  TNode<Smi> tmp11;
  TNode<BoolT> tmp12;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5, &phi_bb10_7);
    std::tie(tmp5, tmp6) = NewReference_Object_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp7});
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp10 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{phi_bb10_7}, TNode<Smi>{tmp9});
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    tmp12 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{phi_bb10_7}, TNode<Smi>{tmp11});
    ca_.Branch(tmp12, &block16, std::vector<Node*>{}, &block17, std::vector<Node*>{});
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    CodeStubAssembler(state_).Unreachable();
  }

  TNode<Oddball> tmp13;
  if (block17.is_used()) {
    ca_.Bind(&block17);
    tmp13 = TheHole_0(state_);
    CodeStubAssembler(state_).StoreReference<Object>(CodeStubAssembler::Reference{tmp5, tmp6}, tmp13);
    ca_.Goto(&block5, tmp8, tmp10);
  }

  TNode<IntPtrT> phi_bb4_5;
  TNode<Smi> phi_bb4_7;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5, &phi_bb4_7);
    ca_.Goto(&block18);
  }

    ca_.Bind(&block18);
}

void Swap_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Smi_0 p_a, TorqueStructReference_Smi_0 p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  TNode<Smi> tmp0;
  TNode<Smi> tmp1;
  if (block0.is_used()) {
    ca_.Bind(&block0);
    tmp0 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_a.object, p_a.offset});
    tmp1 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{p_b.object, p_b.offset});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_a.object, p_a.offset}, tmp1);
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{p_b.object, p_b.offset}, tmp0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TorqueStructTestTuple_Smi_intptr_0 TupleSwap_intptr_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructTestTuple_intptr_Smi_0 p_tuple) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return TorqueStructTestTuple_Smi_intptr_0{TNode<Smi>{p_tuple.snd}, TNode<IntPtrT>{p_tuple.fst}};
}

void InitializeFieldsFromIterator_Smi_SmiGeneratorIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_Smi_0 p_target, TorqueStructSmiGeneratorIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    ca_.Goto(&block5, p_target.offset, p_originIterator.value);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<Smi> phi_bb5_7;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5, &phi_bb5_7);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_5, phi_bb5_7}, &block4, std::vector<Node*>{phi_bb5_5, phi_bb5_7});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<Smi> phi_bb3_7;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_7);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_5, phi_bb3_7}, &block10, std::vector<Node*>{phi_bb3_5, phi_bb3_7});
  }

  TNode<IntPtrT> phi_bb9_5;
  TNode<Smi> phi_bb9_7;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_7);
    ca_.Goto(&block4, phi_bb9_5, phi_bb9_7);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<Smi> phi_bb10_7;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<Smi> tmp10;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5, &phi_bb10_7);
    std::tie(tmp5, tmp6) = NewReference_Smi_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp7});
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp10 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb10_7}, TNode<Smi>{tmp9});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp6}, phi_bb10_7);
    ca_.Goto(&block5, tmp8, tmp10);
  }

  TNode<IntPtrT> phi_bb4_5;
  TNode<Smi> phi_bb4_7;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5, &phi_bb4_7);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

void InitializeFieldsFromIterator_InternalClassStructElement_InternalClassStructElementGeneratorIterator_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_InternalClassStructElement_0 p_target, TorqueStructInternalClassStructElementGeneratorIterator_0 p_originIterator) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    ca_.Goto(&block5, p_target.offset, p_originIterator.value);
  }

  TNode<IntPtrT> phi_bb5_5;
  TNode<Smi> phi_bb5_7;
  TNode<BoolT> tmp3;
  if (block5.is_used()) {
    ca_.Bind(&block5, &phi_bb5_5, &phi_bb5_7);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp3, &block3, std::vector<Node*>{phi_bb5_5, phi_bb5_7}, &block4, std::vector<Node*>{phi_bb5_5, phi_bb5_7});
  }

  TNode<IntPtrT> phi_bb3_5;
  TNode<Smi> phi_bb3_7;
  TNode<BoolT> tmp4;
  if (block3.is_used()) {
    ca_.Bind(&block3, &phi_bb3_5, &phi_bb3_7);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{phi_bb3_5}, TNode<IntPtrT>{tmp2});
    ca_.Branch(tmp4, &block9, std::vector<Node*>{phi_bb3_5, phi_bb3_7}, &block10, std::vector<Node*>{phi_bb3_5, phi_bb3_7});
  }

  TNode<IntPtrT> phi_bb9_5;
  TNode<Smi> phi_bb9_7;
  if (block9.is_used()) {
    ca_.Bind(&block9, &phi_bb9_5, &phi_bb9_7);
    ca_.Goto(&block4, phi_bb9_5, phi_bb9_7);
  }

  TNode<IntPtrT> phi_bb10_5;
  TNode<Smi> phi_bb10_7;
  TNode<HeapObject> tmp5;
  TNode<IntPtrT> tmp6;
  TNode<IntPtrT> tmp7;
  TNode<IntPtrT> tmp8;
  TNode<Smi> tmp9;
  TNode<Smi> tmp10;
  TNode<Smi> tmp11;
  TNode<Smi> tmp12;
  TNode<IntPtrT> tmp13;
  TNode<IntPtrT> tmp14;
  if (block10.is_used()) {
    ca_.Bind(&block10, &phi_bb10_5, &phi_bb10_7);
    std::tie(tmp5, tmp6) = NewReference_InternalClassStructElement_0(state_, TNode<HeapObject>{p_target.object}, TNode<IntPtrT>{phi_bb10_5}).Flatten();
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 8);
    tmp8 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{phi_bb10_5}, TNode<IntPtrT>{tmp7});
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp10 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{phi_bb10_7}, TNode<Smi>{tmp9});
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    tmp12 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp6}, phi_bb10_7);
    tmp13 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    tmp14 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp13});
    CodeStubAssembler(state_).StoreReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp14}, tmp10);
    ca_.Goto(&block5, tmp8, tmp12);
  }

  TNode<IntPtrT> phi_bb4_5;
  TNode<Smi> phi_bb4_7;
  if (block4.is_used()) {
    ca_.Bind(&block4, &phi_bb4_5, &phi_bb4_7);
    ca_.Goto(&block16);
  }

    ca_.Bind(&block16);
}

}  // namespace internal
}  // namespace v8

