open TestFramework;

module Caml = Bread.Caml;
module String = Bread.String;

describe("String", ({test}) => {
  test("length", ({expect}) => {
    expect.int(String.length("01234")).toBe(5);
    expect.int(String.length("012345678")).toBe(9);
  });

  test("get", ({expect}) => {
    expect.string("01234".[3] |> String.fromChar).toEqual("3");
    expect.string("01234".[1] |> String.fromChar).toEqual("1");
  });

  test("split", ({expect}) => {
    let s = String.split;
    expect.list(s("-", "1-2-3")).toEqual(["1", "2", "3"]);
    expect.list(s(", ", "1, 2, 3")).toEqual(["1", "2", "3"]);
    expect.list(s("xxx", "123xxx456xxx3xxx789")).toEqual([
      "123",
      "456",
      "3",
      "789",
    ]);
    expect.list(s("", "123")).toEqual(["1", "2", "3"]);
    expect.list(s("1", "123")).toEqual(["", "23"]);
    expect.list(s("2", "123")).toEqual(["1", "3"]);
    expect.list(s("3", "123")).toEqual(["12", ""]);
    expect.list(s("1", "1231")).toEqual(["", "23", ""]);
    expect.list(s("11", "112311")).toEqual(["", "23", ""]);
    expect.list(s("11", "11123111")).toEqual(["", "123", "1"]);
  });
});
