/**
 * This file is generated. Do not modify it manually.
 *
 * To update this file:
 *   - Modify relevant files in: src/bread_config
 *   - Run: esy gen
 *
 * @generated
 */;

module Caml = {
  module Array = Array;
  module List = List;
  module String = String;
  module Scanf = Scanf;
};

module String = {
  /**
Alias for the string type. Useful for using this module with certain Functors
   */
  type t = string;
  /**
The empty string.
   */
  let empty = "";
  
  /**
length(string)

returns the length (number of characters) of string
   */
  let length = Caml.String.length;
  
  /**
compare(a, b)

compares a and b. A negative integer is returned when a < b, a positive integer is returned when a > b, and 0 is returned when a equals b
   */
  let compare = Caml.String.compare;
  
  /**
equal(a, b)

tests for equality between a and b
   */
  let equal = Caml.String.equal;
  
  /**
get(string, i)

returns the character in string at index i. This function can also be called using the syntax: string.[i]
   */
  let get = Caml.String.get;
  
  /**
charAt(i, string)

returns the character in string at index i
   */
  let charAt = (i, string) => {
    Caml.String.get(string, i);
  };
  
  /**
make(length, c)

returns a new string with length length, filled with the character c
   */
  let make = Caml.String.make;
  
  /**
init(length, fn)

returns a new string with length length, with the character at each index, i, defined by fn(i)
   */
  let init = Caml.String.init;
  
  /**
fromChar(c)

returns a new string of length 1 containing only the character c
   */
  let fromChar = (c) => {
    let s = Caml.String.make(1, c);
    s;
  };
  
  /**
fromCharArray(array)

returns a new string containing the characters in array
   */
  let fromCharArray = (array) => {
    let n = Caml.Array.length(array);
    let s = Caml.String.init(n, i => array[i]);
    s;
  };
  
  /**
fromCharList(list)

returns a new string containing the characters in list
   */
  let fromCharList = (list) => {
    let list = Caml.Array.of_list(list);
    fromCharArray(list);
  };
  
  /**
toCharArray(string)

returns an array of the characters in string
   */
  let toCharArray = (string) => {
    let n = Caml.String.length(string);
    let arr = Caml.Array.init(n, i => Caml.String.get(string, i));
    arr;
  };
  
  /**
toCharList(string)

returns a list of the characters in string
   */
  let toCharList = (string) => {
    let arr = toCharArray(string);
    let list = Caml.Array.to_list(arr);
    list;
  };
  
  /**
toUppercase(string)

returns a copy of string with all lowercase letters converted to uppercase using the US-ASCII character set
   */
  let toUppercase = Caml.String.uppercase_ascii;
  
  /**
toLowercase(string)

returns a copy of string with all uppercase letters converted to lowercase using the US-ASCII character set
   */
  let toLowercase = Caml.String.lowercase_ascii;
  
  /**
concat(separator, list)

concatenates all elements of list together with separator inserted between each pair of elements
   */
  let concat = Caml.String.concat;
  
  /**
join(separator, list)

concatenates all elements of list together with separator inserted between each pair of elements
   */
  let join = Caml.String.concat;
  
  /**
escape(string)

Returns a copy of string with special characters represented by escape sequences following the lexical conventions of OCaml. All characters outside the ASCII printable range (32...126) are escaped, as well as backslash and double-quote.
   */
  let escape = Caml.String.escaped;
  
  /**
unescape(string)

Returns a copy of string with escape sequences, following the lexical conventions of OCaml, replaced by their corresponding special characters.
   */
  let unescape = Caml.Scanf.unescaped;
  
  /**
slice(i, j, string)

returns a substring of string between given indices i and j
   */
  let slice = (i, j, string) => {
    let n = Caml.String.length(string)
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
      Caml.String.sub(string, i, j - i);
    };
  };
  
  /**
sliceToEnd(i, string)

returns a substring of string from index i to the end
   */
  let sliceToEnd = (i, string) => {
    slice(i, Caml.String.length(string), string);
  };
  
  /*
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
  
  let split = (token, string) => {
    let tn = Caml.String.length(token);
    if (tn === 0) {
      Caml.List.map(fromChar, toCharList(string));
    } else {
      let indexOf = indexOfInt(token);
      let result = ref([]);
      let consider = ref(string);
      let break = ref(false);
      while (! break^) {
        let i = indexOf(consider^);
        switch (i) {
        | (-1) =>
          result := [consider^, ...result^];
          consider := "";
          break := true;
          ();
        | _ =>
          result := [slice(0, i, consider^), ...result^];
          consider := sliceToEnd(i + tn, consider^);
        };
      };
      Caml.List.rev(result^);
    };
  };
  
  /**
replaceFirst(token, replacement, string)

replaces the first occurence of token in string with replacement
   */
  let replaceFirst = (token, replacement, string) => {
    let i = indexOfInt(token, string);
    if (i === -1) {
      string;
    } else {
      let tn = length(token);
      slice(0, i, string) ++ replacement ++ sliceToEnd(i + tn, string);
    };
  };
  
  /**
replaceLast(token, replacement, string)

replaces the last occurence of token in string with replacement
   */
  let replaceLast = (token, replacement, string) => {
    let i = lastIndexOfInt(token, string);
    if (i === -1) {
      string;
    } else {
      let tn = length(token);
      slice(0, i, string) ++ replacement ++ sliceToEnd(i + tn, string);
    };
  };
  
  /**
replaceAll(token, replacement, string)

replaces all occurences of token in string with replacement
   */
  let replaceAll = (token, replacement, string) => {
    let parts = split(token, string);
    let combined = concat(replacement, parts);
    let combined =
      if (token == "") {
        if (string == "") {
          replacement ++ combined;
        } else {
          replacement ++ combined ++ replacement;
        };
      } else {
        combined;
      };
    combined;
  };
  
};

