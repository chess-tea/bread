open Types;

module Repeat = {
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

module Function = {
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
        ~body: option(fUtils => list(string))=?,
        ~rebind: option(string)=?,
        ~children: list(unit),
        _,
      )
      : mChild => {
    let render = _mUtils => {
      let argArray = Caml.Array.of_list(argNames);
      let argCount = Caml.Array.length(argArray);
      let arg = x => argArray[x - 1];
      let fUtils = {arg: arg};
      let argNames = Caml.String.concat(", ", argNames);
      let replace = Utils.replaceDollars(arg, argCount);
      let replaceList = Caml.List.map(replace);
      let doc = [
        "/**",
        name ++ "(" ++ argNames ++ ")",
        "",
        replace(desc),
        // "",
        // "  - TODO: Examples, SeeAlso",
        " */",
      ];
      let content =
        switch (body, rebind) {
        | (Some(body), _) =>
          let bindingOpen = [
            "let " ++ name ++ " = (" ++ argNames ++ ") => {",
          ];
          let body = Render.indent(body(fUtils));
          let bindingClose = ["};"];
          bindingOpen @ replaceList(body) @ bindingClose;
        | (_, Some(rebind)) => [
            "let " ++ name ++ " = " ++ rebind ++ ";",
          ]
        | (None, None) => ["{ (); };"]
        };
      [""] @ doc @ content @ [""];
    };
    [render];
  };
};

module Raw = {
  let createElement = (~raw: string, ~children: list(unit), _): mChild => {
    let render = _mUtils => {
      [raw];
    };
    [render];
  };
};

module Template = {
  let createElement = (~name: string, ~children: list(unit), _): mChild => {
    let render = (utils: mUtils) => {
      [""] @ utils.template(name) @ [""];
    };
    [render];
  };
};