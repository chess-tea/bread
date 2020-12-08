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
  module Char = Char;
  module Int = Int;
  module List = List;
  module Map = Map;
  module Set = Set;
  module String = String;
  module Scanf = Scanf;
};

module Int = {
  /**
Alias for the int type. Useful for using this module with certain Functors
   */
  type t = int;
  
  /**
compare(a, b)

compares a and b. A negative integer is returned when a < b, a positive integer is returned when a > b, and 0 is returned when a equals b
   */
  let compare = Caml.Int.compare;
  
  /**
equal(a, b)

tests for equality between a and b
   */
  let equal = Caml.Int.equal;
  
};

module Char = {
  /**
Alias for the char type. Useful for using this module with certain Functors
   */
  type t = char;
  
  /**
compare(a, b)

compares a and b. A negative integer is returned when a < b, a positive integer is returned when a > b, and 0 is returned when a equals b
   */
  let compare = Caml.Char.compare;
  
  /**
equal(a, b)

tests for equality between a and b
   */
  let equal = Caml.Char.equal;
  
  /**
isWhitespace(c)

tests if c is a whitespace character: ' ', '\012', '\n', '\r', or '\t'
   */
  let isWhitespace = (c) => {
    switch (c) {
    | ' '
    | '\012'
    | '\n'
    | '\r'
    | '\t' => true
    | _ => false
    };
  };
  
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
  
  /**
trim(string)

returns a copy of string with whitespace removed from the front and back
   */
  let trim = Caml.String.trim;
  
  /**
trimLeft(string)

returns a copy of string with whitespace removed from the front
   */
  let trimLeft = (string) => {
    let n = length(string);
    let i = ref(0);
    let break = ref(false);
    while (!break^ && i^ < n) {
      if (!Char.isWhitespace(string.[i^])) {
        break := true;
      } else {
        incr(i);
      };
    };
    sliceToEnd(i^, string);
  };
  
  /**
trimRight(string)

returns a copy of string with whitespace removed from the back
   */
  let trimRight = (string) => {
    let n = length(string);
    let i = ref(n - 1);
    let break = ref(false);
    while (!break^ && i^ >= 0) {
      if (!Char.isWhitespace(string.[i^])) {
        break := true;
      } else {
        decr(i);
      };
    };
    slice(0, i^ + 1, string);
  };
  
};

module Set = {
  module Impl = Caml.Set.Make(String);
  /**
Alias for the set type.
   */
  type t = Impl.t;
  /**
The empty set.
   */
  let empty = Impl.empty;
  
  /**
fromList(list)

creates a set from the elements of list
   */
  let fromList = Impl.of_list;
  
  /**
toList(set)

returns the elements of set as a list
   */
  let toList = Impl.elements;
  
  /**
fromArray(array)

creates a set from the elements of array
   */
  let fromArray = (array) => {
    fromList(Caml.Array.to_list(array));
  };
  
  /**
toArray(set)

returns the elements of set as an array
   */
  let toArray = (set) => {
    Caml.Array.of_list(toList(set));
  };
  
  /**
isEmpty(set)

tests whether set is empty
   */
  let isEmpty = Impl.is_empty;
  
  /**
size(set)

returns the number of elements in set
   */
  let size = Impl.cardinal;
  
  /**
has(key, set)

tests if key is present in set
   */
  let has = Impl.mem;
  
  /**
add(key, set)

returns a new set containing the elements of set with key added
   */
  let add = Impl.add;
  
  /**
remove(key, set)

returns a new set containing the elements of set with key removed
   */
  let remove = Impl.remove;
  
  /**
map(fn, set)

returns a new set where each element, el, of set has been transformed by calling fn(el)
   */
  let map = Impl.map;
  
};

module IntSet = {
  module Impl = Caml.Set.Make(Int);
  /**
Alias for the set type.
   */
  type t = Impl.t;
  /**
The empty set.
   */
  let empty = Impl.empty;
  
  /**
fromList(list)

creates a set from the elements of list
   */
  let fromList = Impl.of_list;
  
  /**
toList(set)

returns the elements of set as a list
   */
  let toList = Impl.elements;
  
  /**
fromArray(array)

creates a set from the elements of array
   */
  let fromArray = (array) => {
    fromList(Caml.Array.to_list(array));
  };
  
  /**
toArray(set)

returns the elements of set as an array
   */
  let toArray = (set) => {
    Caml.Array.of_list(toList(set));
  };
  
  /**
isEmpty(set)

tests whether set is empty
   */
  let isEmpty = Impl.is_empty;
  
  /**
size(set)

returns the number of elements in set
   */
  let size = Impl.cardinal;
  
  /**
has(key, set)

tests if key is present in set
   */
  let has = Impl.mem;
  
