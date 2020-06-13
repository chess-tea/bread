type t = string;

let slice = (i, j, s) => {
  let n = Caml.String.length(s);
  /* Resolve indices to final positions. */
  let i = i < 0 ? i + n : i;
  let i = i < 0 ? 0 : i;
  let i = i > n ? n : i;
  let j = j < 0 ? j + n : j;
  let j = j < 0 ? 0 : j;
  let j = j > n ? n : j;
  if (i >= j) {
    "";
  } else {
    Caml.String.sub(s, i, j - i);
  };
};

let sliceToEnd = (i, s) => slice(i, Caml.String.length(s), s);

/**
 *  Returns the index of the first occurrence of string `needle` in string
 *  `haystack`. If not found, returns -1.
 *
 *  An implementation of the Knuth-Morris-Pratt (KMP) algorithm.
 */
let indexOfInternal = (needle, needleAt) => {
  /* see Wikipedia pseudocode */
  let needle_len = Caml.String.length(needle);
  if (needle_len === 0) {
    (_, _) => 0;
  } else {
    let table = Caml.Array.make(needle_len, 0);
    table[0] = (-1);
    let pos = ref(2)
    and cnd = ref(0);
    while (pos^ < needle_len) {
      if (needleAt(pos^ - 1) === needleAt(cnd^)) {
        table[pos^] = cnd^ + 1;
        incr(pos);
        incr(cnd);
      } else if (cnd^ > 0) {
        cnd := table[cnd^];
      } else {
        table[pos^] = 0;
        incr(pos);
      };
    };
    (haystack, haystackAt) => {
      let len = Caml.String.length(haystack);
      let p = ref(0);
      let q = ref(0);
      while (p^ < len && q^ < needle_len) {
        if (haystackAt(p^) === needleAt(q^)) {
          incr(p);
          incr(q);
        } else if (q^ === 0) {
          incr(p);
        } else {
          q := table[q^];
        };
      };
      if (q^ >= needle_len) {
        p^ - needle_len;
      } else {
        (-1);
      };
    };
  };
};

let indexOfInt = needle => {
  let needleAt = i => needle.[i];
  haystack => {
    let haystackAt = i => haystack.[i];
    let index = indexOfInternal(needle, needleAt, haystack, haystackAt);
    index;
  };
};

let indexOf = needle => {
  let indexOfIntPartial = indexOfInt(needle);
  haystack => {
    let result = indexOfIntPartial(haystack);
    if (result === (-1)) {
      None;
    } else {
      Some(result);
    };
  };
};

let lastIndexOfInt = needle => {
  let needleLen = Caml.String.length(needle);
  /* This lets us simulate reversed strings without a memory allocation */
  let needleAt = i => needle.[needleLen - 1 - i];
  let indexOfInternalPartial = indexOfInternal(needle, needleAt);
  haystack => {
    let haystackLen = Caml.String.length(haystack);
    let haystackAt = i => haystack.[haystackLen - 1 - i];
    let index = indexOfInternalPartial(haystack, haystackAt);
    /* We get a "reversed" index, so we have to un-reverse it at the end. */
    index === (-1) ? index : haystackLen - needleLen - index;
  };
};

let lastIndexOf = needle => {
  let lastIndexOfIntPartial = lastIndexOfInt(needle);
  haystack => {
    let result = lastIndexOfIntPartial(haystack);
    if (result === (-1)) {
      None;
    } else {
      Some(result);
    };
  };
};

let contains = needle => {
  let indexOfIntPartial = indexOfInt(needle);
  haystack => indexOfIntPartial(haystack) !== (-1);
};

let includes = ();

let substring = ();

let count = ();

let size = ();

let length = Caml.String.length;

let isEmpty = s => length(s) === 0;

let emptyString = "";

let isWhiteSpace = c =>
  switch (c) {
  | ' '
  /* Vertical tab */
  | '\011'
  /* Form feed */
  | '\012'
  | '\r'
  | '\n'
  | '\t' => true
  | _ => false
  };

let trim = s => {
  let n = Caml.String.length(s);
  let l = ref(0);
  while (l^ < n && isWhiteSpace(s.[l^])) {
    incr(l);
  };
  if (l^ === n) {
    emptyString;
  } else {
    let r = ref(n - 1);
    while (r^ >= 0 && isWhiteSpace(s.[r^])) {
      decr(r);
    };
    if (l^ === 0 && r^ === n - 1) {
      s;
    } else {
      slice(l^, r^ + 1, s);
    };
  };
};

