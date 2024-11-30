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
        const auto direction = static_cast<ArrowDirection>(distribution_4(random_number_generator));
        arrows.push_back(new Arrow(direction));
    }

    void ArrowManager::move_arrows(const int delta_x, const int delta_y) const
    {
        for (const auto arrow: arrows)
        {
            arrow->update_arrow_position(delta_x, delta_y);
        }
    }

    void ArrowManager::delete_arrows()
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
} // game
