#ifndef INPUT_H
#define INPUT_H

#include <tuple> // Required for using std::tuple

/**
 * @brief Retrieves touchscreen input coordinates.
 *
 * This function detects the first touchscreen input event, retrieves the x and y
 * coordinates, and ensures no lingering touch events are processed. The coordinates
 * are then returned as a tuple of floats.
 *
 * @return A std::tuple<float, float> containing the x and y coordinates of the touch event.
 */
std::tuple<float, float> get_input_coordinates();

#endif // INPUT_H
