open BreadCore;
open Components;

<ModuleDef name="String">
  <Raw raw="type t = string;" />
  <Function
    name="length"
    rebind="Caml.String.length"
    args=["t"]
    return="int"
    argNames=["string"]
    desc="returns the length (number of characters) of $1"
  />
  <Function
    name="compare"
    rebind="Caml.String.compare"
    args=["t", "t"]
    return="int"
    argNames=["a", "b"]
    desc=Const.compareDesc
  />
  <Function
    name="equal"
    rebind="Caml.String.equal"
    args=["t", "t"]
    return="bool"
    argNames=["a", "b"]
    desc=Const.equalDesc
  />
  // Necessary for string.[i] syntax support.
  <Function
    name="get"
    rebind="Caml.String.get"
    args=["t", "int"]
    return="char"
    argNames=["string", "i"]
    desc="returns the character in $1 at index $2. This function can also be called using the syntax: $1.[$2]"
    seeAlso=["String.charAt"]
  />
  <Function
    name="charAt"
    args=["int", "t"]
    return="char"
    argNames=["i", "string"]
    desc="returns the character in $2 at index $1"
    seeAlso=["String.get"]
    body={({arg}) => {["Caml.String.get($2, $1);"]}}
  />
  <Function
    name="make"
    rebind="Caml.String.make"
    args=["int", "char"]
    return="t"
    argNames=["length", "c"]
    desc="returns a new string with length $1, filled with the character $2"
  />
  <Function
    name="init"
    rebind="Caml.String.init"
    args=["int", "(int => char)"]
    return="t"
    argNames=["length", "fn"]
    desc="returns a new string with length $1, with the character at each index, i, defined by $2(i)"
  />
  <Function
    name="fromChar"
    args=["char"]
    return="t"
    argNames=["c"]
    desc="returns a new string of length 1 containing only the character $1"
    body={({arg}) => {["let s = Caml.String.make(1, $1);", "s;"]}}
  />
  <Function
    name="fromCharArray"
    args=["array(char)"]
    return="t"
    argNames=["array"]
    desc="returns a new string containing the characters in $1"
    body={({arg}) => {
      [
        "let n = Caml.Array.length($1);",
        "let s = Caml.String.init(n, i => $1[i]);",
        "s;",
      ]
    }}
  />
  <Function
    name="fromCharList"
    args=["list(char)"]
    return="t"
    argNames=["list"]
    desc="returns a new string containing the characters in $1"
    body={({arg}) => {
      ["let list = Caml.Array.of_list($1);", "fromCharArray(list);"]
    }}
  />
  <Function
    name="toCharArray"
    args=["t"]
    return="array(char)"
    argNames=["string"]
    desc="returns an array of the characters in $1"
    body={({arg}) => {
      [
        "let n = Caml.String.length($1);",
        "let arr = Caml.Array.init(n, i => Caml.String.get($1, i));",
        "arr;",
      ]
    }}
  />
  <Function
    name="toCharList"
    args=["t"]
    return="list(char)"
    argNames=["string"]
    desc="returns a list of the characters in $1"
    body={({arg}) => {
      [
        "let arr = toCharArray($1);",
        "let list = Caml.Array.to_list(arr);",
        "list;",
      ]
    }}
  />
  <Function
    name="toUppercase"
    rebind="Caml.String.uppercase_ascii"
    args=["t"]
    return="t"
    argNames=["string"]
    desc="returns a copy of $1 with all lowercase letters converted to uppercase using the US-ASCII character set"
  />
  <Function
    name="toLowercase"
    rebind="Caml.String.lowercase_ascii"
    args=["t"]
    return="t"
    argNames=["string"]
    desc="returns a copy of $1 with all uppercase letters converted to lowercase using the US-ASCII character set"
  />
  <Function
    name="slice"
    args=["int", "int", "t"]
    return="t"
    argNames=["i", "j", "string"]
    desc="returns a substring of $3 between given indices $1 and $2"
    body={({arg}) => {
      [
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
      ]
    }}
  />
  <Function
    name="sliceToEnd"
    args=["int", "t"]
    return="t"
    argNames=["i", "string"]
    desc="returns a substring of $2 from index $1 to the end"
    body={({arg}) => {["slice($1, Caml.String.length($2), $2);"]}}
  />
  <Template name="string/indexOfInternal" />
  <Template name="string/indexOfInt" />
  <Template name="string/indexOf" />
  <Template name="string/lastIndexOfInt" />
  <Template name="string/lastIndexOf" />
  <Template name="string/contains" />
</ModuleDef>;
