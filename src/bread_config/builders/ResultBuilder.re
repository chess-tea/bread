open Core;
open Components;

<M name="Result">
  <F
    name="isOk"
    args=["t($1, $2)"]
    return="bool"
    argNames=["result"]
    desc="returns whether $1 is Ok"
    body={({arg}) => {
      Inline.resultSwitch(arg(1), "_", "true", "_", "false")
    }}
  />
  <F
    name="isError"
    args=["t($1, $2)"]
    return="bool"
    argNames=["result"]
    desc="returns whether $1 is Error"
    body={({arg}) => {
      Inline.resultSwitch(arg(1), "_", "false", "_", "true")
    }}
  />
</M>;
