open Core;
open Components;

<M name="Option">
  <F
    name="isNone"
    args=["t($1)"]
    return="bool"
    argNames=["option"]
    desc="returns whether $1 is None"
    body={({arg}) => {Inline.optionSwitch(arg(1), "_", "false", "true")}}
  />
  <F
    name="isSome"
    args=["t($1)"]
    return="bool"
    argNames=["option"]
    desc="returns whether $1 is Some"
    body={({arg}) => {Inline.optionSwitch(arg(1), "_", "true", "false")}}
  />
  <F
    name="makeNone"
    args=["$1"]
    return="t($1)"
    argNames=["value"]
    desc="ignores $1 and always returns None"
    body={({arg}) => {["None"]}}
  />
  <F
    name="makeSome"
    args=["$1"]
    return="t($1)"
    argNames=["value"]
    desc="returns Some($1)"
    body={({arg}) => {["Some(" ++ arg(1) ++ ")"]}}
  />
  <F
    name="get"
    args=["$1", "t($1)"]
    return="$1"
    argNames=["default", "option"]
    desc="returns the value contained within $2 if it exists; otherwise, returns $1"
    body={({arg}) => {
      Inline.optionSwitch(arg(2), arg(2), arg(2), arg(1))
    }}
  />
  <F
    name="getExn"
    args=["t($1)"]
    return="$1"
    argNames=["option"]
    desc="returns the value contained within $1 if it exists; otherwise, raises exception"
    body={({arg}) => {
      Inline.optionSwitch(
        arg(1),
        arg(1),
        arg(1),
        "failwith(\"Unexpected None\")",
      )
    }}
  />
</M>;
