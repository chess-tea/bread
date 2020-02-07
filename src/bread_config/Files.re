type relative = Fp.t(Fp.relative);
type absolute = Fp.t(Fp.absolute);

let createElement = (~children: list((relative, string)), _: unit): unit => {
  let fn = root => {
    let () =
      List.iter(
        ((path, contents)) => {
          let fullPath = Fp.join(root, path);
          print_endline("  - " ++ Fp.toString(fullPath));
          let parts = String.split_on_char('\n', contents);
          let () = Fs.writeTextExn(fullPath, parts);
          ();
        },
        children,
      );
    ();
  };
  Registry.Files.add(fn);
};
