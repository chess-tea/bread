# Bread 🍞🥖🥐

## **bread**  -  _/ brɛd /_  -  n.

1. A critical element in sandwich construction that provides structure.
2. Container for items such as bacon, lettuce, and tomato.

Bread drastically increases the efficiency sandwiches can be created and used. Its effect is similar to that of data structures and algorithms on an application.

# Documentation

We don't have docs yet. Hah, take that person exploring this library.

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
