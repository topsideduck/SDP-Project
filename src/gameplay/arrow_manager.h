//
// Created by Harikeshav R on 11/30/24.
//

#ifndef ARROW_MANAGER_H
#define ARROW_MANAGER_H

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
        std::uniform_int_distribution<std::mt19937::result_type> random_time_delay_between_generation_distribution{
            0, 50
        };

    public:
        ArrowManager();

        ~ArrowManager();

        void create_random_arrow();

        unsigned int create_random_generation_delay();

        void move_all_arrows(float delta_x, float delta_y) const;

        void delete_invalid_arrows();

        void draw_all_arrows() const;
    };
} // game

#endif //ARROW_MANAGER_H
