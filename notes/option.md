# option

- `get`, `getx`
- `map`, `map2`, ...
- `flatMap`, (does `flatMap2` make sense?)
- `forEach`
- `isNone`, `isSome`, `has` (?)
- `makeSome`, `makeNone`
- `equals` (or equals inner?)
- `compare` (or compare inner?)

Ideal definition (todo: implement):

```reason
module Inline = {
  let optionSwitch = (optionName, some, none) => [
    "switch (" ++ optionName ++ ") {",
    "| Some(" ++ optionName ++ ") => " ++ some,
    "| None => " ++ none,
    "}",
  ];
};


<M name="Option">
  <T t="option($1)" args=["value"] opaque=false />
  <F
    name="get"
    args=["$1", "t($1)"]
    return="$1"
    argNames=["default", "option"]
    seeAlso=[]
    body={({arg}) => {
      Inline.optionSwitch(arg(2), arg(2), arg(1))
    }}
  />
</M>
```
