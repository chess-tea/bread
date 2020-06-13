open Types;

let commas = String.concat(", ");

let indent = lines => {
  let inComment = ref(false);
  let lines =
    Caml.List.map(
      line => {
        let trimmed = String.trim(line);
        let n = String.length(trimmed);

        if (n >= 2 && trimmed.[n - 2] === '*' && trimmed.[n - 1] === '/') {
          inComment := false;
        };

        // Need to compute result before turning off inComment.
        let result =
          if (inComment^) {
            line;
          } else {
            "  " ++ line;
          };

        if (n >= 3 && trimmed.[0] === '/' && trimmed.[1] === '*' && trimmed.[2] === '*') {
          inComment := true;
        };

        result;
      },
      lines,
    );
  lines;
};

let m = (m: m): list(string) => {
  let mUtils: mUtils = {moduleName: () => m.name};
  let moduleOpen = ["module " ++ m.name ++ " = {"];
  let moduleInner =
    m.children
    |> Caml.List.flatten
    |> Caml.List.map(child => child(mUtils))
    |> Caml.List.flatten;
  let moduleClose = ["};", ""];
  moduleOpen @ indent(moduleInner) @ moduleClose;
};
