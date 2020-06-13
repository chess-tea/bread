type fUtils = {arg: int => string};
type mUtils = {moduleName: unit => string};
type mChild = list(mUtils => list(string));
type m = {
  name: string,
  priority: int,
  children: list(mChild),
};
