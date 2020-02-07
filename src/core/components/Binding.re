let createElement =
    (
      ~name: string,
      ~t: option(string)=?,
      ~doc: option(string)=?,
      ~children: list(string),
      _: unit,
    )
    : string => {
  let t =
    switch (t) {
    | Some(t) => ": " ++ t
    | None => ""
    };
  let parts =
    switch (doc) {
    | Some(doc) => [doc]
    | None => []
    };
  let parts =
    switch (children) {
    | [] => parts @ ["let " ++ name ++ t ++ " = ();"]
    | [first, ...rest] =>
      parts @ ["let " ++ name ++ t ++ " = " ++ first] @ rest
    };
  Caml.String.concat("\n", parts) ++ ";\n";
};
