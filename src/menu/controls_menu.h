//
// Created by Harikeshav R on 11/20/24.
//

#ifndef CONTROLS_MENU_H
#define CONTROLS_MENU_H

namespace game
{
    /**
     * @class ControlsMenu
     * @brief Handles the controls menu screen and its navigation functionality.
     *
     * This class manages the rendering of the controls menu interface, including
     * displaying the controls menu image and navigating back to the main menu.
     */
    class ControlsMenu
    {
    public:
        /**
         * @brief Constructor for the ControlsMenu class.
         */
        ControlsMenu();

        /**
         * @brief Destructor for the ControlsMenu class.
         */
        ~ControlsMenu();

        /**
         * @brief Displays the controls menu and handles user interaction.
         *
         * This static method draws the controls menu interface on the screen,
         * listens for user input, and handles the transition back to the main menu.
         */
        static void draw_controls_menu();

        /**
         * @brief Navigates to the main menu.
         *
         * This static method transitions the screen to the main menu by calling
         * the main menu's draw method.
         */
        static void open_main_menu();
    };
} // game

#endif // CONTROLS_MENU_H
