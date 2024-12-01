#ifndef INSTRUCTIONS_MENU_H
#define INSTRUCTIONS_MENU_H

#include "src/menu/menus.h"

namespace game
{
    /**
     * @class InstructionsMenu
     * @brief Manages the instructions menu interface and its navigation functionality.
     *
     * The InstructionsMenu class handles displaying the instructions menu and
     * facilitating navigation back to the main menu.
     */
    class InstructionsMenu
    {
    public:
        /**
         * @brief Constructs an InstructionsMenu instance.
         */
        InstructionsMenu();

        /**
         * @brief Destructor for the InstructionsMenu class.
         */
        ~InstructionsMenu();

        /**
         * @brief Displays the instructions menu screen.
         *
         * Loads the instructions menu interface and waits for user input.
         */
        static void draw_instructions_menu();

        /**
         * @brief Handles user input for the instructions menu.
         *
         * Waits for user interaction and transitions to the main menu if
         * the "Back" button is clicked.
         *
         * @return Menus::MainMenu when the user selects the main menu.
         */
        static Menus handle_instructions_menu_input();
    };
} // namespace game

#endif // INSTRUCTIONS_MENU_H
