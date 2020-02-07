open DocTypes;

module U = {
  let render = (d: doc) => {
    switch (d) {
    | String(s) => s
    | Break => "\n"
    | _ => ""
    };
  };
};

module String = {
  let createElement = (~children: list(string), _: unit): doc => {
    let result = Caml.String.concat("", children);
    String(result);
  };
};

let createElement =
    (
      ~openToken="/**",
      ~lineLength=80,
      ~endingSemicolon=false,
      ~children: DocTypes.t,
      _: unit,
    )
    : string => {
  let semi = endingSemicolon ? ";\n" : "";
  let parts =
    [openToken, "\n"]
    @ Caml.List.map(U.render, children)
    @ ["\n", "*/", semi];
  Caml.String.concat("", parts);
};
