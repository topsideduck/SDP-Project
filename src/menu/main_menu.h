//
// Created by Harikeshav R on 11/19/24.
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <thread>
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
         *
         * Initializes the MainMenu object. No specific initialization is needed in this case.
         */
        MainMenu();

        /**
         * @brief Destructor for the MainMenu class.
         *
         * Cleans up any resources (if applicable) when the MainMenu object is destroyed.
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
         * @brief Handles the dance animation sequence for the main menu.
         *
         * This method manages the dance animation that runs in the background while the
         * main menu is displayed. The dance continues until the provided atomic flag is set to false.
         *
         * @param should_i_dance A pointer to an atomic boolean flag to control the dance animation.
         */
        static void main_menu_dance(const std::atomic<bool> *should_i_dance);

        /**
         * @brief Handles user input for the main menu and returns the next menu.
         *
         * This method monitors touchscreen input to detect which button the user clicks.
         * It returns the corresponding menu based on the user's selection (e.g., MusicPickerMenu,
         * InstructionsMenu, etc.).
         *
         * @return The menu to navigate to based on the user's selection.
         */
        static Menus handle_main_menu_input();
    };
} // namespace game

#endif // MAIN_MENU_H
