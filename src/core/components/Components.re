// Types
module Types = {
  type fUtils = {arg: int => string};
  type mUtils = {moduleName: unit => string};
  type mChild = mUtils => list(string);
  type m = {
    name: string,
    children: list(mChild),
  };
};

open Types;

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
        ~body: Types.fUtils => list(string),
        ~children: list(unit),
        _,
      )
      : Types.mChild => {
    let render = _mUtils => {
      let argArray = Caml.Array.of_list(argNames);
      let fUtils = {arg: x => argArray[x - 1]};
      let argNames = Caml.String.concat(", ", argNames);
      let doc = [
        "/**",
        name ++ "(" ++ argNames ++ ") " ++ desc,
        "",
        "  - TODO: Examples, SeeAlso",
        "*/",
      ];
      let bindingOpen = ["let " ++ name ++ " = (" ++ argNames ++ ") => {"];
      let body = body(fUtils);
      let bindingClose = ["};"];
      doc @ bindingOpen @ body @ bindingClose;
    };
    render;
  };
};

module Render = {
  let render = (m: m): list(string) => {
    let mUtils: mUtils = {moduleName: () => m.name};
    let moduleOpen = ["module " ++ m.name ++ " = {"];
    let moduleInner =
      m.children |> Caml.List.map(child => child(mUtils)) |> Caml.List.flatten;
    let moduleClose = ["};", ""];
    moduleOpen @ moduleInner @ moduleClose;
  };
};
