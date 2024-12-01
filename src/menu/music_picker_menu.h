//
// Created by Harikeshav R on 11/30/24.
//

#ifndef MUSIC_PICKER_MENU_H
#define MUSIC_PICKER_MENU_H

#include <string>
#include "src/menu/menus.h"

namespace game
{
    /**
     * @class ControlsMenu
     * @brief Handles the controls menu screen and its navigation functionality.
     *
     * This class manages the rendering of the controls menu interface, including
     * displaying the controls menu image and navigating back to the main menu.
     */
    class MusicPickerMenu
    {
    public:
        MusicPickerMenu();

        ~MusicPickerMenu();

        static void draw_music_picker_menu();

        static std::tuple<Menus, std::string, std::string> handle_music_picker_menu_input();
    };
} // game

#endif //MUSIC_PICKER_MENU_H
