/**
optionSwitch(name, someName, some, none)
 */
let optionSwitch = (name, someName, some, none) => [
  "switch (" ++ name ++ ") {",
  "| Some(" ++ someName ++ ") => " ++ some,
  "| None => " ++ none,
  "}",
];

/**
resultSwitch(name, okName, ok, errorName, error)
 */
let resultSwitch = (name, okName, ok, errorName, error) => [
  "switch (" ++ name ++ ") {",
  "| Ok(" ++ okName ++ ") => " ++ ok,
  "| Error(" ++ errorName ++ ") => " ++ error,
  "}",
];
