open BreadCore;
open Components;

<ModuleDef name="Char" priority=90>
  <Raw
    desc={
      "Alias for the char type. Useful for using this module with certain "
      ++ "Functors"
    }
    raw="type t = char;"
  />
  <Function
    name="compare"
    rebind="Caml.Char.compare"
    args=["t", "t"]
    return="int"
    argNames=["a", "b"]
    desc=Const.compareDesc
  />
  <Function
    name="equal"
    rebind="Caml.Char.equal"
    args=["t", "t"]
    return="bool"
    argNames=["a", "b"]
    desc=Const.equalDesc
  />
  <Function
    name="isWhitespace"
    args=["t"]
    return="bool"
    argNames=["c"]
    desc={
      "tests if $1 is a whitespace character: ' ', '\\012', '\\n', '\\r', "
      ++ "or '\\t'"
    }
    body={({arg}) => {
      [
        "switch ($1) {",
        "| ' '",
        "| '\\012'",
        "| '\\n'",
        "| '\\r'",
        "| '\\t' => true",
        "| _ => false",
        "};",
      ]
    }}
  />
</ModuleDef>;
