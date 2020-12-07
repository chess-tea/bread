open TestFramework;

module Caml = Bread.Caml;
module Map = Bread.Map;

describe("Map", ({test}) => {
  test("1", ({expect}) => {
    expect.int(1).toBe(1);
    expect.int(1).toBe(1);
  });

  test("basics", ({expect}) => {
    let s =
      Map.empty
      |> Map.set("a", 1)
      |> Map.set("a", 2)
      |> Map.set("b", 3)
      |> Map.set("c", 4);

    expect.int(Map.size(s)).toBe(3);
    expect.int(Map.getExn("a", s)).toBe(2);
    expect.int(Map.getExn("b", s)).toBe(3);
    expect.int(Map.getExn("c", s)).toBe(4);
    expect.bool(Map.hasKey("d", s)).toBeFalse();

    let s = Map.remove("a", s);

    expect.int(Map.size(s)).toBe(2);
    expect.bool(Map.hasKey("a", s)).toBeFalse();
    expect.int(Map.getExn("b", s)).toBe(3);
    expect.int(Map.getExn("c", s)).toBe(4);
    expect.bool(Map.hasKey("d", s)).toBeFalse();
  });

  test("creation", ({expect}) => {
    let s = Map.fromList([("a", 1), ("a", 2), ("b", 3), ("c", 4)]);
    expect.int(Map.size(s)).toBe(3);
    expect.int(Map.getExn("a", s)).toBe(2);
    expect.int(Map.getExn("b", s)).toBe(3);
    expect.int(Map.getExn("c", s)).toBe(4);
    expect.bool(Map.hasKey("d", s)).toBeFalse();
  });
});
