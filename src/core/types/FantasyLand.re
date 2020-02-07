/**
 * https://github.com/fantasyland/fantasy-land
 */;

type setoid= [
  | `Equals
];

type ord = [
  | setoid
  | `Lte
];

type semigroupoid = [
  | `Compose
];

type category = [
  | semigroupoid
  | `ID
];

type semigroup = [
  | `Concat
];

type monoid = [
  | semigroup
  | `Empty
];

type group = [
  | monoid
  | `Invert
];

type filterable = [
  | `Filter
];

type functor_ = [
  | `Map
];

type contravariant = [
  | `Contramap
];

type apply = [
  | functor_
  | `Ap
];

type applicative = [
  | apply
  | `Of
];

type alt = [
  | functor_
  | `Alt
];

type plus = [
  | alt
  | `Zero
];

type alternative = [
  | applicative
  | plus
];

type foldable = [
  | `Reduce
];

type traversable = [
  | functor_
  | foldable
  | `Traverse
];

type chain = [
  | apply
  | `Chain
];

type chainRec = [
  | chain
  | `ChainRec
];

type monad = [
  | applicative
  | chain
];

type extend = [
  | functor_
  | `Extend
];

type comonad = [
  | extend
  | `Extract
];

type bifunctor = [
  | functor_
  | `Bimap
];

type profunctor = [
  | functor_
  | `Promap
];
