open BreadCore;
open Components;

let make = (moduleName, functorArg, keyType) => {
  <ModuleDef name=moduleName>
    <Raw raw={"module Impl = Caml.Set.Make(" ++ functorArg ++ ");"} />
    <Raw desc="Alias for the set type." raw="type t = Impl.t;" />
    <Raw desc="The empty set." raw="let empty = Impl.empty;" />
    <Function
      name="fromList"
      rebind="Impl.of_list"
      args=["list(" ++ keyType ++ ")"]
      return="t"
      argNames=["list"]
      desc="creates a set from the elements of $1"
    />
    <Function
      name="toList"
      rebind="Impl.elements"
      args=["t"]
      return={"list(" ++ keyType ++ ")"}
      argNames=["set"]
      desc="returns the elements of $1 as a list"
    />
    <Function
      name="fromArray"
      args=["array(" ++ keyType ++ ")"]
      return="t"
      argNames=["array"]
      desc="creates a set from the elements of $1"
      body={({arg}) => {["fromList(Caml.Array.to_list($1));"]}}
    />
    <Function
      name="toArray"
      args=["t"]
      return={"array(" ++ keyType ++ ")"}
      argNames=["set"]
      desc="returns the elements of $1 as an array"
      body={({arg}) => {["Caml.Array.of_list(toList($1));"]}}
    />
    <Function
      name="isEmpty"
      rebind="Impl.is_empty"
      args=["t"]
      return="bool"
      argNames=["set"]
      desc="tests whether $1 is empty"
    />
    <Function
      name="size"
      rebind="Impl.cardinal"
      args=["t"]
      return="int"
      argNames=["set"]
      desc="returns the number of elements in $1"
    />
    <Function
      name="has"
      rebind="Impl.mem"
      args=[keyType, "t"]
      return="bool"
      argNames=["key", "set"]
      desc="tests if $1 is present in $2"
    />
    <Function
      name="add"
      rebind="Impl.add"
      args=[keyType, "t"]
      return="t"
      argNames=["key", "set"]
      desc="returns a new set containing the elements of $2 with $1 added"
    />
    <Function
      name="remove"
      rebind="Impl.remove"
      args=[keyType, "t"]
      return="t"
      argNames=["key", "set"]
      desc="returns a new set containing the elements of $2 with $1 removed"
    />
    <Function
      name="map"
      rebind="Impl.map"
      args=[keyType ++ " => " ++ keyType, "t"]
      return="t"
      argNames=["fn", "set"]
      desc={
        "returns a new set where each element, el, of $2 has been transformed "
        ++ "by calling $1(el)"
      }
    />
  </ModuleDef>;
};

make("Set", "String", "string");
make("IntSet", "Int", "int");
