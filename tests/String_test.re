open TestFramework;

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
});
