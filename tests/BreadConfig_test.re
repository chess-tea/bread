open TestFramework;

open Core;

describe("Bread Config", ({test}) => {
  ();

  test("option builder", ({expect}) => {
    let optionFns = Registry.Modules.get();
    let contents =
      optionFns
      |> Caml.List.map(Components.Render.render)
      |> Caml.List.flatten
      |> Caml.String.concat("\n");
    let contents = contents ++ "\n";
    expect.string(contents).toMatchSnapshot();
  });
});
