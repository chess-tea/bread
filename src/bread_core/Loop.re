/**
 * Loops from first to last (inclusive);
 */
let loop = (~increment=1, first, last, fn) => {
  let curr = ref(first);
  let resultRev = ref([]);
  while (curr^ <= last) {
    resultRev := [fn(curr^), ...resultRev^];
    curr := curr^ + increment;
  };
  resultRev^ |> Caml.List.rev;
};

/**
 * Like loop but gives the index as a string.
 */
let loopS = (~increment=1, first, last, fn) => {
  loop(~increment, first, last, i => fn(string_of_int(i)));
};
