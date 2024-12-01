#ifndef PLAY_DANCE_H
#define PLAY_DANCE_H

#include "src/gameplay/arrow.h" // Include ArrowDirection enum

/**
 * @brief Renders a dance animation for the given direction.
 *
 * @param direction The direction of the dance animation (e.g., Left, Up, etc.).
 * @param dance_counter Pointer to the counter controlling animation frames.
 * @param x_coordinate X-coordinate for the frame's position on the screen.
 * @param y_coordinate Y-coordinate for the frame's position on the screen.
 * @param update_rate Frame update rate controlling the speed of the animation.
 */
void play_dance(const ArrowDirection direction, int *dance_counter, int x_coordinate, int y_coordinate,
                int update_rate);

#endif // PLAY_DANCE_H
