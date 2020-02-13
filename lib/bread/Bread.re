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
  
};

