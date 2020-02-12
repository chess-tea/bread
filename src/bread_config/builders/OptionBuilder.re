open Core;
open Doc;
open Components;

<M name="Option">
  <F
    name="get"
    args=["$1", "t($1)"]
    return="$1"
    argNames=["default", "option"]
    desc="returns the value contained within $2 if it exists; otherwise, returns $1"
    body={({arg}) => {Inline.optionSwitch(arg(2), arg(2), arg(1))}}
  />
</M>;
