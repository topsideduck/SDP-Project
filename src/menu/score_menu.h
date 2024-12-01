//
// Created by Harikeshav R on 12/1/24.
//

#ifndef SCORE_MENU_H
#define SCORE_MENU_H

#include "src/menu/menus.h"

namespace game
{
    /**
     * @class ScoreMenu
     * @brief Handles the score menu functionality, including displaying scores
     * and processing user interaction.
     */
    class ScoreMenu
    {
    public:
        /**
         * @brief Constructor for the ScoreMenu class.
         */
        ScoreMenu();

        /**
         * @brief Destructor for the ScoreMenu class.
         */
        ~ScoreMenu();

        /**
         * @brief Displays a numeric score on the screen.
         *
         * Breaks the score into individual digits and displays them
         * horizontally centered at a specified Y-coordinate.
         *
         * @param score The score to display.
         * @param y_coordinate The Y-coordinate for displaying the score.
         */
        static void display_score(unsigned int score, int y_coordinate);

        /**
         * @brief Draws the score menu screen with the current score and high score.
         *
         * Displays different backgrounds based on whether the score is a new high score.
         *
         * @param score The current score.
         * @param high_score The high score.
         */
        static void draw_score_menu(const unsigned int score, const unsigned int high_score);

        /**
         * @brief Handles user interaction on the score menu.
         *
         * Monitors touch input to determine the next menu to transition to
         * based on user selection.
         *
         * @return Menus::MusicPickerMenu or Menus::MainMenu based on user input.
         */
        static Menus handle_score_menu_input();
    };
} // namespace game

#endif // SCORE_MENU_H
