open BreadCore;
open Components;

<ModuleDef name="Option">
  <Function
    name="isNone"
    args=["t($1)"]
    return="bool"
    argNames=["option"]
    desc="returns whether $1 is None"
    body={({arg}) => {Inline.optionSwitch(arg(1), "_", "false", "true")}}
  />
  <Function
    name="isSome"
    args=["t($1)"]
    return="bool"
    argNames=["option"]
    desc="returns whether $1 is Some"
    body={({arg}) => {Inline.optionSwitch(arg(1), "_", "true", "false")}}
  />
  <Function
    name="makeNone"
    args=["$1"]
    return="t($1)"
    argNames=["_value"]
    desc="ignores $1 and always returns None"
    body={({arg}) => {["None"]}}
  />
  <Function
    name="makeSome"
    args=["$1"]
    return="t($1)"
    argNames=["value"]
    desc="returns Some($1)"
    body={({arg}) => {["Some($1)"]}}
  />
  <Function
    name="get"
    args=["$1", "t($1)"]
    return="$1"
    argNames=["default", "option"]
    desc="returns the value contained within $2 if it exists; otherwise, returns $1"
    body={({arg}) => {
      Inline.optionSwitch(arg(2), arg(2), arg(2), arg(1))
    }}
  />
  <Function
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
  <Function
    name="getLazy"
    args=["unit => $1", "t($1)"]
    return="$1"
    argNames=["defaultFn", "option"]
    desc="returns the value contained within $2 if it exists; otherwise, returns the result of calling $1"
    body={({arg}) => {
      Inline.optionSwitch(arg(2), arg(2), arg(2), arg(1) ++ "()")
    }}
  />
  <Function
    name="filterKeep"
    args=["$1 => bool", "t($1)"]
    return="t($1)"
    argNames=["testFn", "option"]
    desc="keeps the value and option unchanged if $1 is true when called with $2's value; otherwise, returns None"
    body={({arg}) => {
      [
        "switch ($2) {",
        "| Some(value) when $1(value) => $2",
        "| _ => None",
        "}",
      ]
    }}
  />
  <Function
    name="filterDrop"
    args=["$1 => bool", "t($1)"]
    return="t($1)"
    argNames=["testFn", "option"]
    desc="drops the value and returns None if $1 is true when called with $2's value; otherwise, returns $2 unchanged"
    body={({arg}) => {
      [
        "switch ($2) {",
        "| Some(value) when $1(value) => $2",
        "| _ => None",
        "}",
      ]
    }}
  />
  <Function
    name="toResult"
    args=["$1", "t($2)"]
    return="result($1, $2)"
    argNames=["noneError", "option"]
    desc="converts $2 to a result. Returns Ok(value) if $2 is Some(value), and Error($1) otherwise"
    body={({arg}) => {[
      "switch ($2) {",
      "| Some(value) => Ok(value)",
      "| None => Error($1)",
      "}",
    ]}}
  />
  <Function
    name="fromResult"
    args=["result($1, $2)"]
    return="t($1)"
    argNames=["result"]
    desc="converts $1 to an option. Returns Some(value) if $1 is Ok(value), and None otherwise"
    body={({arg}) => {[
      "switch ($1) {",
      "| Ok(value) => Some(value)",
      "| Error(_) => None",
      "}",
    ]}}
  />
  <Repeat
    n=7
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

      <Function
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
            "  Some($1(" ++ Render.commas(options) ++ "))",
            "| _ => None",
            "}",
          ];
        }}
      />;
    }}
  />
  <Repeat
    n=7
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

      <Function
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
            "  $1(" ++ Render.commas(options) ++ ")",
            "| _ => None",
            "}",
          ];
        }}
      />;
    }}
  />
</ModuleDef>;
