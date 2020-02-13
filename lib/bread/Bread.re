/**
 * This file is generated. Do not modify it manually.
 *
 * To update this file:
 *   - Modify relevant files in: src/bread_config
 *   - Run: esy gen
 *
 * @generated
 */;

module Option = {
  
  /**
isNone(option) returns whether $1 is None
   */
  let isNone = (option) => {
    switch (option) {
    | Some(_) => false
    | None => true
    }
  };
  
  /**
isSome(option) returns whether $1 is Some
   */
  let isSome = (option) => {
    switch (option) {
    | Some(_) => true
    | None => false
    }
  };
  
  /**
makeNone(value) ignores $1 and always returns None
   */
  let makeNone = (value) => {
    None
  };
  
  /**
makeSome(value) returns Some($1)
   */
  let makeSome = (value) => {
    Some(value)
  };
  
  /**
get(default, option) returns the value contained within $2 if it exists; otherwise, returns $1
   */
  let get = (default, option) => {
    switch (option) {
    | Some(option) => option
    | None => default
    }
  };
  
  /**
getExn(option) returns the value contained within $1 if it exists; otherwise, raises exception
   */
  let getExn = (option) => {
    switch (option) {
    | Some(option) => option
    | None => failwith("Unexpected None")
    }
  };
  
  /**
getLazy(defaultFn, option) returns the value contained within $2 if it exists; otherwise, returns the result of calling $1
   */
  let getLazy = (defaultFn, option) => {
    switch (option) {
    | Some(option) => option
    | None => defaultFn()
    }
  };
  
  /**
map(fn, option) changes value of an option according to $1 if all inputs are Some value
   */
  let map = (fn, option) => {
    switch (option) {
    | (Some(option)) =>
      Some(fn(option))
    | _ => None
    }
  };
  
  /**
map2(fn, option1, option2) changes value of an option according to $1 if all inputs are Some value
   */
  let map2 = (fn, option1, option2) => {
    switch (option1, option2) {
    | (Some(option1), Some(option2)) =>
      Some(fn(option1, option2))
    | _ => None
    }
  };
  
  /**
map3(fn, option1, option2, option3) changes value of an option according to $1 if all inputs are Some value
   */
  let map3 = (fn, option1, option2, option3) => {
    switch (option1, option2, option3) {
    | (Some(option1), Some(option2), Some(option3)) =>
      Some(fn(option1, option2, option3))
    | _ => None
    }
  };
  
  /**
map4(fn, option1, option2, option3, option4) changes value of an option according to $1 if all inputs are Some value
   */
  let map4 = (fn, option1, option2, option3, option4) => {
    switch (option1, option2, option3, option4) {
    | (Some(option1), Some(option2), Some(option3), Some(option4)) =>
      Some(fn(option1, option2, option3, option4))
    | _ => None
    }
  };
  
  /**
map5(fn, option1, option2, option3, option4, option5) changes value of an option according to $1 if all inputs are Some value
   */
  let map5 = (fn, option1, option2, option3, option4, option5) => {
    switch (option1, option2, option3, option4, option5) {
    | (Some(option1), Some(option2), Some(option3), Some(option4), Some(option5)) =>
      Some(fn(option1, option2, option3, option4, option5))
    | _ => None
    }
  };
  
};

