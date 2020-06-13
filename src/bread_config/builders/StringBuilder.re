open Core;
open Components;

<ModuleDef name="String">
  <Let name="length" right="Caml.String.length" />
  <Function
    name="slice"
    args=["int", "int", "t"]
    return="t"
    argNames=["i", "j", "string"]
    desc="returns a substring of $3 between given indices $1 and $2"
    body={({arg}) => {[
      "let n = Caml.String.length($3)",
      "/* Resolve indices to final positions. */",
      "let $1 = $1 < 0 ? $1 + n : $1;",
      "let $1 = $1 < 0 ? 0 : $1;",
      "let $1 = $1 > n ? n : $1;",
      "let $2 = $2 < 0 ? $2 + n : $2;",
      "let $2 = $2 < 0 ? 0 : $2;",
      "let $2 = $2 > n ? n : $2;",
      "if ($1 >= $2) {",
      "  \"\";",
      "} else {",
      "  Caml.String.sub($3, $1, $2 - $1);",
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
      "slice($1, Caml.String.length($2), $2);",
    ]}}
  />
  <Template name="string/indexOfInternal" />
  <Template name="string/indexOfInt" />
  <Template name="string/indexOf" />
  <Template name="string/lastIndexOfInt" />
  <Template name="string/lastIndexOf" />
  <Template name="string/contains" />
</ModuleDef>;