  /**
add(key, set)

returns a new set containing the elements of set with key added
   */
  let add = Impl.add;
  
  /**
remove(key, set)

returns a new set containing the elements of set with key removed
   */
  let remove = Impl.remove;
  
  /**
map(fn, set)

returns a new set where each element, el, of set has been transformed by calling fn(el)
   */
  let map = Impl.map;
  
};

module Map = {
  module Impl = Caml.Map.Make(String);
  /**
Alias for the map type.
   */
  type t('value) = Impl.t('value);
  /**
The empty map.
   */
  let empty = Impl.empty;
  
  /**
isEmpty(map)

tests whether map is empty
   */
  let isEmpty = Impl.is_empty;
  
  /**
size(map)

returns the number of entries in map
   */
  let size = Impl.cardinal;
  
  /**
hasKey(key, map)

tests if the key key is present in map
   */
  let hasKey = Impl.mem;
  
  /**
get(key, map)

returns Some(value) associated with key if it exists in map, None otherwise
   */
  let get = Impl.find_opt;
  
  /**
getExn(key, map)

returns the value associated with key if it exists in map, raises Not_found otherwise
   */
  let getExn = Impl.find;
  
  /**
set(key, value, map)

returns a new map containing the entries of map with the value of key set to value
   */
  let set = Impl.add;
  
  /**
remove(key, map)

returns a new map containing the entries of map with the entry of key key removed
   */
  let remove = Impl.remove;
  
  /**
map(fn, map)

returns a new map with the same keys as map where each value, v, has been transformed by calling fn(v)
   */
  let map = Impl.map;
  
  /**
mapi(fn, map)

returns a new map with the same keys as map where each value, v, has been transformed by calling fn(key, v)
   */
  let mapi = Impl.mapi;
  
  /**
fromList(list)

creates a map from the entries of list, if there are duplicate keys, then the map will contain the value occuring last in list
   */
  let fromList = (list) => {
    Caml.List.fold_left(
      (m, (key, value)) => Impl.add(key, value, m),
      Impl.empty,
      list,
    );
  };
  
  /**
toList(map)

returns the entries of map as a list
   */
  let toList = Impl.bindings;
  
  /**
fromArray(array)

creates a map from the entries of array, if there are duplicate keys, then the map will contain the value occuring last in array
   */
  let fromArray = (array) => {
    fromList(Caml.Array.to_list(array));
  };
  
  /**
toArray(map)

returns the entries of map as an array
   */
  let toArray = (map) => {
    Caml.Array.of_list(toList(map));
  };
  
};

module IntMap = {
  module Impl = Caml.Map.Make(Int);
  /**
Alias for the map type.
   */
  type t('value) = Impl.t('value);
  /**
The empty map.
   */
  let empty = Impl.empty;
  
  /**
isEmpty(map)

tests whether map is empty
   */
  let isEmpty = Impl.is_empty;
  
  /**
size(map)

returns the number of entries in map
   */
  let size = Impl.cardinal;
  
  /**
hasKey(key, map)

tests if the key key is present in map
   */
  let hasKey = Impl.mem;
  
  /**
get(key, map)

returns Some(value) associated with key if it exists in map, None otherwise
   */
  let get = Impl.find_opt;
  
  /**
getExn(key, map)

returns the value associated with key if it exists in map, raises Not_found otherwise
   */
  let getExn = Impl.find;
  
  /**
set(key, value, map)

returns a new map containing the entries of map with the value of key set to value
   */
  let set = Impl.add;
  
  /**
remove(key, map)

returns a new map containing the entries of map with the entry of key key removed
   */
  let remove = Impl.remove;
  
  /**
map(fn, map)

returns a new map with the same keys as map where each value, v, has been transformed by calling fn(v)
   */
  let map = Impl.map;
  
  /**
mapi(fn, map)

returns a new map with the same keys as map where each value, v, has been transformed by calling fn(key, v)
   */
  let mapi = Impl.mapi;
  
  /**
fromList(list)

creates a map from the entries of list, if there are duplicate keys, then the map will contain the value occuring last in list
   */
  let fromList = (list) => {
    Caml.List.fold_left(
      (m, (key, value)) => Impl.add(key, value, m),
      Impl.empty,
      list,
    );
  };
  
  /**
toList(map)

returns the entries of map as a list
   */
  let toList = Impl.bindings;
  
  /**
fromArray(array)

creates a map from the entries of array, if there are duplicate keys, then the map will contain the value occuring last in array
   */
  let fromArray = (array) => {
    fromList(Caml.Array.to_list(array));
  };
  
