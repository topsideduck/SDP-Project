//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/instructions_menu.h"

#include "src/lib/FEHImages.h"
#include "src/menu/main_menu.h"
#include "src/util/constants.h"
#include "src/util/input.h"

namespace game
{
    InstructionsMenu::InstructionsMenu() = default;

    InstructionsMenu::~InstructionsMenu() = default;

    void InstructionsMenu::draw_instructions_menu()
    {
        LCD.Clear();

        FEHImage instructions_menu_image{INSTRUCTIONS_MENU_IMAGE_FILE_PATH};
        instructions_menu_image.Draw(0, 0);

        LCD.Update();

        bool back_to_main_menu_clicked = false;

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();
            if (x_coordinate >= INSTRUCTIONS_MENU_BACK_BUTTON_X_COORDINATE && x_coordinate <=
                INSTRUCTIONS_MENU_BACK_BUTTON_X_COORDINATE
                + INSTRUCTIONS_MENU_BACK_BUTTON_X_SIZE && y_coordinate >= INSTRUCTIONS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= INSTRUCTIONS_MENU_BACK_BUTTON_Y_COORDINATE + INSTRUCTIONS_MENU_BACK_BUTTON_Y_SIZE)
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

    void InstructionsMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // game
