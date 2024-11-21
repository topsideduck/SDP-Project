//
// Created by Harikeshav R on 11/20/24.
//

#ifndef INSTRUCTIONS_MENU_H
#define INSTRUCTIONS_MENU_H

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

        /**
         * @brief Navigates to the main menu.
         *
         * This static method transitions the screen to the main menu by calling
         * the main menu's draw method.
         */
        static void open_main_menu();
    };
} // namespace game

#endif // INSTRUCTIONS_MENU_H
