open TestFramework;

module Caml = Bread.Caml;
module Graph = Bread.Graph;

describe("Graph", ({test}) => {
  test("1", ({expect}) => {
    expect.int(1).toBe(1);
    expect.int(1).toBe(1);
  });

  test("basics", ({expect}) => {
    let g =
      Graph.empty
      |> Graph.addDirected("a", "b")
      |> Graph.addDirected("b", "c")
      |> Graph.addDirected("c", "d");

    let x = Graph.dfs((acc, node) => acc @ [node], [], "a", g);
    expect.list(x).toEqual(["a", "b", "c", "d"]);

    let x = Graph.dfs((acc, node) => acc @ [node], [], "b", g);
    expect.list(x).toEqual(["b", "c", "d"]);
  });

  test("basics 2", ({expect}) => {
    let g =
      Graph.empty
      |> Graph.addDirected("a", "b")
      |> Graph.addDirected("b", "c")
      |> Graph.addDirected("c", "d1")
      |> Graph.addDirected("c", "d2")
      |> Graph.addDirected("c", "d3");

    let x = Graph.dfs((acc, node) => acc @ [node], [], "b", g);
    expect.list(x).toEqual(["b", "c", "d1", "d2", "d3"]);
  });

  test("basics 3", ({expect}) => {
    let g =
      Graph.empty
      |> Graph.addDirected("a", "b")
      |> Graph.addDirected("b", "c")
      |> Graph.addDirected("c", "d1")
      |> Graph.addDirected("c", "d2")
      |> Graph.addDirected("c", "d3")
      |> Graph.addDirected("d1", "e")
      |> Graph.addDirected("d2", "e")
      |> Graph.addDirected("d3", "e");

    let x = Graph.dfs((acc, node) => acc @ [node], [], "b", g);
    expect.list(x).toEqual(["b", "c", "d1", "e", "d2", "d3"]);
  });
});
