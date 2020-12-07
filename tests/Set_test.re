open TestFramework;

module Caml = Bread.Caml;
module Set = Bread.Set;

describe("Set", ({test}) => {
  test("1", ({expect}) => {
    expect.int(1).toBe(1);
    expect.int(1).toBe(1);
  });

  test("basics", ({expect}) => {
    let s =
      Set.empty
      |> Set.add("a")
      |> Set.add("a")
      |> Set.add("b")
      |> Set.add("c");

    expect.int(Set.size(s)).toBe(3);
    expect.bool(Set.has("a", s)).toBeTrue();
    expect.bool(Set.has("b", s)).toBeTrue();
    expect.bool(Set.has("c", s)).toBeTrue();
    expect.bool(Set.has("A", s)).toBeFalse();
    expect.bool(Set.has("d", s)).toBeFalse();

    let s = Set.remove("a", s);

    expect.int(Set.size(s)).toBe(2);
    expect.bool(Set.has("a", s)).toBeFalse();
    expect.bool(Set.has("b", s)).toBeTrue();
    expect.bool(Set.has("c", s)).toBeTrue();
    expect.bool(Set.has("A", s)).toBeFalse();
    expect.bool(Set.has("d", s)).toBeFalse();

    let s = Set.map(el => el ++ el, s);

    expect.int(Set.size(s)).toBe(2);
    expect.bool(Set.has("b", s)).toBeFalse();
    expect.bool(Set.has("c", s)).toBeFalse();
    expect.bool(Set.has("bb", s)).toBeTrue();
    expect.bool(Set.has("cc", s)).toBeTrue();
  });
});
