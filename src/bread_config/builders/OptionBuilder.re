open Core;
open Doc;

<Files>
  <File path=Fp.(At.(dot / "Option.re"))>
    <Binding
      name="map"
      t="('a => 'b, option('a)) => option('b)"
      doc={
        <Doc>
          <String>
            "`map(fn, o)` applies `fn` to the value of `o` and "
          </String>
          <String> "returns the result wrapped in an `option`" </String>
        </Doc>
      }>
      "(fn, o) =>"
      "  switch (o) {"
      "  | Some(value) => Some(fn(value))"
      "  | None => None"
      "  }"
    </Binding>
  </File>
</Files>;
