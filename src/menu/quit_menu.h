//
// Created by Harikeshav R on 11/19/24.
//

#ifndef QUIT_MENU_H
#define QUIT_MENU_H

namespace game
{
    class QuitMenu
    {
    public:
        QuitMenu();

        ~QuitMenu();

        static void draw_quit_menu();

        static void open_main_menu();

        static void quit_game();
    };
} // game

#endif //QUIT_MENU_H
