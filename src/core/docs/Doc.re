
let createElement = (
  ~openToken="/**",
  ~lineLength=80,
  ~endingSemicolon=false,
  ~children=DocTypes.t,
  _: unit,
): string => {
  let _ = children;
  "Hello World!";
};
