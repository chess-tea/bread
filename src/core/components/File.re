let createElement =
    (~path: Fp.t(Fp.relative), ~children: list(string), _: unit)
    : (Fp.t(Fp.relative), string) => {
  let header = [
    "/**",
    " * This code is generated. Do not modify manually.",
    " *",
    " * @generated",
    " */;",
    "",
  ];
  let header = Caml.String.concat("\n", header);
  let body = Caml.String.concat("\n", children);
  let contents = header ++ "\n" ++ body;
  let contents = Caml.String.trim(contents);
  (path, contents);
};
