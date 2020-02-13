type fUtils = {arg: int => string};
type mUtils = {moduleName: unit => string};
type mChild = mUtils => list(string);
type m = {
  name: string,
  children: list(mChild),
};
