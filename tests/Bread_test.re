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
    let actual = string_of_int(Bread.test);
    expect.string(actual).toMatchSnapshot();
  });
});
