//
// Created by Harikeshav R on 11/21/24.
//

#ifndef STATISTICS_MENU_H
#define STATISTICS_MENU_H

namespace game
{
    class StatisticsMenu
    {
    public:
        StatisticsMenu();

        ~StatisticsMenu();

        static void draw_statistics_menu();

        static void open_main_menu();
    };
} // game

#endif //STATISTICS_MENU_H
