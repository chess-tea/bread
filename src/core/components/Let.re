let createElement =
    (
      ~name: string,
      ~doc: option(string)=?,
      ~children: list(string),
      _: unit,
    )
    : string => {
  let parts =
    switch (doc) {
    | Some(doc) => [doc]
    | None => []
    };
  let parts =
    switch (children) {
    | [] => parts @ ["let " ++ name ++ " = ();"]
    | [first, ...rest] => parts @ ["let " ++ name ++ " = " ++ first] @ rest
    };
  Caml.String.concat("\n", parts) ++ ";\n";
};
