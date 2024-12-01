#ifndef CREDITS_MENU_H
#define CREDITS_MENU_H

#include "src/menu/menus.h"

namespace game
{
    /**
     * @class CreditsMenu
     * @brief Manages the credits menu interface and navigation functionality.
     *
     * The CreditsMenu class is responsible for playing a video of sequential frames
     * as part of the credits display. It also facilitates navigation back to the main menu.
     */
    class CreditsMenu
    {
    public:
        /**
         * @brief Constructs a CreditsMenu instance.
         */
        CreditsMenu();

        /**
         * @brief Destructor for the CreditsMenu class.
         */
        ~CreditsMenu();

        /**
         * @brief Plays the credits menu video on the LCD screen.
         *
         * Displays sequential frames of the credits video from a specified folder
         * and prepares for user interaction.
         */
        static void draw_credits_menu();

        /**
         * @brief Handles user input for the credits menu.
         *
         * Waits for user interaction. If the "Back" button is clicked, transitions to the main menu.
         *
         * @return Menus::MainMenu when navigation to the main menu is triggered.
         */
        static Menus handle_credits_menu_input();
    };
} // namespace game

#endif // CREDITS_MENU_H
