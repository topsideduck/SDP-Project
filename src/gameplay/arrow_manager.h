//
// Created by Harikeshav R on 11/30/24.
//

#ifndef ARROW_MANAGER_H
#define ARROW_MANAGER_H

#include <src/util/constants.h>

#include "src/gameplay/arrow.h"

#include "random"
#include "vector"


namespace game
{
    class ArrowManager
    {
    private:
        std::vector<Arrow *> arrows;

        std::random_device random_device;
        std::mt19937 random_number_generator{random_device()};
        std::uniform_int_distribution<std::mt19937::result_type> random_arrow_generator_distribution{0, 3};

        unsigned int random_time_delay_generator_start_bound = RANDOM_TIME_DELAY_GENERATOR_START_BOUND;
        unsigned int random_time_delay_generator_end_bound = RANDOM_TIME_DELAY_GENERATOR_END_BOUND;


    public:
        ArrowManager();

        ~ArrowManager();

        void create_random_arrow();

        unsigned int create_random_generation_delay();

        void update_random_time_delay_generation_bounds();

        void move_all_arrows(float delta_x, float delta_y) const;

        void delete_invalid_arrows();

        void draw_all_arrows() const;

        unsigned int gather_scores(ArrowDirection direction) const;
    };
} // game

#endif //ARROW_MANAGER_H
