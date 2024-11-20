//
// Created by Harikeshav R on 11/20/24.
//

#ifndef CONTROLS_MENU_H
#define CONTROLS_MENU_H

namespace game {

    class ControlsMenu
    {
    public:
        ControlsMenu();

        ~ControlsMenu();

        static void draw_controls_menu();

        static void open_main_menu();
    };

} // game

#endif //CONTROLS_MENU_H
