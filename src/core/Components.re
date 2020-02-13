open Types;

module X = {
  let createElement =
      (
        ~first=1,
        ~increment=1,
        ~n: int,
        ~make: int => mChild,
        ~children: list(unit),
        _,
      )
      : mChild => {
    let result = Loop.loop(~increment, first, n, make);
    Caml.List.flatten(result);
  };
};

module F = {
  let createElement =
      (
        ~name: string,
        /* The types of each arg. Use $1, $2, etc. to refer to type params. */
        ~args: list(string),
        /* The type of the result. Use $1, $2, etc. to refer to type params. */
        ~return: string,
        /*
         * The names of the args, can be anything but should be named well for
         * better docs
         */
        ~argNames: list(string),
        ~desc: string,
        ~seeAlso: list(string)=[],
        ~examples: list(string)=[],
        ~body: fUtils => list(string),
        ~children: list(unit),
        _,
      )
      : mChild => {
    let render = _mUtils => {
      let argArray = Caml.Array.of_list(argNames);
      let fUtils = {arg: x => argArray[x - 1]};
      let argNames = Caml.String.concat(", ", argNames);
      let doc = [
        "/**",
        name ++ "(" ++ argNames ++ ")",
        "",
        desc,
        // "",
        // "  - TODO: Examples, SeeAlso",
        " */",
      ];
      let bindingOpen = ["let " ++ name ++ " = (" ++ argNames ++ ") => {"];
      let body = Render.indent(body(fUtils));
      let bindingClose = ["};"];
      [""] @ doc @ bindingOpen @ body @ bindingClose @ [""];
    };
    [render];
  };
};
