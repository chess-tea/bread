/**
optionSwitch(optionSwitch, optionMatch, some, none)
 */
let optionSwitch = (optionSwitch, optionMatch, some, none) => [
  "switch (" ++ optionSwitch ++ ") {",
  "| Some(" ++ optionMatch ++ ") => " ++ some,
  "| None => " ++ none,
  "}",
];
