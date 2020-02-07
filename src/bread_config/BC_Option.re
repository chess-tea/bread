open Core;
open Doc;

<Files>
  <File path=Fp.(At.(dot / "Option.re"))>
    <Let
      name="map"
      doc={
        <Doc>
          <String> "Hello World!" </String>
          <String> "Hello world again!" </String>
        </Doc>
      }>
      "(fn, o) =>"
      "  switch (o) {"
      "  | Some(value) => Some(fn(value))"
      "  | None => None"
      "  }"
    </Let>
  </File>
</Files>;
