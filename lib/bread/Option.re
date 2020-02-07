/**
 * This code is generated. Do not modify manually.
 *
 * @generated
 */;

/**
`map(fn, o)` applies `fn` to the value of `o` and returns the result wrapped in an `option`
*/
let map: ('a => 'b, option('a)) => option('b) = (fn, o) =>
  switch (o) {
  | Some(value) => Some(fn(value))
  | None => None
  };
