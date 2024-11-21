//
// Created by Harikeshav R on 11/21/24.
//

#include "src/menu/play_game_menu.h"

#include "src/lib/FEHImages.h"
#include "src/menu/main_menu.h"
#include "src/util/constants.h"
#include "src/util/input.h"

namespace game
{
    PlayGameMenu::PlayGameMenu() = default;

    PlayGameMenu::~PlayGameMenu() = default;

    void PlayGameMenu::draw_play_game_menu()
    {
        LCD.Clear();

        FEHImage play_game_menu_image{PLAY_GAME_MENU_IMAGE_FILE_PATH};
        play_game_menu_image.Draw(0, 0);

        LCD.Update();

        bool back_to_main_menu_clicked = false;

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();
            if (x_coordinate >= PLAY_GAME_MENU_BACK_BUTTON_X_COORDINATE && x_coordinate <=
                PLAY_GAME_MENU_BACK_BUTTON_X_COORDINATE
                + PLAY_GAME_MENU_BACK_BUTTON_X_SIZE && y_coordinate >= PLAY_GAME_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= PLAY_GAME_MENU_BACK_BUTTON_Y_COORDINATE + PLAY_GAME_MENU_BACK_BUTTON_Y_SIZE)
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

    void PlayGameMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // game