module Result = {
  
  /**
isOk(result)

returns whether result is Ok
   */
  let isOk = (result) => {
    switch (result) {
    | Ok(_) => true
    | Error(_) => false
    }
  };
  
  /**
isError(result)

returns whether result is Error
   */
  let isError = (result) => {
    switch (result) {
    | Ok(_) => false
    | Error(_) => true
    }
  };
  
};

module Option = {
  
  /**
isNone(option)

returns whether option is None
   */
  let isNone = (option) => {
    switch (option) {
    | Some(_) => false
    | None => true
    }
  };
  
  /**
isSome(option)

returns whether option is Some
   */
  let isSome = (option) => {
    switch (option) {
    | Some(_) => true
    | None => false
    }
  };
  
  /**
makeNone(_value)

ignores _value and always returns None
   */
  let makeNone = (_value) => {
    None
  };
  
  /**
makeSome(value)

returns Some(value)
   */
  let makeSome = (value) => {
    Some(value)
  };
  
  /**
get(default, option)

returns the value contained within option if it exists; otherwise, returns default
   */
  let get = (default, option) => {
    switch (option) {
    | Some(option) => option
    | None => default
    }
  };
  
  /**
getExn(option)

returns the value contained within option if it exists; otherwise, raises exception
   */
  let getExn = (option) => {
    switch (option) {
    | Some(option) => option
    | None => failwith("Unexpected None")
    }
  };
  
  /**
getLazy(defaultFn, option)

returns the value contained within option if it exists; otherwise, returns the result of calling defaultFn
   */
  let getLazy = (defaultFn, option) => {
    switch (option) {
    | Some(option) => option
    | None => defaultFn()
    }
  };
  
  /**
filterKeep(testFn, option)

keeps the value and option unchanged if testFn is true when called with option's value; otherwise, returns None
   */
  let filterKeep = (testFn, option) => {
    switch (option) {
    | Some(value) when testFn(value) => option
    | _ => None
    }
  };
  
  /**
filterDrop(testFn, option)

drops the value and returns None if testFn is true when called with option's value; otherwise, returns option unchanged
   */
  let filterDrop = (testFn, option) => {
    switch (option) {
    | Some(value) when testFn(value) => option
    | _ => None
    }
  };
  
  /**
toResult(noneError, option)

converts option to a result. Returns Ok(value) if option is Some(value), and Error(noneError) otherwise
   */
  let toResult = (noneError, option) => {
    switch (option) {
    | Some(value) => Ok(value)
    | None => Error(noneError)
    }
  };
  
  /**
fromResult(result)

converts result to an option. Returns Some(value) if result is Ok(value), and None otherwise
   */
  let fromResult = (result) => {
    switch (result) {
    | Ok(value) => Some(value)
    | Error(_) => None
    }
  };
  
  /**
map(fn, option)

changes value of an option according to fn if all inputs are Some value
   */
  let map = (fn, option) => {
    switch (option) {
    | (Some(option)) =>
      Some(fn(option))
    | _ => None
    }
  };
  
  /**
map2(fn, option1, option2)

changes value of an option according to fn if all inputs are Some value
   */
  let map2 = (fn, option1, option2) => {
    switch (option1, option2) {
    | (Some(option1), Some(option2)) =>
      Some(fn(option1, option2))
    | _ => None
    }
  };
  
  /**
map3(fn, option1, option2, option3)

changes value of an option according to fn if all inputs are Some value
   */
  let map3 = (fn, option1, option2, option3) => {
    switch (option1, option2, option3) {
    | (Some(option1), Some(option2), Some(option3)) =>
      Some(fn(option1, option2, option3))
    | _ => None
    }
  };
  
