let test = 42;

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
print_endline("Writing:");

let root = Fp.absoluteExn(outputDir);
let files = Registry.Files.get();
List.iter(fn => fn(root), files);

print_endline("All Done!");
