//
// Created by Harikeshav R on 11/20/24.
//

#ifndef CREDITS_MENU_H
#define CREDITS_MENU_H

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

        /**
         * @brief Navigates to the main menu.
         *
         * This static method transitions the screen to the main menu by calling
         * the main menu's draw method.
         */
        static void open_main_menu();
    };
} // game

#endif // CREDITS_MENU_H
