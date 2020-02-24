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
    argNames=["_value"]
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
  <F
    name="getLazy"
    args=["unit => $1", "t($1)"]
    return="$1"
    argNames=["defaultFn", "option"]
    desc="returns the value contained within $2 if it exists; otherwise, returns the result of calling $1"
    body={({arg}) => {
      Inline.optionSwitch(arg(2), arg(2), arg(2), arg(1) ++ "()")
    }}
  />
  <F
    name="filterKeep"
    args=["$1 => bool", "t($1)"]
    return="t($1)"
    argNames=["testFn", "option"]
    desc="keeps the value and option unchanged if $1 is true when called with $2's value; otherwise, returns None"
    body={({arg}) => {
      [
        "switch (" ++ arg(2) ++ ") {",
        "| Some(value) when " ++ arg(1) ++ "(value) => " ++ arg(2),
        "| _ => None",
        "}",
      ]
    }}
  />
  <F
    name="filterDrop"
    args=["$1 => bool", "t($1)"]
    return="t($1)"
    argNames=["testFn", "option"]
    desc="drops the value and returns None if $1 is true when called with $2's value; otherwise, returns $2 unchanged"
    body={({arg}) => {
      [
        "switch (" ++ arg(2) ++ ") {",
        "| Some(value) when " ++ arg(1) ++ "(value) => " ++ arg(2),
        "| _ => None",
        "}",
      ]
    }}
  />
  <X
    n=5
    make={i => {
      let iStr = string_of_int(i);
      let iNextStr = string_of_int(i + 1);

      let name =
        switch (i) {
        | 1 => "map"
        | _ => "map" ++ iStr
        };

      let types = Loop.loopS(1, i, s => "$" ++ s);
      let tTypes = List.map(t => "t(" ++ t ++ ")", types);
      let args =
        {let fn = "(" ++ Render.commas(types) ++ ") => $" ++ iNextStr;
         [fn, ...tTypes]};
      let return = "t($" ++ iNextStr ++ ")";
      let argNames =
        {let optionNames =
           switch (i) {
           | 1 => ["option"]
           | _ => Loop.loopS(1, i, s => "option" ++ s)
           };
         ["fn", ...optionNames]};

      <F
        name
        args
        return
        argNames
        desc="changes value of an option according to $1 if all inputs are Some value"
        body={({arg}) => {
          let options = Loop.loop(1, i, i => arg(i + 1));
          let allSome = List.map(o => "Some(" ++ o ++ ")", options);
          [
            "switch (" ++ Render.commas(options) ++ ") {",
            "| (" ++ Render.commas(allSome) ++ ") =>",
            "  Some(" ++ arg(1) ++ "(" ++ Render.commas(options) ++ "))",
            "| _ => None",
            "}",
          ];
        }}
      />;
    }}
  />
  <X
    n=5
    make={i => {
      let iStr = string_of_int(i);
      let iNextStr = string_of_int(i + 1);

      let name =
        switch (i) {
        | 1 => "flatMap"
        | _ => "flatMap" ++ iStr
        };

      let types = Loop.loopS(1, i, s => "$" ++ s);
      let tTypes = List.map(t => "t(" ++ t ++ ")", types);
      let args =
        {let fn =
           "(" ++ Render.commas(types) ++ ") => t($" ++ iNextStr ++ ")";
         [fn, ...tTypes]};
      let return = "t($" ++ iNextStr ++ ")";
      let argNames =
        {let optionNames =
           switch (i) {
           | 1 => ["option"]
           | _ => Loop.loopS(1, i, s => "option" ++ s)
           };
         ["fn", ...optionNames]};

      <F
        name
        args
        return
        argNames
        desc="changes value of an option according to $1 if all inputs are Some value"
        body={({arg}) => {
          let options = Loop.loop(1, i, i => arg(i + 1));
          let allSome = List.map(o => "Some(" ++ o ++ ")", options);
          [
            "switch (" ++ Render.commas(options) ++ ") {",
            "| (" ++ Render.commas(allSome) ++ ") =>",
            "  " ++ arg(1) ++ "(" ++ Render.commas(options) ++ ")",
            "| _ => None",
            "}",
          ];
        }}
      />;
    }}
  />
</M>;
