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

  test("replaceAll", ({expect}) => {
    let r = String.replaceAll;
    expect.string(r("a", "b", "1a2a3a")).toEqual("1b2b3b");
    expect.string(r("a2", "b2", "1a2a3a")).toEqual("1b2a3a");
    expect.string(r("a", "b", "aaa")).toEqual("bbb");
    expect.string(r("a", "aa", "aaa")).toEqual("aaaaaa");
    expect.string(r("aa", "x", "aaa")).toEqual("xa");
    expect.string(r("apple", "lemon", "applejuice")).toEqual("lemonjuice");
    expect.string(r("a", "", "aaa")).toEqual("");
    expect.string(r("aa", "", "aaa")).toEqual("a");
    expect.string(r("aa", "", "aaaa")).toEqual("");
    expect.string(r("aaa", "", "aaaa")).toEqual("a");
    expect.string(r("", "a", "123")).toEqual("a1a2a3a");
    expect.string(r("", "", "123")).toEqual("123");
  });

  test("replaceFirst", ({expect}) => {
    let r = String.replaceFirst;
    expect.string(r("a", "b", "1a2a3a")).toEqual("1b2a3a");
    expect.string(r("a2", "b2", "1a2a3a")).toEqual("1b2a3a");
    expect.string(r("a", "b", "aaa")).toEqual("baa");
    expect.string(r("a", "aa", "aaa")).toEqual("aaaa");
    expect.string(r("aa", "x", "aaa")).toEqual("xa");
    expect.string(r("apple", "lemon", "applejuice")).toEqual("lemonjuice");
    expect.string(r("a", "", "aaa")).toEqual("aa");
    expect.string(r("aa", "", "aaa")).toEqual("a");
    expect.string(r("aa", "", "aaaa")).toEqual("aa");
    expect.string(r("aaa", "", "aaaa")).toEqual("a");
    expect.string(r("", "a", "123")).toEqual("a123");
    expect.string(r("", "", "123")).toEqual("123");
  });

  test("replaceLast", ({expect}) => {
    let r = String.replaceLast;
    expect.string(r("a", "b", "1a2a3a")).toEqual("1a2a3b");
    expect.string(r("a2", "b2", "1a2a3a")).toEqual("1b2a3a");
    expect.string(r("a", "b", "aaa")).toEqual("aab");
    expect.string(r("a", "aa", "aaa")).toEqual("aaaa");
    expect.string(r("aa", "x", "aaa")).toEqual("ax");
    expect.string(r("apple", "lemon", "applejuice")).toEqual("lemonjuice");
    expect.string(r("a", "", "aaa")).toEqual("aa");
    expect.string(r("aa", "", "aaa")).toEqual("a");
    expect.string(r("aa", "", "aaaa")).toEqual("aa");
    expect.string(r("aaa", "", "aaaa")).toEqual("a");
    expect.string(r("", "a", "123")).toEqual("123a");
    expect.string(r("", "", "123")).toEqual("123");
  });

  test("trimLeft", ({expect}) => {
    let t = String.trimLeft;
    expect.string(t("")).toEqual("");
    expect.string(t("a")).toEqual("a");
    expect.string(t("abc")).toEqual("abc");
    expect.string(t("abc   ")).toEqual("abc   ");
    expect.string(t("abc   abc")).toEqual("abc   abc");
    expect.string(t(" a")).toEqual("a");
    expect.string(t(" abc")).toEqual("abc");
    expect.string(t(" abc   ")).toEqual("abc   ");
    expect.string(t(" abc   abc")).toEqual("abc   abc");
    expect.string(t("  a")).toEqual("a");
    expect.string(t("  abc")).toEqual("abc");
    expect.string(t("  abc   ")).toEqual("abc   ");
    expect.string(t("  abc   abc")).toEqual("abc   abc");
    expect.string(t(" \na")).toEqual("a");
    expect.string(t(" \nabc")).toEqual("abc");
    expect.string(t(" \tabc   ")).toEqual("abc   ");
    expect.string(t(" \rabc   abc")).toEqual("abc   abc");
    expect.string(t(" \r\n\t\012abc   abc")).toEqual("abc   abc");
  });

  test("trimRight", ({expect}) => {
    let t = String.trimRight;
    expect.string(t("")).toEqual("");
    expect.string(t("a")).toEqual("a");
    expect.string(t("abc")).toEqual("abc");
    expect.string(t("   abc")).toEqual("   abc");
    expect.string(t("abc   abc")).toEqual("abc   abc");
    expect.string(t("a ")).toEqual("a");
    expect.string(t("abc ")).toEqual("abc");
    expect.string(t("   abc ")).toEqual("   abc");
    expect.string(t("abc   abc ")).toEqual("abc   abc");
    expect.string(t("a  ")).toEqual("a");
    expect.string(t("abc  ")).toEqual("abc");
    expect.string(t("   abc  ")).toEqual("   abc");
    expect.string(t("abc   abc  ")).toEqual("abc   abc");
    expect.string(t("a \n ")).toEqual("a");
    expect.string(t("abc \t")).toEqual("abc");
    expect.string(t("   abc\r\r")).toEqual("   abc");
    expect.string(t("abc   abc \n")).toEqual("abc   abc");
    expect.string(t("abc   abc \r\n\t\012")).toEqual("abc   abc");
  });
});
