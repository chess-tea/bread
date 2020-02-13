open Core;
open Components;

<M name="Option">
  <F
    name="isNone"
    args=["t($1)"]
    return="bool"
    argNames=["option"]
    desc="returns whether $1 is None"
    body={({arg}) => {Inline.optionSwitch(arg(1), "_", "false", "true")}}
  />
  <F
    name="isSome"
    args=["t($1)"]
    return="bool"
    argNames=["option"]
    desc="returns whether $1 is Some"
    body={({arg}) => {Inline.optionSwitch(arg(1), "_", "true", "false")}}
  />
  <F
    name="makeNone"
    args=["$1"]
    return="t($1)"
    argNames=["value"]
    desc="ignores $1 and always returns None"
    body={({arg}) => {["None"]}}
  />
  <F
    name="makeSome"
    args=["$1"]
    return="t($1)"
    argNames=["value"]
    desc="returns Some($1)"
    body={({arg}) => {["Some(" ++ arg(1) ++ ")"]}}
  />
  <F
    name="get"
    args=["$1", "t($1)"]
    return="$1"
    argNames=["default", "option"]
    desc="returns the value contained within $2 if it exists; otherwise, returns $1"
    body={({arg}) => {
      Inline.optionSwitch(arg(2), arg(2), arg(2), arg(1))
    }}
  />
  <F
    name="getExn"
    args=["t($1)"]
    return="$1"
    argNames=["option"]
    desc="returns the value contained within $1 if it exists; otherwise, raises exception"
    body={({arg}) => {
      Inline.optionSwitch(
        arg(1),
        arg(1),
        arg(1),
        "failwith(\"Unexpected None\")",
      )
    }}
  />
  <X
    n=5
    make={i => {
      let iStr = i === 1 ? "" : string_of_int(i);
      let iNextStr = string_of_int(i + 1);
      let name = "map" ++ iStr;
      let fnArgArgs = Loop.loopS(1, i, s => "$" ++ s);
      let fnArgArgs = Caml.String.concat(", ", fnArgArgs);
      let fnArg = "(" ++ fnArgArgs ++ ") => " ++ "$" ++ iNextStr;
      let optionArgs = Loop.loopS(1, i, s => "t($" ++ s ++ ")");
      let optionNames = Loop.loopS(1, i, s => "option" ++ s);
      let args = [fnArg, ...optionArgs];
      let return = "t($" ++ iNextStr ++ ")";
      let argNames = ["fn", ...optionNames];

      <F
        name
        args
        return
        argNames
        desc="changes value of an option according to $1 if all inputs are Some value"
        body={({arg}) => {["None"]}}
      />;
    }}
  />
</M>;
