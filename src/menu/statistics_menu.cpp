//
// Created by Harikeshav R on 11/21/24.
//

#include "src/menu/statistics_menu.h"

#include "src/lib/FEHImages.h"
#include "src/menu/main_menu.h"
#include "src/util/constants.h"
#include "src/util/input.h"

namespace game
{
    StatisticsMenu::StatisticsMenu() = default;

    StatisticsMenu::~StatisticsMenu() = default;

    void StatisticsMenu::draw_statistics_menu()
    {
        LCD.Clear();

        FEHImage statistics_menu_image{STATISTICS_MENU_IMAGE_FILE_PATH};
        statistics_menu_image.Draw(0, 0);

        LCD.Update();

        bool back_to_main_menu_clicked = false;

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();
            if (x_coordinate >= STATISTICS_MENU_BACK_BUTTON_X_COORDINATE && x_coordinate <=
                STATISTICS_MENU_BACK_BUTTON_X_COORDINATE + STATISTICS_MENU_BACK_BUTTON_X_SIZE && y_coordinate >=
                STATISTICS_MENU_BACK_BUTTON_Y_COORDINATE && y_coordinate <= STATISTICS_MENU_BACK_BUTTON_Y_COORDINATE +
                STATISTICS_MENU_BACK_BUTTON_Y_SIZE)
            {
                back_to_main_menu_clicked = true;
                break;
            }
        }

        if (back_to_main_menu_clicked)
        {
            open_main_menu();
        }
    }

    void StatisticsMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // game
