open Core;
open Components;

<ModuleDef name="CamlList">
  <Function
    name="isEmpty"
    args=["t($1)"]
    return="bool"
    argNames=["list"]
    desc="returns whether $1 is empty"
    body={({arg}) => {
      [
        // not-one-line
        "switch (" ++ arg(1) ++ ") {",
        "| [] => true",
        "| _ => false",
        "}",
      ]
    }}
  />
</ModuleDef>;
