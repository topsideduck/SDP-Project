//
// Created by Harikeshav R on 11/19/24.
//

#include "src/util/input.h"  // Include custom header file for input utilities

#include <tuple>            // For using std::tuple to return multiple values
#include "src/lib/FEHLCD.h" // Include FEHLCD library for touchscreen operations

/**
 * @brief Captures and returns the coordinates of the first touch on the screen.
 *
 * This function continuously checks for a touch event on the screen using the FEHLCD library.
 * Once a touch is detected, it retrieves and stores the x and y coordinates of the touch.
 * To ensure no lingering touch is processed, it waits until the touch is released before returning the coordinates.
 *
 * @return A std::tuple<float, float> containing the x and y coordinates of the first touch event.
 */
std::tuple<float, float> get_input_coordinates()
{
    float x_coordinate, y_coordinate; // Variables to store the actual touch coordinates
    float x_trash, y_trash; // Temporary variables to discard lingering touch data

    // Wait for a touch event and capture the coordinates
    while (!LCD.Touch(&x_coordinate, &y_coordinate))
    {
        // Busy-wait until a touch is detected
    };

    // Wait for the touch to be released
    while (LCD.Touch(&x_trash, &y_trash))
    {
        // Busy-wait until the touch is no longer detected
    };

    // Return the captured touch coordinates as a tuple
    return {x_coordinate, y_coordinate};
}
