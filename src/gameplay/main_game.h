//
// Created by Harikeshav R on 11/30/24.
//

#ifndef MAINGAME_H
#define MAINGAME_H

#include "src/gameplay/arrow.h"

namespace game
{
    class MainGame
    {
    public:
        MainGame();

        ~MainGame();

        static void main_loop();
    };
} // game

#endif //MAINGAME_H
