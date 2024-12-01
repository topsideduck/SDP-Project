//
// Created by Harikeshav R on 11/29/24.
//

#ifndef ARROW_H
#define ARROW_H

#include <string>
#include "src/lib/FEHImages.h"

/**
 * @enum ArrowDirection
 * @brief Defines the possible directions for an arrow.
 *
 * The directions represent the possible orientations of the arrow in the game.
 */
enum ArrowDirection
{
    Left, ///< The arrow is pointing to the left.
    Right, ///< The arrow is pointing to the right.
    Up, ///< The arrow is pointing upwards.
    Down, ///< The arrow is pointing downwards.
    Standing, ///< The arrow is not moving (in a standing position).
    Sitting ///< The arrow is stationary (in a sitting position).
};

namespace game
{
    /**
     * @class Arrow
     * @brief Represents an arrow that moves on the screen.
     *
     * The Arrow class manages the properties of an arrow, including its position,
     * direction, image, and behavior when interacting with targets. The arrow moves
     * across the screen and can be used to score points based on its proximity to the target.
     */
    class Arrow
    {
    private:
        float x_coordinate, y_coordinate; ///< The current position of the arrow on the screen.
        ArrowDirection arrow_direction; ///< The direction the arrow is facing.

        std::string arrow_image_file_path; ///< The file path to the arrow's image.
        FEHImage arrow_image; ///< The image object representing the arrow.

        bool is_hit = false; ///< Whether the arrow has successfully hit the target.

    public:
        /**
         * @brief Constructs an Arrow object with a specified direction.
         *
         * @param direction The direction of the arrow.
         */
        explicit Arrow(ArrowDirection direction);

        /**
         * @brief Destructor for the Arrow class.
         *
         * Cleans up resources used by the Arrow object, including closing the image.
         */
        ~Arrow();

        /**
         * @brief Updates the position of the arrow based on delta values.
         *
         * @param delta_x The change in the x-coordinate.
         * @param delta_y The change in the y-coordinate.
         */
        void update_arrow_position(float delta_x, float delta_y);

        /**
         * @brief Draws the arrow at its current position.
         */
        void draw_arrow();

        /**
         * @brief Checks if the arrow is out of bounds.
         *
         * @return True if the arrow has reached the end of its path, false otherwise.
         */
        bool is_out_of_bounds() const;

        /**
         * @brief Checks if the arrow has already scored points.
         *
         * @return True if points have been awarded, false otherwise.
         */
        bool is_points_received() const;

        /**
         * @brief Calculates the points received based on how close the arrow is to the target.
         *
         * @return The points received for hitting the target (0, 1, 2, or 3).
         */
        int calculate_points_received_for_hit();

        /**
         * @brief Gets the direction of the arrow.
         *
         * @return The direction of the arrow.
         */
        ArrowDirection get_direction() const;
    };
} // game

#endif //ARROW_H
