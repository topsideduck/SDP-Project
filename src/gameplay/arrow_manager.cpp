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



} // game
