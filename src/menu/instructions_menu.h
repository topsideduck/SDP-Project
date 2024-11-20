//
// Created by Harikeshav R on 11/20/24.
//

#ifndef INSTRUCTIONS_MENU_H
#define INSTRUCTIONS_MENU_H

namespace game
{
    class InstructionsMenu
    {
    public:
        InstructionsMenu();

        ~InstructionsMenu();

        static void draw_instructions_menu();

        static void open_main_menu();
    };
} // game

#endif //INSTRUCTIONS_MENU_H
