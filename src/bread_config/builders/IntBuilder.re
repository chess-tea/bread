open BreadCore;
open Components;

<ModuleDef name="Int" priority=90>
  <Raw
    desc={
      "Alias for the int type. Useful for using this module with certain "
      ++ "Functors"
    }
    raw="type t = int;"
  />
  <Function
    name="compare"
    rebind="Caml.Int.compare"
    args=["t", "t"]
    return="int"
    argNames=["a", "b"]
    desc=Const.compareDesc
  />
  <Function
    name="equal"
    rebind="Caml.Int.equal"
    args=["t", "t"]
    return="bool"
    argNames=["a", "b"]
    desc=Const.equalDesc
  />
</ModuleDef>;
