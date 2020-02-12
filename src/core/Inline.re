let optionSwitch = (optionName, some, none) => [
  "switch (" ++ optionName ++ ") {",
  "| Some(" ++ optionName ++ ") => " ++ some,
  "| None => " ++ none,
  "}",
];
