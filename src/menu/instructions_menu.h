//
// Created by Harikeshav R on 11/20/24.
//

#ifndef INSTRUCTIONS_MENU_H
#define INSTRUCTIONS_MENU_H
#include "menus.h"

namespace game
{
    /**
     * @class InstructionsMenu
     * @brief Handles the instructions menu screen and its functionality.
     *
     * This class provides functionality for displaying the instructions menu,
     * waiting for user input, and navigating back to the main menu.
     */
    class InstructionsMenu
    {
    public:
        /**
         * @brief Constructor for the InstructionsMenu class.
         */
        InstructionsMenu();

        /**
         * @brief Destructor for the InstructionsMenu class.
         */
        ~InstructionsMenu();

        /**
         * @brief Displays the instructions menu and handles user interaction.
         *
         * This static method draws the instructions menu screen, listens for
         * user input, and transitions to the main menu when the "Back" button is clicked.
         */
        static void draw_instructions_menu();

        static Menus handle_instructions_menu_input();
    };
} // namespace game

#endif // INSTRUCTIONS_MENU_H
