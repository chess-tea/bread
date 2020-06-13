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
};

module String = {
  let length = Caml.String.length;
  
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

