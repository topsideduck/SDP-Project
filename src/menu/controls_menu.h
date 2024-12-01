#ifndef CONTROLS_MENU_H
#define CONTROLS_MENU_H

#include "src/menu/menus.h"   // Include the Menus enum

namespace game
{
    /**
     * @class ControlsMenu
     * @brief Manages the controls menu interface and user navigation.
     *
     * The ControlsMenu class handles the rendering of the controls menu screen, including
     * displaying the interface image and detecting user input for navigation back to the main menu.
     */
    class ControlsMenu
    {
    public:
        /**
         * @brief Constructs a ControlsMenu instance.
         */
        ControlsMenu();

        /**
         * @brief Destructor for the ControlsMenu class.
         */
        ~ControlsMenu();

        /**
         * @brief Draws the controls menu interface on the LCD screen.
         *
         * Clears the LCD, renders the controls menu image, and updates the display
         * to prepare for user interaction.
         */
        static void draw_controls_menu();

        /**
         * @brief Handles user input for the controls menu.
         *
         * Waits for user interaction with the controls menu. If the "Back" button is pressed,
         * transitions to the main menu.
         *
         * @return Menus::MainMenu when navigation to the main menu is triggered.
         */
        static Menus handle_controls_menu_input();
    };
} // namespace game

#endif // CONTROLS_MENU_H
