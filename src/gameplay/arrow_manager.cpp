//
// Created by Harikeshav R on 11/30/24.
//

#include "src/gameplay/arrow_manager.h"
#include "src/gameplay/arrow.h"

#include <random>


namespace game
{
    /**
     * @brief Default constructor for the ArrowManager class.
     *
     * Initializes the random number generator for creating random arrows and
     * managing the time delay between arrow generations.
     */
    ArrowManager::ArrowManager() = default;

    /**
     * @brief Destructor for the ArrowManager class.
     *
     * Cleans up any dynamically allocated arrows when the ArrowManager is destroyed.
     */
    ArrowManager::~ArrowManager() = default;

    /**
     * @brief Creates a random arrow and adds it to the arrows collection.
     *
     * The direction of the arrow is chosen randomly from the ArrowDirection enum
     * and the arrow is instantiated accordingly.
     */
    void ArrowManager::create_random_arrow()
    {
        // Generate a random direction for the arrow
        const auto direction = static_cast<ArrowDirection>(
            random_arrow_generator_distribution(random_number_generator));
        // Add the new arrow to the arrows collection
        arrows.push_back(new Arrow(direction));
    }

    /**
     * @brief Generates a random time delay between arrow generations.
     *
     * The delay is a random value between the predefined start and end bounds,
     * which controls how frequently new arrows are generated.
     *
     * @return The generated time delay in milliseconds.
     */
    unsigned int ArrowManager::create_random_generation_delay()
    {
        std::uniform_int_distribution random_time_delay_between_generation_distribution{
            random_time_delay_generator_start_bound, random_time_delay_generator_end_bound
        };
        return random_time_delay_between_generation_distribution(random_number_generator);
    }

    /**
     * @brief Updates the bounds for the random time delay between arrow generations.
     *
     * This function reduces the start and end bounds of the time delay, making
     * arrow generation more frequent as the game progresses.
     */
    void ArrowManager::update_random_time_delay_generation_bounds()
    {
        // Reduce the start bound but ensure it doesn't go below the minimum limit
        if (random_time_delay_generator_start_bound > RANDOM_TIME_DELAY_GENERATOR_MIN_START_BOUND)
        {
            random_time_delay_generator_start_bound -= 5;
        }

        // Reduce the end bound but ensure it doesn't go below the minimum limit
        if (random_time_delay_generator_end_bound > RANDOM_TIME_DELAY_GENERATOR_MIN_END_BOUND)
        {
            random_time_delay_generator_end_bound -= 5;
        }
    }

    /**
     * @brief Moves all the arrows by a given delta in both x and y directions.
     *
     * This method updates the positions of all arrows in the arrows collection.
     * The movement is determined by the given delta values.
     *
     * @param delta_x The change in the x-coordinate.
     * @param delta_y The change in the y-coordinate.
     */
    void ArrowManager::move_all_arrows(const float delta_x, const float delta_y) const
    {
        // Move each arrow in the collection by the given deltas
        for (const auto arrow: arrows)
        {
            arrow->update_arrow_position(delta_x, delta_y);
        }
    }

    /**
     * @brief Deletes arrows that are either out of bounds or have received points.
     *
     * This method iterates through the collection of arrows, removes any that
     * are out of bounds or have already received points, and frees their memory.
     */
    void ArrowManager::delete_invalid_arrows()
    {
        // Remove arrows that are either out of bounds or have been hit
        const auto it = std::ranges::remove_if(arrows, [](const Arrow *arrow)
        {
            if (arrow->is_out_of_bounds())
            {
                delete arrow;
                return true;
            }
            if (arrow->is_points_received())
            {
                delete arrow;
                return true;
            }
            return false;
        }).begin();

        // Erase the removed arrows from the collection
        arrows.erase(it, arrows.end());
    }

    /**
     * @brief Draws all the arrows on the screen.
     *
     * This method calls the draw function for each arrow in the collection,
     * rendering each arrow at its current position on the screen.
     */
    void ArrowManager::draw_all_arrows() const
    {
        // Draw each arrow on the screen
        for (const auto arrow: arrows)
        {
            arrow->draw_arrow();
        }
    }

    /**
     * @brief Calculates the total points for arrows in a given direction.
     *
     * This method sums up the points received by all arrows that are moving in
     * the specified direction, based on whether they have been successfully hit.
     *
     * @param direction The direction for which points are to be gathered.
     * @return The total score for arrows in the specified direction.
     */
    unsigned int ArrowManager::gather_scores(const ArrowDirection direction) const
    {
        unsigned int scores = 0;

        // Loop through each arrow and calculate the score for arrows in the given direction
        for (const auto arrow: arrows)
        {
            if (arrow->get_direction() == direction)
            {
                scores += arrow->calculate_points_received_for_hit();
            }
        }

        return scores;
    }
} // game
