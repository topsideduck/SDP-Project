//
// Created by Harikeshav R on 11/20/24.
//

#ifndef CREDITS_MENU_H
#define CREDITS_MENU_H

namespace game
{
    class CreditsMenu
    {
    public:
        CreditsMenu();

        ~CreditsMenu();

        static void draw_credits_menu();

        static void open_main_menu();
    };
} // game

#endif //CREDITS_MENU_H
