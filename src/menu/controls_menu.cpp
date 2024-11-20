//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/controls_menu.h"

#include "src/lib/FEHImages.h"
#include "src/menu/main_menu.h"
#include "src/util/constants.h"
#include "src/util/input.h"

namespace game
{
    ControlsMenu::ControlsMenu() = default;

    ControlsMenu::~ControlsMenu() = default;

    void ControlsMenu::draw_controls_menu()
    {
        LCD.Clear();

        FEHImage controls_menu_image{CONTROLS_MENU_IMAGE_FILE_PATH};
        controls_menu_image.Draw(0, 0);

        LCD.Update();

        bool back_to_main_menu_clicked = false;

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();
            if (x_coordinate >= CONTROLS_MENU_BACK_BUTTON_X_COORDINATE && x_coordinate <=
                CONTROLS_MENU_BACK_BUTTON_X_COORDINATE
                + CONTROLS_MENU_BACK_BUTTON_X_SIZE && y_coordinate >= CONTROLS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= CONTROLS_MENU_BACK_BUTTON_Y_COORDINATE + CONTROLS_MENU_BACK_BUTTON_Y_SIZE)
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

    void ControlsMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // game
