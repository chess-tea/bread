module Files = {
  type t = Fp.t(Fp.absolute) => unit;

  module Private = {
    let items: ref(list(t)) = ref([]);
  };

  let add = item => Private.items := [item, ...Private.items^];

  let get = () => Private.items^;
};
