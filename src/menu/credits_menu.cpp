//
// Created by Harikeshav R on 11/20/24.
//

#include "src/menu/credits_menu.h"

#include "filesystem"
#include "src/lib/FEHImages.h"
#include "src/menu/main_menu.h"
#include "src/util/constants.h"
#include "src/util/input.h"
#include "src/util/play_video.h"

namespace game
{
    CreditsMenu::CreditsMenu() = default;

    CreditsMenu::~CreditsMenu() = default;

    void CreditsMenu::draw_credits_menu()
    {
        LCD.Clear();

        bool back_clicked = false;

        play_video(CREDITS_MENU_VIDEO_FRAMES_PATH, CREDITS_MENU_VIDEO_NUMBER_OF_FRAMES, "credits_");

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            if (x_coordinate >= CREDITS_MENU_BACK_BUTTON_X_COORDINATE && x_coordinate <=
                CREDITS_MENU_BACK_BUTTON_X_COORDINATE +
                CREDITS_MENU_BACK_BUTTON_X_SIZE && y_coordinate >= CREDITS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate
                <= CREDITS_MENU_BACK_BUTTON_Y_COORDINATE + CREDITS_MENU_BACK_BUTTON_X_SIZE)
            {
                back_clicked = true;
                break;
            }
        }

        if (back_clicked)
        {
            open_main_menu();
        }
    }

    void CreditsMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // game
