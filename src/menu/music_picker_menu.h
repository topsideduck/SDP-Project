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
     * @class MusicPickerMenu
     * @brief Handles the music picker menu screen and its functionality.
     *
     * This class is responsible for rendering the music picker menu on the screen,
     * processing user input for selecting a music track or navigating to other menus.
     * It also manages the interaction with the touchscreen input for selecting different
     * options in the menu.
     */
    class MusicPickerMenu
    {
    public:
        /**
         * @brief Default constructor for the MusicPickerMenu class.
         *
         * Initializes the MusicPickerMenu object, but no specific initialization
         * is required as this menu is static in nature.
         */
        MusicPickerMenu();

        /**
         * @brief Destructor for the MusicPickerMenu class.
         *
         * Cleans up any allocated resources (if any), but in this case, the menu
         * does not require explicit resource management.
         */
        ~MusicPickerMenu();

        /**
         * @brief Renders the music picker menu on the LCD screen.
         *
         * This static method clears the LCD screen, loads the image for the music
         * picker menu, and draws it onto the screen. The menu provides options for
         * the user to select a music track.
         */
        static void draw_music_picker_menu();

        /**
         * @brief Handles user input for the music picker menu and returns the next menu.
         *
         * This static method monitors the user's touch input and checks if the user
         * selects a music track or presses the back button. The return value is a tuple
         * containing the next menu, the audio file path for the selected music, and
         * the corresponding info file path.
         *
         * @return A tuple with the next menu, audio file path, and info file path.
         */
        static std::tuple<Menus, std::string, std::string> handle_music_picker_menu_input();
    };
} // game

#endif //MUSIC_PICKER_MENU_H
