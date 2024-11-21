//
// Created by Harikeshav R on 11/19/24.
//

#ifndef INPUT_H
#define INPUT_H

#include <tuple> // For returning multiple values using std::tuple

/**
 * @brief Function to capture touchscreen input coordinates.
 *
 * This function waits for a touchscreen input, retrieves the x and y coordinates of the
 * touch, and ensures no lingering touch data is processed before returning the coordinates.
 *
 * @return A std::tuple<float, float> containing the x and y coordinates of the detected touch.
 */
std::tuple<float, float> get_input_coordinates();

#endif // INPUT_H
