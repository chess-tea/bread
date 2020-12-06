open BreadCore;
open Components;

<ModuleDef name="Result">
  <Function
    name="isOk"
    args=["t($1, $2)"]
    return="bool"
    argNames=["result"]
    desc="returns whether $1 is Ok"
    body={({arg}) => {
      Inline.resultSwitch(arg(1), "_", "true", "_", "false")
    }}
  />
  <Function
    name="isError"
    args=["t($1, $2)"]
    return="bool"
    argNames=["result"]
    desc="returns whether $1 is Error"
    body={({arg}) => {
      Inline.resultSwitch(arg(1), "_", "false", "_", "true")
    }}
  />
</ModuleDef>;
