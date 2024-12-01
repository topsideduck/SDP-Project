#include "src/util/input.h"  // Include header for input functionality
#include <tuple>            // For using std::tuple to return multiple values
#include "src/lib/FEHLCD.h" // Include FEHLCD library for touchscreen operations

/**
 * @brief Captures and returns the coordinates of the first touch on the screen.
 *
 * This function continuously checks for a touch event on the screen using the FEHLCD library.
 * Once a touch is detected, it retrieves and stores the x and y coordinates of the touch event.
 * The function ensures that it only processes a single touch by waiting for the touch to be released
 * before returning the coordinates.
 *
 * @return A std::tuple<float, float> containing the x and y coordinates of the first touch.
 */
std::tuple<float, float> get_input_coordinates()
{
    float x_coordinate, y_coordinate; // Variables to store touch coordinates
    float x_trash, y_trash; // Temporary variables to discard lingering touch data

    // Wait until a touch is detected and capture its coordinates
    while (!LCD.Touch(&x_coordinate, &y_coordinate))
    {
        // Busy-wait until the screen is touched
    }

    // Wait for the touch to be released
    while (LCD.Touch(&x_trash, &y_trash))
    {
        // Busy-wait until the touch is no longer detected
    }

    // Return the touch coordinates as a tuple
    return {x_coordinate, y_coordinate};
}
