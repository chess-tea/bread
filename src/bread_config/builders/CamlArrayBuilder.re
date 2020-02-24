open Core;
open Components;

<M name="CamlArray">
  <F
    name="isEmpty"
    args=["t($1)"]
    return="bool"
    argNames=["array"]
    desc="returns whether $1 is empty"
    body={({arg}) => {["Caml.Array.length(" ++ arg(1) ++ ") === 0"]}}
  />
</M>;
