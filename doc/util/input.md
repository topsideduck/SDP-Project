# Input

## 1. Purpose:

- `get_input_coordinates()` retrieves touch input from a screen and returns the x and y coordinates as a tuple. It
  ensures a clean touch input by waiting for the touch to end before proceeding.

## 2. Code Highlights:

- **input.cpp** contains the implementation of the function.
- **input.h** declares the function with a concise comment for the header documentation.

## 3. Workflow:

- The implementation relies on the `FEHLCD` library for detecting touch input.
- Touch coordinates are captured and lingering touch events are discarded using separate loops.