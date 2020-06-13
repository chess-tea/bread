let args = Sys.argv;

if (Array.length(args) < 2) {
  failwith(
    "Expected exactly 2 arguments to BreadGen. The output and templates directory. Received too few arguments.",
  );
};

if (Array.length(args) > 3) {
  failwith(
    "Expected exactly 2 arguments to BreadGen. The output and templates directory. Received too many arguments.",
  );
};

let outputDir = args[1];
let templatesDir = args[2];

print_endline("Installing in:");
print_endline("  - " ++ outputDir);
print_endline("Loading templates from:");
print_endline("  - " ++ templatesDir);

let templatesDir = Fp.absoluteExn(templatesDir);
module StringMap = Map.Make(String);
let templateMap = ref(StringMap.empty);
Fs.traverseFileSystemFromPath(
  ~onNode=(result, cont) => {
    switch (result) {
    | File(path, _stat) =>
      let pathString = Fp.toString(path);
      let contents = Fs.readTextExn(path);
      templateMap := StringMap.add(pathString, contents, templateMap^);
    | _ => cont();
    };
  },
  templatesDir
);
let getTemplate = (name) => {
  let path = Fp.At.(templatesDir / name);
  let pathString = Fp.toString(path);
  if (!StringMap.mem(pathString, templateMap^)) {
    print_endline("!!! Error: Unknown template: " ++ pathString);
    failwith("Unknown Template");
  };
  StringMap.find(pathString, templateMap^);
};

print_endline("Building modules:");

let root = Fp.absoluteExn(outputDir);
let ms = Registry.Modules.get();

let contents =
  Registry.Modules.get()
  |> List.sort((m1: Core.Types.m, m2: Core.Types.m) => compare(m1.priority, m2.priority))
  |> List.rev
  |> List.map((m: Core.Types.m) => {
       print_endline("  - " ++ m.name);
       let contents = Core.Render.m(~getTemplate, m);
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