  /**
map4(fn, option1, option2, option3, option4)

changes value of an option according to fn if all inputs are Some value
   */
  let map4 = (fn, option1, option2, option3, option4) => {
    switch (option1, option2, option3, option4) {
    | (Some(option1), Some(option2), Some(option3), Some(option4)) =>
      Some(fn(option1, option2, option3, option4))
    | _ => None
    }
  };
  
  /**
map5(fn, option1, option2, option3, option4, option5)

changes value of an option according to fn if all inputs are Some value
   */
  let map5 = (fn, option1, option2, option3, option4, option5) => {
    switch (option1, option2, option3, option4, option5) {
    | (Some(option1), Some(option2), Some(option3), Some(option4), Some(option5)) =>
      Some(fn(option1, option2, option3, option4, option5))
    | _ => None
    }
  };
  
  /**
map6(fn, option1, option2, option3, option4, option5, option6)

changes value of an option according to fn if all inputs are Some value
   */
  let map6 = (fn, option1, option2, option3, option4, option5, option6) => {
    switch (option1, option2, option3, option4, option5, option6) {
    | (Some(option1), Some(option2), Some(option3), Some(option4), Some(option5), Some(option6)) =>
      Some(fn(option1, option2, option3, option4, option5, option6))
    | _ => None
    }
  };
  
  /**
map7(fn, option1, option2, option3, option4, option5, option6, option7)

changes value of an option according to fn if all inputs are Some value
   */
  let map7 = (fn, option1, option2, option3, option4, option5, option6, option7) => {
    switch (option1, option2, option3, option4, option5, option6, option7) {
    | (Some(option1), Some(option2), Some(option3), Some(option4), Some(option5), Some(option6), Some(option7)) =>
      Some(fn(option1, option2, option3, option4, option5, option6, option7))
    | _ => None
    }
  };
  
  /**
flatMap(fn, option)

changes value of an option according to fn if all inputs are Some value
   */
  let flatMap = (fn, option) => {
    switch (option) {
    | (Some(option)) =>
      fn(option)
    | _ => None
    }
  };
  
  /**
flatMap2(fn, option1, option2)

changes value of an option according to fn if all inputs are Some value
   */
  let flatMap2 = (fn, option1, option2) => {
    switch (option1, option2) {
    | (Some(option1), Some(option2)) =>
      fn(option1, option2)
    | _ => None
    }
  };
  
  /**
flatMap3(fn, option1, option2, option3)

changes value of an option according to fn if all inputs are Some value
   */
  let flatMap3 = (fn, option1, option2, option3) => {
    switch (option1, option2, option3) {
    | (Some(option1), Some(option2), Some(option3)) =>
      fn(option1, option2, option3)
    | _ => None
    }
  };
  
  /**
flatMap4(fn, option1, option2, option3, option4)

changes value of an option according to fn if all inputs are Some value
   */
  let flatMap4 = (fn, option1, option2, option3, option4) => {
    switch (option1, option2, option3, option4) {
    | (Some(option1), Some(option2), Some(option3), Some(option4)) =>
      fn(option1, option2, option3, option4)
    | _ => None
    }
  };
  
  /**
flatMap5(fn, option1, option2, option3, option4, option5)

changes value of an option according to fn if all inputs are Some value
   */
  let flatMap5 = (fn, option1, option2, option3, option4, option5) => {
    switch (option1, option2, option3, option4, option5) {
    | (Some(option1), Some(option2), Some(option3), Some(option4), Some(option5)) =>
      fn(option1, option2, option3, option4, option5)
    | _ => None
    }
  };
  
  /**
flatMap6(fn, option1, option2, option3, option4, option5, option6)

changes value of an option according to fn if all inputs are Some value
   */
  let flatMap6 = (fn, option1, option2, option3, option4, option5, option6) => {
    switch (option1, option2, option3, option4, option5, option6) {
    | (Some(option1), Some(option2), Some(option3), Some(option4), Some(option5), Some(option6)) =>
      fn(option1, option2, option3, option4, option5, option6)
    | _ => None
    }
  };
  
  /**
flatMap7(fn, option1, option2, option3, option4, option5, option6, option7)

changes value of an option according to fn if all inputs are Some value
   */
  let flatMap7 = (fn, option1, option2, option3, option4, option5, option6, option7) => {
    switch (option1, option2, option3, option4, option5, option6, option7) {
    | (Some(option1), Some(option2), Some(option3), Some(option4), Some(option5), Some(option6), Some(option7)) =>
      fn(option1, option2, option3, option4, option5, option6, option7)
    | _ => None
    }
  };
  
};

module CamlList = {
  
  /**
isEmpty(list)

returns whether list is empty
   */
  let isEmpty = (list) => {
    switch (list) {
    | [] => true
    | _ => false
    }
  };
  
};

module CamlArray = {
  
  /**
isEmpty(array)

returns whether array is empty
   */
  let isEmpty = (array) => {
    Caml.Array.length(array) === 0
  };
  
};

