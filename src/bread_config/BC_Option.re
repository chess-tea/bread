let test = 42;

module Map = {
  let doc = <Doc> {DocTypes.String("Hello World!")} </Doc>;
  let fn = "(fn, x) => switch (x) { | Some(x) => Some(fn(x)) | None => None }";
};

let functionDefinitions = [(Map.fn, Map.doc)];
