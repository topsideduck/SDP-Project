//
// Created by Harikeshav R on 11/21/24.
//

#ifndef STATISTICS_MENU_H
#define STATISTICS_MENU_H

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

        /**
         * @brief Displays the statistics menu and processes user input.
         *
         * This static method renders the statistics menu screen and monitors user
         * interaction to determine whether the user wants to return to the main menu.
         */
        static void draw_statistics_menu();

        /**
         * @brief Transitions to the main menu screen.
         *
         * This static method is called when the user clicks the "Back" button
         * in the statistics menu.
         */
        static void open_main_menu();
    };
} // namespace game

#endif // STATISTICS_MENU_H
