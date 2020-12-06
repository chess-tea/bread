type doc =
  | String(string)
  | Bold(string)
  | Italic(string)
  | URL({
      /* TODO: Allow bold/italics in here */
      display: option(string),
      url: string,
    })
  | ReasonRef({
      modules: list(string),
      binding: option(string),
    })
  | Code(string)
  | MultiLineCode(list(string))
  | Break
  | Indent(int)
  | Group(list(doc));

type t = list(doc);
