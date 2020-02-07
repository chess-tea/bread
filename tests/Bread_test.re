open TestFramework;

describe("Example", ({test}) => {
  test("1", ({expect}) => {
    let actual = 42;
    let expected = 42;
    expect.int(actual).toBe(expected);
  });

  test("2", ({expect}) => {
    let actual = [1, 2];
    expect.list(actual).toEqual([1, 2]);
  });

  test("3", ({expect}) => {
    let actual = Bread.Option.map(x => x + 2, Some(40));

    let actual =
      switch (actual) {
      | Some(x) => string_of_int(x)
      | None => "None"
      };

    expect.string(actual).toMatchSnapshot();
  });
});
