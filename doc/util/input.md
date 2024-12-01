## Input Utility

### Overview
The `Input` utility provides a simple way to retrieve touchscreen input coordinates using the FEHLCD library. It waits for a touch event, captures the x and y coordinates, and ensures that only the first touch is processed.

### Files
1. **input.cpp**: Implements the `get_input_coordinates` function for detecting touchscreen events and retrieving the coordinates.
2. **input.h**: Declares the `get_input_coordinates` function.

### Functionality
#### `std::tuple<float, float> get_input_coordinates()`
- Waits for a touch event on the screen.
- Captures the x and y coordinates of the first touch.
- Waits for the touch to be released to avoid processing lingering touch data.
- Returns the coordinates as a tuple of two floats.

### Usage
1. Include `input.h` in your project.
2. Call `get_input_coordinates()` to get the x and y coordinates of the next touch event.

### Example
```cpp
#include "src/util/input.h"
#include <iostream>

int main()
{
    auto [x, y] = get_input_coordinates();
    std::cout << "Touch detected at: (" << x << ", " << y << ")" << std::endl;
    return 0;
}
```