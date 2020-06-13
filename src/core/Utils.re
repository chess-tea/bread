let replaceDollars = (fn, n, string) => {
  let i = ref(n);
  let result = ref(string);
  /* Traverse in reverse order so that $10 is replaces before $1 */
  while (i^ > 0) {
    result := String2.replaceAll("$" ++ string_of_int(i^), fn(i^), result^);
    decr(i);
  };
  result^;
};