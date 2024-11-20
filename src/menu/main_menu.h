//
// Created by Harikeshav R on 11/19/24.
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

namespace game
{
    class MainMenu
    {
    public:
        MainMenu();

        ~MainMenu();

        static void draw_main_menu();

        static void open_quit_menu();

        static void open_credits_menu();
    };
} // game

#endif //MAIN_MENU_H
