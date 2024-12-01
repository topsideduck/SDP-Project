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
     * This class provides the functionality to display the statistics menu, process
     * user input, and navigate back to the main menu.
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

        static void display_score(unsigned int score, const int y_coordinate);

        /**
         * @brief Displays the statistics menu and processes user input.
         *
         * This static method renders the statistics menu screen and monitors user
         * interaction to determine whether the user wants to return to the main menu.
         */
        static void draw_statistics_menu(const unsigned int high_score,
                                         const std::vector<unsigned int> &last_three_scores);

        static Menus handle_statistics_menu_input();
    };
} // namespace game

#endif // STATISTICS_MENU_H
