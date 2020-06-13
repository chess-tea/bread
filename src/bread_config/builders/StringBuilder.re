open Core;
open Components;

<ModuleDef name="String">
  <Function
    name="slice"
    args=["int", "int", "t"]
    return="t"
    argNames=["i", "j", "string"]
    desc="returns a substring of $3 between given indices $1 and $2"
    body={({arg}) => {[
      "let n = Caml.String.length(" ++ arg(3) ++ ")",
      "/* Resolve indices to final positions. */",
      "let " ++ arg(1) ++ " = " ++ arg(1) ++ " < 0 ? " ++ arg(1) ++ " + n : " ++ arg(1) ++ ";",
      "let " ++ arg(1) ++ " = " ++ arg(1) ++ " < 0 ? 0 : " ++ arg(1) ++ ";",
      "let " ++ arg(1) ++ " = " ++ arg(1) ++ " > n ? n : " ++ arg(1) ++ ";",
      "let " ++ arg(2) ++ " = " ++ arg(2) ++ " < 0 ? " ++ arg(2) ++ " + n : " ++ arg(2) ++ ";",
      "let " ++ arg(2) ++ " = " ++ arg(2) ++ " < 0 ? 0 : " ++ arg(2) ++ ";",
      "let " ++ arg(2) ++ " = " ++ arg(2) ++ " > n ? n : " ++ arg(2) ++ ";",
      "if (" ++ arg(1) ++ " >= " ++ arg(2) ++ ") {",
      "  \"\";",
      "} else {",
      "  Caml.String.sub(" ++ arg(3) ++ ", " ++ arg(1) ++ ", " ++ arg(2) ++ " - " ++ arg(1) ++ ");",
      "};",
    ]}}
  />
  <Function
    name="sliceToEnd"
    args=["int", "t"]
    return="t"
    argNames=["i", "string"]
    desc="returns a substring of $2 from index $1 to the end"
    body={({arg}) => {[
      "slice(" ++ arg(1) ++ ", Caml.String.length(" ++ arg(2) ++ "), " ++ arg(2) ++ ");",
    ]}}
  />
</ModuleDef>;
