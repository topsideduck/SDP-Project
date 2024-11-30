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
        std::uniform_int_distribution<std::mt19937::result_type> distribution_4{0, 3};

    public:
        ArrowManager();

        ~ArrowManager();

        void create_random_arrow();

        void move_arrows(int delta_x, int delta_y) const;

        void delete_arrows();

        void draw_all_arrows() const;
    };
} // game

#endif //ARROW_MANAGER_H
