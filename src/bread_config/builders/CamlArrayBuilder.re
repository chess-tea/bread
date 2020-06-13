open Core;
open Components;

<ModuleDef name="CamlArray">
  <Function
    name="isEmpty"
    args=["t($1)"]
    return="bool"
    argNames=["array"]
    desc="returns whether $1 is empty"
    body={({arg}) => {["Caml.Array.length(" ++ arg(1) ++ ") === 0"]}}
  />
</ModuleDef>;
