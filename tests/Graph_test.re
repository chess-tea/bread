open TestFramework;

module Caml = Bread.Caml;
module Graph = Bread.Graph;

// TODO: Add this somewhere?
module MutableGraph = {
  open Bread;

  type t = {
    mutable nodes: Map.t(int),
    mutable nodesRev: IntMap.t(string),
    mutable edges: IntMap.t(IntSet.t),
  };

  let empty = {nodes: Map.empty, nodesRev: IntMap.empty, edges: IntMap.empty};

  let nodeToID = (n, graph) => {
    Map.getExn(n, graph.nodes);
  };

  let idToNode = (id, graph) => {
    IntMap.getExn(id, graph.nodesRev);
  };

  let addNode = (string, graph) =>
    if (!Map.hasKey(string, graph.nodes)) {
      let id = Map.size(graph.nodes);
      graph.nodes = Map.set(string, id, graph.nodes);
      graph.nodesRev = IntMap.set(id, string, graph.nodesRev);
    };

  let addDirected = (u, v, graph) => {
    addNode(u, graph);
    addNode(v, graph);
    let u = Map.getExn(u, graph.nodes);
    let v = Map.getExn(v, graph.nodes);
    if (!IntMap.hasKey(u, graph.edges)) {
      graph.edges = IntMap.set(u, IntSet.empty, graph.edges);
    };
    // TODO: Change from get/set to a single update.
    let edgeSet = IntMap.getExn(u, graph.edges);
    graph.edges = IntMap.set(u, IntSet.add(v, edgeSet), graph.edges);
    ();
  };

  let addUndirected = (u, v, graph) => {
    addDirected(u, v, graph);
    addDirected(v, u, graph);
    ();
  };

  let dfs =
      (
        ~onEnter: string => unit=_node => (),
        ~onExit: string => unit=_node => (),
        root,
        graph,
      ) => {
    let root = nodeToID(root, graph);
    let visited = ref(IntSet.empty);
    let rec helper = curr =>
      if (!IntSet.has(curr, visited^)) {
        let node = idToNode(curr, graph);
        visited := IntSet.add(curr, visited^);
        onEnter(node);
        let nextEdges = IntMap.getExn(curr, graph.edges);
        // TODO: Change to iter/forEach.
        let _ =
          IntSet.map(
            next => {
              helper(next);
              next;
            },
            nextEdges,
          );
        onExit(node);
      };
    helper(root);
  };
};

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
