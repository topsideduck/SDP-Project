//
// Created by Harikeshav R on 11/21/24.
//

#ifndef PLAY_GAME_MENU_H
#define PLAY_GAME_MENU_H

namespace game
{
    /**
     * @class PlayGameMenu
     * @brief Handles the play game menu screen and its functionality.
     *
     * This class provides the functionality to display the play game menu, process
     * user input, and navigate back to the main menu when required.
     */
    class PlayGameMenu
    {
    public:
        /**
         * @brief Constructor for the PlayGameMenu class.
         */
        PlayGameMenu();

        /**
         * @brief Destructor for the PlayGameMenu class.
         */
        ~PlayGameMenu();

        /**
         * @brief Displays the play game menu and processes user input.
         *
         * This static method renders the play game menu screen and monitors user
         * interaction to handle transitions, such as navigating back to the main menu.
         */
        static void draw_play_game_menu();

        /**
         * @brief Transitions to the main menu screen.
         *
         * This static method is called when the user clicks the "Back" button
         * in the play game menu.
         */
        static void open_main_menu();
    };
} // namespace game

#endif // PLAY_GAME_MENU_H
