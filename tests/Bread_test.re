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
    let actual = Bread.Option.get(-1, Some(42));

    let expected = 42;

    expect.int(actual).toBe(expected);
  });
});