  /**
toArray(map)

returns the entries of map as an array
   */
  let toArray = (map) => {
    Caml.Array.of_list(toList(map));
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

module MutableGraph = {
  
  type t = {
    mutable nodes: Map.t(int),
    mutable nodesRev: IntMap.t(string),
    mutable edges: IntMap.t(IntSet.t),
  };
  
  let empty = {nodes: Map.empty, nodesRev: IntMap.empty, edges: IntMap.empty};
  
  let getNodes = (graph) => {
    let entries = Map.toList(graph.nodes);
    let keys = Caml.List.map(((key, _value)) => key, entries);
    keys;
  };
  
  let getEdges = (node, graph) => {
    let node =
      switch (Map.get(node, graph.nodes)) {
      | Some(node) => node
      | None => failwith("Unknown node: " ++ node)
      };
    let edges =
      switch (IntMap.get(node, graph.edges)) {
      | Some(edges) => IntSet.toList(edges)
      | None => []
      };
    let edges = Caml.List.map(node => IntMap.getExn(node, graph.nodesRev), edges);
    edges;
  };
  
  let addNode = (string, graph) =>
    if (!Map.hasKey(string, graph.nodes)) {
      let id = Map.size(graph.nodes);
      graph.nodes = Map.set(string, id, graph.nodes);
      graph.nodesRev = IntMap.set(id, string, graph.nodesRev);
    };
  
  let addDirected = (u, v, graph) => {
    addNode(u, graph);
    addNode(v, graph);
    let u = Map.getExn(u, graph.nodes);
    let v = Map.getExn(v, graph.nodes);
    if (!IntMap.hasKey(u, graph.edges)) {
      graph.edges = IntMap.set(u, IntSet.empty, graph.edges);
    };
    // TODO: Change from get/set to a single update.
    let edgeSet = IntMap.getExn(u, graph.edges);
    graph.edges = IntMap.set(u, IntSet.add(v, edgeSet), graph.edges);
    ();
  };
  
  let addUndirected = (u, v, graph) => {
    addDirected(u, v, graph);
    addDirected(v, u, graph);
    ();
  };
  
  let dfs =
      (
        ~onEnter: string => unit=_node => (),
        ~onExit: string => unit=_node => (),
        root,
        graph,
      ) => {
    let root = Map.getExn(root, graph.nodes);
    let visited = ref(IntSet.empty);
    let rec helper = curr =>
      if (!IntSet.has(curr, visited^)) {
        let node = IntMap.getExn(curr, graph.nodesRev);
        visited := IntSet.add(curr, visited^);
        onEnter(node);
        let nextEdges = IntMap.getExn(curr, graph.edges);
        // TODO: Change to iter/forEach.
        let _ =
          IntSet.map(
            next => {
              helper(next);
              next;
            },
            nextEdges,
          );
        onExit(node);
      };
    helper(root);
  };
  
};

module GraphWeighted = {
  
  type t = {
    nodes: Map.t(int),
    nodesRev: IntMap.t(string),
    edges: IntMap.t(IntMap.t(int)),
  };
  
  type dfsKind =
    | OnEnter
    | OnExit;
  
  let empty = {nodes: Map.empty, nodesRev: IntMap.empty, edges: IntMap.empty};
  
  let getNodes = (graph) => {
    let entries = Map.toList(graph.nodes);
    let keys = Caml.List.map(((key, _value)) => key, entries);
    keys;
  };
  
  let getEdges = (node, graph) => {
    let node =
      switch (Map.get(node, graph.nodes)) {
      | Some(node) => node
      | None => failwith("Unknown node: " ++ node)
      };
    let edges =
      switch (IntMap.get(node, graph.edges)) {
      | Some(edges) => IntMap.toList(edges)
      | None => []
      };
    let edges = Caml.List.map(
      ((node, weight)) => (IntMap.getExn(node, graph.nodesRev), weight),
      edges,
    );
    edges;
  };
  
  let addNode = (string, graph) =>
    if (!Map.hasKey(string, graph.nodes)) {
      let id = Map.size(graph.nodes);
      let nodes = Map.set(string, id, graph.nodes);
      let nodesRev = IntMap.set(id, string, graph.nodesRev);
      {...graph, nodes, nodesRev};
    } else {
      graph;
    };
  
  let addDirected = (u, v, weight, graph) => {
    let graph = addNode(u, graph);
    let graph = addNode(v, graph);
    let u = Map.getExn(u, graph.nodes);
    let v = Map.getExn(v, graph.nodes);
    let adjacent =
      if (!IntMap.hasKey(u, graph.edges)) {
        IntMap.empty;
      } else {
        IntMap.getExn(u, graph.edges);
      };
    let edges = IntMap.set(u, IntMap.set(v, weight, adjacent), graph.edges);
    {...graph, edges};
  };
  
  let addUndirected = (u, v, weight, graph) => {
    let graph = addDirected(u, v, weight, graph);
    let graph = addDirected(v, u, weight, graph);
    graph;
  };
  
  let dfs = (~kind=OnEnter, fn, initial, root, graph) => {
    if (!Map.hasKey(root, graph.nodes)) {
      failwith("Unknown node: " ++ root);
    };
    let root = Map.getExn(root, graph.nodes);
    let result = ref(initial);
    let visited = ref(IntSet.empty);
    let rec helper = (curr, weight, rootCall) =>
      if (!IntSet.has(curr, visited^)) {
        let node = IntMap.getExn(curr, graph.nodesRev);
        visited := IntSet.add(curr, visited^);
  
        if (!rootCall) {
          switch (kind) {
          | OnEnter =>
            result := fn(result^, node, weight);
            ();
          | OnExit => ()
          };
        };
  
        let nextEdges = IntMap.get(curr, graph.edges);
        switch (nextEdges) {
        | Some(nextEdges) =>
          // TODO: Change to iter/forEach.
          let _ =
            IntMap.mapi(
              (next, weight) => {
                helper(next, weight, false);
                next;
              },
              nextEdges,
            );
          ();
        | None => ()
        };
  
        if (!rootCall) {
          switch (kind) {
          | OnEnter => ()
          | OnExit =>
            result := fn(result^, node, weight);
            ();
          };
        };
  
        ();
      };
    helper(root, -1, true);
    result^;
  };
  
};

module Graph = {
  
  type t = {
    nodes: Map.t(int),
    nodesRev: IntMap.t(string),
    edges: IntMap.t(IntSet.t),
  };
  
  type dfsKind =
    | OnEnter
    | OnExit;
  
  let empty = {nodes: Map.empty, nodesRev: IntMap.empty, edges: IntMap.empty};
  
  let getNodes = (graph) => {
    let entries = Map.toList(graph.nodes);
    let keys = Caml.List.map(((key, _value)) => key, entries);
    keys;
  };
  
  let getEdges = (node, graph) => {
    let node =
      switch (Map.get(node, graph.nodes)) {
      | Some(node) => node
      | None => failwith("Unknown node: " ++ node)
      };
    let edges =
      switch (IntMap.get(node, graph.edges)) {
      | Some(edges) => IntSet.toList(edges)
      | None => []
      };
    let edges = Caml.List.map(node => IntMap.getExn(node, graph.nodesRev), edges);
    edges;
  };
  
  let addNode = (string, graph) =>
    if (!Map.hasKey(string, graph.nodes)) {
      let id = Map.size(graph.nodes);
      let nodes = Map.set(string, id, graph.nodes);
      let nodesRev = IntMap.set(id, string, graph.nodesRev);
      {...graph, nodes, nodesRev};
    } else {
      graph;
    };
  
  let addDirected = (u, v, graph) => {
    let graph = addNode(u, graph);
    let graph = addNode(v, graph);
    let u = Map.getExn(u, graph.nodes);
    let v = Map.getExn(v, graph.nodes);
    let adjacent =
      if (!IntMap.hasKey(u, graph.edges)) {
        IntSet.empty;
      } else {
        IntMap.getExn(u, graph.edges);
      };
    let edges = IntMap.set(u, IntSet.add(v, adjacent), graph.edges);
    {...graph, edges};
  };
  
  let addUndirected = (u, v, graph) => {
    let graph = addDirected(u, v, graph);
    let graph = addDirected(v, u, graph);
    graph;
  };
  
  let dfs = (~kind=OnEnter, fn, initial, root, graph) => {
    if (!Map.hasKey(root, graph.nodes)) {
      failwith("Unknown node: " ++ root);
    };
    let root = Map.getExn(root, graph.nodes);
    let result = ref(initial);
    let visited = ref(IntSet.empty);
    let rec helper = curr =>
      if (!IntSet.has(curr, visited^)) {
        let node = IntMap.getExn(curr, graph.nodesRev);
        visited := IntSet.add(curr, visited^);
  
        switch (kind) {
        | OnEnter =>
          result := fn(result^, node);
          ();
        | OnExit => ()
        };
  
        let nextEdges = IntMap.get(curr, graph.edges);
        switch (nextEdges) {
        | Some(nextEdges) =>
          // TODO: Change to iter/forEach.
          let _ =
            IntSet.map(
              next => {
                helper(next);
                next;
              },
              nextEdges,
            );
          ();
        | None => ()
        };
  
        switch (kind) {
        | OnEnter => ()
        | OnExit =>
          result := fn(result^, node);
          ();
        };
  
        ();
      };
    helper(root);
    result^;
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

