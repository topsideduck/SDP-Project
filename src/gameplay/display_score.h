//
// Created by Harikeshav R on 11/29/24.
//

#ifndef DISPLAYSCORE_H
#define DISPLAYSCORE_H

#include "string"

namespace game
{
    class DisplayScore
    {
    public:
        DisplayScore();

        ~DisplayScore();

        static void draw_score_on_screen(int score);
    };
} // game

#endif //DISPLAYSCORE_H
