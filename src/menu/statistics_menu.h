//
// Created by Harikeshav R on 11/21/24.
//

#ifndef STATISTICS_MENU_H
#define STATISTICS_MENU_H
#include "src/menu/menus.h"

#include <vector>

namespace game
{
    /**
     * @class StatisticsMenu
     * @brief Handles the statistics menu screen and its functionality.
     *
     * This class provides methods for displaying the statistics menu,
     * showing scores, and handling user interaction.
     */
    class StatisticsMenu
    {
    public:
        /**
         * @brief Constructor for the StatisticsMenu class.
         */
        StatisticsMenu();

        /**
         * @brief Destructor for the StatisticsMenu class.
         */
        ~StatisticsMenu();

        /**
         * @brief Displays a numeric score on the screen.
         *
         * Breaks the score into individual digits, loads their respective
         * image files, and displays them centered horizontally.
         *
         * @param score The numeric score to display.
         * @param y_coordinate The Y-coordinate for displaying the score.
         */
        static void display_score(unsigned int score, const int y_coordinate);

        /**
         * @brief Draws the statistics menu screen.
         *
         * Displays the high score and the last three scores at their respective
         * Y-coordinates on the statistics menu screen.
         *
         * @param high_score The player's highest score.
         * @param last_three_scores A vector containing the last three scores.
         */
        static void draw_statistics_menu(const unsigned int high_score,
                                         const std::vector<unsigned int> &last_three_scores);

        /**
         * @brief Handles user interaction in the statistics menu.
         *
         * Monitors for touch input and transitions back to the main menu
         * when the "Back" button is clicked.
         *
         * @return Menus::MainMenu when the "Back" button is clicked.
         */
        static Menus handle_statistics_menu_input();
    };
} // namespace game

#endif // STATISTICS_MENU_H
