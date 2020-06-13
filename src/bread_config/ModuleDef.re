open Core;

let createElement =
    (
      ~name: string,
      ~docs: list(string)=[],
      ~seeAlso: list(string)=[],
      ~priority: int=0,
      ~children: list(Types.mChild),
      _,
    )
    : unit => {
  ();
  Registry.Modules.add({name, children, priority});
};
