//
// Created by Harikeshav R on 11/19/24.
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

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

        /**
         * @brief Navigates to the Play Game menu.
         */
        static void open_play_game_menu();

        /**
         * @brief Navigates to the Instructions menu.
         */
        static void open_instructions_menu();

        /**
         * @brief Navigates to the Controls menu.
         */
        static void open_controls_menu();

        /**
         * @brief Navigates to the Statistics menu.
         */
        static void open_statistics_menu();

        /**
         * @brief Navigates to the Credits menu.
         */
        static void open_credits_menu();

        /**
         * @brief Navigates to the Quit menu.
         */
        static void open_quit_menu();
    };
} // namespace game

#endif // MAIN_MENU_H
