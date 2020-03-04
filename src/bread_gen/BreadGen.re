let test = 42;

print_endline("Hello World");

let args = Sys.argv;

if (Array.length(args) < 2) {
  failwith(
    "Expected exactly 1 argument to BreadGen that is the output directory. Received no arguments.",
  );
};

if (Array.length(args) > 2) {
  failwith(
    "Expected exactly 1 argument to BreadGen that is the output directory. Received too many arguments.",
  );
};

let outputDir = args[1];

print_endline("Installing in:");
print_endline("  - " ++ outputDir);
print_endline("Rendering:");

let root = Fp.absoluteExn(outputDir);
let ms = Registry.Modules.get();

let contents =
  Registry.Modules.get()
  |> List.map((m: Core.Types.m) => {
       print_endline("  - " ++ m.name);
       let contents = Core.Render.m(m);
       contents;
     })
  |> List.flatten;

let contents =
  [
    "/**",
    " * This file is generated. Do not modify it manually.",
    " *",
    " * To update this file:",
    " *   - Modify relevant files in: src/bread_config",
    " *   - Run: esy gen",
    " *",
    " * @generated",
    " */;",
    "",
  ]
  @ [
    // TODO: Should move this to a builder rather than it being hard-coded.
    "module Caml = {",
    "  module Array = Array;",
    "  module List = List;",
    "  module String = String;",
    "};",
    "",
  ]
  @ contents;

let removeDuplicateEmptyLines = lines => {
  let count = ref(0);
  let lines =
    lines
    |> List.map(line => {
         let trimmed = String.trim(line);
         let n = String.length(trimmed);
         if (n === 0) {
           incr(count);
         } else {
           count := 0;
         };

         if (count^ > 1) {
           None;
         } else {
           Some(line);
         };
       })
    |> List.filter(oLine => oLine != None)
    |> List.map(o =>
         switch (o) {
         | Some(value) => value
         | None => failwith("unreachable")
         }
       );
  lines;
};

let contents = removeDuplicateEmptyLines(contents);

print_endline("Writing Bread.re");

Fs.writeTextExn(Fp.At.(root / "Bread.re"), contents);

print_endline("All Done!");
