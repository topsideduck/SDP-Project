//
// Created by Harikeshav R on 11/30/24.
//

#include "src/gameplay/arrow_manager.h"
#include "src/gameplay/arrow.h"

#include <random>


namespace game
{
    ArrowManager::ArrowManager() = default;

    ArrowManager::~ArrowManager() = default;

    void ArrowManager::create_random_arrow()
    {
        const auto direction = static_cast<ArrowDirection>(
            random_arrow_generator_distribution(random_number_generator));
        arrows.push_back(new Arrow(direction));
    }

    unsigned int ArrowManager::create_random_generation_delay()
    {
        std::uniform_int_distribution random_time_delay_between_generation_distribution{
            random_time_delay_generator_start_bound, random_time_delay_generator_end_bound
        };
        return random_time_delay_between_generation_distribution(random_number_generator);
    }

    void ArrowManager::update_random_time_delay_generation_bounds()
    {
        if (random_time_delay_generator_start_bound > RANDOM_TIME_DELAY_GENERATOR_MIN_START_BOUND)
        {
             random_time_delay_generator_start_bound -= 5;
        }

        if (random_time_delay_generator_end_bound > RANDOM_TIME_DELAY_GENERATOR_MIN_END_BOUND)
        {
            random_time_delay_generator_end_bound -= 5;
        }
    }


    void ArrowManager::move_all_arrows(const float delta_x, const float delta_y) const
    {
        for (const auto arrow: arrows)
        {
            arrow->update_arrow_position(delta_x, delta_y);
        }
    }

    void ArrowManager::delete_invalid_arrows()
    {
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

        arrows.erase(it, arrows.end());
    }

    void ArrowManager::draw_all_arrows() const
    {
        for (const auto arrow: arrows)
        {
            arrow->draw_arrow();
        }
    }

    unsigned int ArrowManager::gather_scores(const ArrowDirection direction) const
    {
        unsigned int scores = 0;

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
