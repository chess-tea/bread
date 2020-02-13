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
get(default, option) returns the value contained within $2 if it exists; otherwise, returns $1

  - TODO: Examples, SeeAlso
   */
  let get = (default, option) => {
    switch (option) {
    | Some(option) => option
    | None => default
    }
  };
};
