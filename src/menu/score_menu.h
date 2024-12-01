//
// Created by Harikeshav R on 12/1/24.
//

#ifndef SCORE_MENU_H
#define SCORE_MENU_H

#include "src/menu/menus.h"

namespace game
{
    class ScoreMenu
    {
    public:
        ScoreMenu();

        ~ScoreMenu();

        static void display_score(unsigned int score, int y_coordinate);

        static void draw_score_menu(const unsigned int score, const unsigned int high_score);

        static Menus handle_score_menu_input();
    };
} // game

#endif //SCORE_MENU_H
