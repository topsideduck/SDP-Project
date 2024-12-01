//
// Created by Harikeshav R on 11/30/24.
//

#ifndef ARROW_MANAGER_H
#define ARROW_MANAGER_H

#include "src/util/constants.h"

#include "src/gameplay/arrow.h"

#include <random>
#include <vector>


namespace game
{
    /**
     * @class ArrowManager
     * @brief Manages the creation, movement, and deletion of arrows in the game.
     *
     * The ArrowManager class is responsible for generating random arrows,
     * moving all arrows, deleting invalid arrows, drawing them on the screen,
     * and gathering scores based on arrow direction and hit status.
     */
    class ArrowManager
    {
    private:
        // A collection of arrows currently in the game
        std::vector<Arrow *> arrows;

        // Random number generator and distributions for creating arrows and generating time delays
        std::random_device random_device;
        std::mt19937 random_number_generator{random_device()};
        std::uniform_int_distribution<std::mt19937::result_type> random_arrow_generator_distribution{0, 3};

        // Time delay bounds for controlling the frequency of arrow generation
        unsigned int random_time_delay_generator_start_bound = RANDOM_TIME_DELAY_GENERATOR_START_BOUND;
        unsigned int random_time_delay_generator_end_bound = RANDOM_TIME_DELAY_GENERATOR_END_BOUND;

    public:
        /**
         * @brief Default constructor for the ArrowManager class.
         *
         * Initializes the ArrowManager object, including the random number generator
         * and default bounds for arrow generation delay.
         */
        ArrowManager();

        /**
         * @brief Destructor for the ArrowManager class.
         *
         * Ensures proper cleanup of dynamically allocated arrows.
         */
        ~ArrowManager();

        /**
         * @brief Creates a random arrow and adds it to the collection.
         *
         * The arrow's direction is chosen randomly from the available directions.
         */
        void create_random_arrow();

        /**
         * @brief Generates a random delay between arrow generations.
         *
         * The delay is a random value between the start and end bounds and controls
         * how frequently new arrows are generated.
         *
         * @return A random time delay for the next arrow generation.
         */
        unsigned int create_random_generation_delay();

        /**
         * @brief Updates the bounds for the random time delay between arrow generations.
         *
         * The bounds are reduced over time to increase the frequency of arrow generation.
         */
        void update_random_time_delay_generation_bounds();

        /**
         * @brief Moves all arrows by the given delta values in both x and y directions.
         *
         * Updates the position of each arrow in the collection based on the provided
         * delta values.
         *
         * @param delta_x The change in the x-coordinate.
         * @param delta_y The change in the y-coordinate.
         */
        void move_all_arrows(float delta_x, float delta_y) const;

        /**
         * @brief Deletes arrows that are out of bounds or have received points.
         *
         * Removes and deletes arrows that are no longer valid (either out of bounds
         * or already received points).
         */
        void delete_invalid_arrows();

        /**
         * @brief Draws all arrows on the screen.
         *
         * Renders each arrow at its current position by calling its draw method.
         */
        void draw_all_arrows() const;

        /**
         * @brief Gathers the total score for arrows moving in a specific direction.
         *
         * Iterates through all arrows and calculates the total score for arrows in
         * the given direction, based on whether they have been hit.
         *
         * @param direction The direction of the arrows to calculate the score for.
         * @return The total score for arrows moving in the specified direction.
         */
        unsigned int gather_scores(ArrowDirection direction) const;
    };
} // game

#endif //ARROW_MANAGER_H
