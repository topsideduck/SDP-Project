//
// Created by Harikeshav R on 11/19/24.
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "src/menu/menus.h" // Include the Menus enum

namespace game
{
    /**
     * @class MainMenu
     * @brief Manages the main menu of the game and navigation to sub-menus.
     *
     * This class provides functionality for displaying the main menu, handling user
     * input for navigation, and opening different sub-menus like play game, instructions,
     * controls, statistics, credits, and quit.
     */
    class MainMenu
    {
    public:
        /**
         * @brief Constructor for the MainMenu class.
         */
        MainMenu();

        /**
         * @brief Destructor for the MainMenu class.
         */
        ~MainMenu();

        /**
         * @brief Displays the main menu and processes user input.
         *
         * This static method is responsible for rendering the main menu screen and
         * handling touch input to determine which menu the user wants to access.
         */
        static void draw_main_menu();

        static Menus handle_main_menu_input();
    };
} // namespace game

#endif // MAIN_MENU_H