let trimLeft = s => {
  let n = Caml.String.length(s);
  let l = ref(0);
  while (l^ < n && isWhiteSpace(s.[l^])) {
    incr(l);
  };
  if (l^ === n) {
    emptyString;
  } else if (l^ === 0) {
    s;
  } else {
    slice(l^, n, s);
  };
};

let trimRight = s => {
  let n = Caml.String.length(s);
  let r = ref(n - 1);
  while (r^ >= 0 && isWhiteSpace(s.[r^])) {
    decr(r);
  };
  if (r^ === (-1)) {
    emptyString;
  } else if (r^ === n - 1) {
    s;
  } else {
    slice(0, r^ + 1, s);
  };
};

let get = (s, index) =>
  if (index < 0 || index >= length(s)) {
    None;
  } else {
    Some(Caml.String.get(s, index));
  };

let endsWith = (needle, haystack) => {
  let hLen = length(haystack);
  let nLen = length(needle);
  if (nLen > hLen) {
    false;
  } else {
    let hIndex = ref(hLen - nLen);
    let nIndex = ref(0);
    let result = ref(true);
    while (result^ && nIndex^ < nLen) {
      if (haystack.[hIndex^] !== needle.[nIndex^]) {
        result := false;
      };
      incr(hIndex);
      incr(nIndex);
    };
    result^;
  };
};

let startsWith = (needle, haystack) => {
  let hLen = length(haystack);
  let nLen = length(needle);
  if (nLen > hLen) {
    false;
  } else {
    let hIndex = ref(0);
    let nIndex = ref(0);
    let result = ref(true);
    while (result^ && nIndex^ < nLen) {
      if (haystack.[hIndex^] !== needle.[nIndex^]) {
        result := false;
      };
      incr(hIndex);
      incr(nIndex);
    };
    result^;
  };
};

let repeat = (count, s) => {
  let n = Caml.String.length(s);
  if (count <= 0 || n === 0) {
    "";
  } else {
    Caml.String.init(count * n, i => s.[i mod n]);
  };
};

let replaceFirst = (substr, newSubstr, haystack) => {
  let substrLen = length(substr);
  if (substrLen === 0) {
    haystack;
  } else {
    let start = indexOf(substr, haystack);
    switch (start) {
    | Some(index) =>
      let prefix = slice(0, index, haystack);
      let suffix = sliceToEnd(index + substrLen, haystack);
      prefix ++ newSubstr ++ suffix;
    | None => haystack
    };
  };
};

let toCharArray = s => {
  let result = Caml.Array.make(length(s), 'X');
  Caml.String.iteri((i, c) => result[i] = c, s);
  result;
};

let splitList = (delim, s) => {
  let delimLen = length(delim);
  if (delimLen === 0) {
    ();
    /* Create 1-length strings for each character. */
    toCharArray(s)
    |> Caml.Array.map(Caml.String.make(1))
    |> Caml.Array.to_list;
  } else {
    /*
     * Always want the indexOf delim. This partial application allows indexOf
     * to optimize any pre-processing on the needle.
     */
    let indexOf = indexOf(delim);
    let resultRev = ref([]);
    let haystack = ref(s);
    let break = ref(false);
    while (! break^) {
      /*
       * The repeated indexOf is not the most efficient, but will actually be
       * reasonable. indexOf will stop on the first index found so it won't
       * progress all the way through the string each time.
       */
      let index = indexOf(haystack^);
      switch (index) {
      | Some(index) =>
        /* Add part before the delim to the result. */
        let prefix = slice(0, index, haystack^);
        resultRev := [prefix, ...resultRev^];
        /* Keep searching the part after the delim. */
        let suffix = sliceToEnd(index + delimLen, haystack^);
        haystack := suffix;
      | None =>
        break := true;
        resultRev := [haystack^, ...resultRev^];
      };
    };
    resultRev^ |> Caml.List.rev;
  };
};

let replaceAll = (substr, newSubstr, haystack) => {
  let substrLen = length(substr);
  if (substrLen === 0) {
    haystack;
  } else {
    let parts = splitList(substr, haystack);
    Caml.String.concat(newSubstr, parts);
  };
};

let split = (delim, s) => splitList(delim, s) |> Caml.Array.of_list;

let join = (delim, strings) =>
  strings |> Caml.Array.to_list |> Caml.String.concat(delim);

let joinList = (delim, strings) => Caml.String.concat(delim, strings);

let toString = str => str;
