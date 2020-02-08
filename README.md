# Bread 🍞🥖🥐

## **bread**  -  _/ brɛd /_  -  n.

1. A critical element in sandwich construction that provides structure.
2. Container for items such as bacon, lettuce, and tomato.

Bread drastically increases the efficiency sandwiches can be created and used. Its effect is similar to that of data structures and algorithms on an application.

# Principles

Like all good loaves of bread, the primary focus of this repo is on **documentation
and usability**. This is accomplished with an extra layer of indirection. The library
itself is not implemented in plain source code. Instead, it is generated from a "schema" that
contains configuration information about implementation, documentation, and other metadata. This makes writing the implementations more painful, but gives us many nice things:

- Docs are way better, can be enforced, and easily updated.
  - Relationships between functions can be defined in meta data and easily included in all doc-blocks.
  - Module names and functions names can be verified.
  - Data structures that "inherit" functions can use the concrete module name in docs instead of them being generalized.
  - Can have multiple output formats [odoc](https://github.com/ocaml/odoc, markdown, html.
  - And many more!
- Common functions can be inlined.
  - It's normal to use some convenient helpers like `Option.flatMap` when implementing data structures. Using these helpers cause unnecssary function calls compared to using a `switch` directly, but the latter can be very annoying to write every time. We can avoid the annoyance with our fancy code generation and get faster code!
- Project structure can be changed easily.
  - Don't want some fancy data structures that are big and bloated? No problem! We just won't generate that part of the library and its dependencies for you.
  - We can put everything in one big file for you! If you want that I guess.
- Functions with "variable args" can all have nice docs.
  - All those `map2`, `map3`, `mapX` like functions can be generated. (We have the technology!) We will be able to avoid `map2` having docs like: "This is the same as `map` with more args", and be able to repeat the proper documentation block each time.
- There are probably other cool things we can do. Let us know if you have ideas!

# Documentation

We don't have docs yet. Hah, take that person exploring this library. (Ironic isn't it?)

# Development

## Primary commands

- `esy` - Builds and installs
- `esy format` - Runs refmt on all source code
- `esy test` - Runs Rely tests
- `esy gen` - Generates `lib/bread` source code for use

## Directory setup

- `src/bread_config`
  - This is the source code and configuration that will be used to build `lib/bread`. This is a level of indirection that allows outputting more performant, consistent, and better documented code.
- `src/bread_gen`
  - An executable that reads source code and configuration information from `src/bread_config` and creates `lib/bread`.
- `lib/bread`
  - The final output that can be consumed.
  - Everything in here is generated and should not be modified manually.
- `tests/TestExe.re`
  - This is the test executable. Any reason files in `tests` that `open TestFramework` and use `describe` will be registered and run when calling `esy test`.
  - See [reason-native/rely](https://reason-native.com/docs/rely/).
