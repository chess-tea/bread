open BreadCore;
open Components;

let make = (moduleName, functorArg, keyType) => {
  <ModuleDef name=moduleName priority=25>
    <Raw raw={"module Impl = Caml.Map.Make(" ++ functorArg ++ ");"} />
    <Raw
      desc="Alias for the map type."
      raw="type t('value) = Impl.t('value);"
    />
    <Raw desc="The empty map." raw="let empty = Impl.empty;" />
    <Function
      name="isEmpty"
      rebind="Impl.is_empty"
      args=["t('value)"]
      return="bool"
      argNames=["map"]
      desc="tests whether $1 is empty"
    />
    <Function
      name="size"
      rebind="Impl.cardinal"
      args=["t('value)"]
      return="int"
      argNames=["map"]
      desc="returns the number of entries in $1"
    />
    <Function
      name="hasKey"
      rebind="Impl.mem"
      args=[keyType, "t('value)"]
      return="bool"
      argNames=["key", "map"]
      desc="tests if the key $1 is present in $2"
    />
    <Function
      name="get"
      rebind="Impl.find_opt"
      args=[keyType, "t('value)"]
      return="option('value)"
      argNames=["key", "map"]
      desc="returns Some(value) associated with $1 if it exists in $2, None otherwise"
    />
    <Function
      name="getExn"
      rebind="Impl.find"
      args=[keyType, "t('value)"]
      return="option('value)"
      argNames=["key", "map"]
      desc="returns the value associated with $1 if it exists in $2, raises Not_found otherwise"
    />
    <Function
      name="set"
      rebind="Impl.add"
      args=[keyType, "'value", "t('value)"]
      return="t('value)"
      argNames=["key", "value", "map"]
      desc="returns a new map containing the entries of $3 with the value of $1 set to $2"
    />
    <Function
      name="remove"
      rebind="Impl.remove"
      args=[keyType, "t('value)"]
      return="t('value)"
      argNames=["key", "map"]
      desc="returns a new map containing the entries of $2 with the entry of key $1 removed"
    />
    <Function
      name="map"
      rebind="Impl.map"
      args=["'valueOld => 'valueNew", "t('valueOld)"]
      return="t('valueNew)"
      argNames=["fn", "map"]
      desc={
        "returns a new map with the same keys as $2 where each value, v, has "
        ++ "been transformed by calling $1(v)"
      }
    />
    <Function
      name="mapi"
      rebind="Impl.mapi"
      args=["(" ++ keyType ++ ", 'valueOld) => 'valueNew", "t('valueOld)"]
      return="t('valueNew)"
      argNames=["fn", "map"]
      desc={
        "returns a new map with the same keys as $2 where each value, v, has "
        ++ "been transformed by calling $1(key, v)"
      }
    />
    <Function
      name="fromList"
      args=["list((" ++ keyType ++ ", 'value))"]
      return="t('value)"
      argNames=["list"]
      desc={
        "creates a map from the entries of $1, if there are duplicate keys, "
        ++ "then the map will contain the value occuring last in $1"
      }
      body={({arg}) => {
        [
          "Caml.List.fold_left(",
          "  (m, (key, value)) => Impl.add(key, value, m),",
          "  Impl.empty,",
          "  $1,",
          ");",
        ]
      }}
    />
    <Function
      name="toList"
      rebind="Impl.bindings"
      args=["t('value)"]
      return={"list((" ++ keyType ++ ", 'value))"}
      argNames=["map"]
      desc="returns the entries of $1 as a list"
    />
    <Function
      name="fromArray"
      args=["array((" ++ keyType ++ ", 'value))"]
      return="t('value)"
      argNames=["array"]
      desc={
        "creates a map from the entries of $1, if there are duplicate keys, "
        ++ "then the map will contain the value occuring last in $1"
      }
      body={({arg}) => {["fromList(Caml.Array.to_list($1));"]}}
    />
    <Function
      name="toArray"
      args=["t('value)"]
      return={"array((" ++ keyType ++ ", 'value))"}
      argNames=["map"]
      desc="returns the entries of $1 as an array"
      body={({arg}) => {["Caml.Array.of_list(toList($1));"]}}
    />
  </ModuleDef>;
};

make("Map", "String", "string");
make("IntMap", "Int", "int");
