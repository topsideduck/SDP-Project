//
// Created by Harikeshav R on 11/20/24.
//

#ifndef CREDITS_MENU_H
#define CREDITS_MENU_H
#include "menus.h"

namespace game
{
    /**
     * @class CreditsMenu
     * @brief Handles the credits menu screen and its functionality.
     *
     * This class is responsible for displaying the credits menu, which includes playing
     * a video of sequential frames. It also provides navigation back to the main menu.
     */
    class CreditsMenu
    {
    public:
        /**
         * @brief Constructor for the CreditsMenu class.
         */
        CreditsMenu();

        /**
         * @brief Destructor for the CreditsMenu class.
         */
        ~CreditsMenu();

        /**
         * @brief Displays the credits menu and handles user interaction.
         *
         * This static method displays the credits menu video, listens for user input,
         * and transitions to the main menu when the "Back" button is clicked.
         */
        static void draw_credits_menu();

        static Menus handle_credits_menu_input();
    };
} // game

#endif // CREDITS_MENU_H
