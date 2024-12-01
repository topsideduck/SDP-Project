## Play Dance Utility

### Overview

The `play_dance` utility enables rendering and controlling dance animations based on directional inputs. It uses
frame-based animation to display the appropriate sequence of images for a specified dance direction.

### Files

1. **play_dance.cpp**: Implements the `play_dance` function to handle dance animations.
2. **play_dance.h**: Declares the `play_dance` function.

### Functionality

####

`void play_dance(const ArrowDirection direction, int *dance_counter, int x_coordinate, int y_coordinate, int update_rate)`

- **direction**: Specifies the dance direction (e.g., Left, Right, Up, Down).
- **dance_counter**: Pointer to a counter that tracks the current frame of the animation.
- **x_coordinate, y_coordinate**: The coordinates on the screen where the frame will be drawn.
- **update_rate**: Determines how frequently the animation frames are updated.

### Usage

1. Include `play_dance.h` in your project.
2. Call `play_dance` with the appropriate parameters to render the dance animation.

### Example

```cpp
#include "src/util/play_dance.h"
#include "src/gameplay/arrow.h"

int main()
{
    int dance_counter = 1;
    play_dance(ArrowDirection::Left, &dance_counter, 50, 100, 10);
    return 0;
}
```