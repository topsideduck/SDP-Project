//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/main_menu.h"

#include "src/lib/FEHImages.h"
#include "src/menu/credits_menu.h"
#include "src/menu/quit_menu.h"
#include "src/util/constants.h"
#include "src/util/input.h"

namespace game
{
    MainMenu::MainMenu() = default;

    MainMenu::~MainMenu() = default;

    void MainMenu::draw_main_menu()
    {
        LCD.Clear();
        FEHImage main_menu_image{MAIN_MENU_IMAGE_FILE_PATH};
        main_menu_image.Draw(0, 0);

        LCD.Update();

        bool open_credits_menu_button_clicked = false, open_quit_menu_button_clicked = false;

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();
            if (x_coordinate >= MAIN_MENU_CREDITS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CREDITS_BUTTON_X_COORDINATE
                + MAIN_MENU_CREDITS_BUTTON_X_SIZE && y_coordinate >= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE &&
                y_coordinate <=
                MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE + MAIN_MENU_CREDITS_BUTTON_Y_SIZE)
            {
                open_credits_menu_button_clicked = true;
                break;
            }

            if (x_coordinate >= MAIN_MENU_QUIT_BUTTON_X_COORDINATE && x_coordinate <= MAIN_MENU_QUIT_BUTTON_X_COORDINATE
                + MAIN_MENU_QUIT_BUTTON_X_SIZE && y_coordinate >= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE && y_coordinate <=
                MAIN_MENU_QUIT_BUTTON_Y_COORDINATE + MAIN_MENU_QUIT_BUTTON_Y_SIZE)
            {
                open_quit_menu_button_clicked = true;
                break;
            }
        }

        if (open_credits_menu_button_clicked)
        {
            open_credits_menu();
        }

        else if (open_quit_menu_button_clicked)
        {
            open_quit_menu();
        }
    }

    void MainMenu::open_quit_menu()
    {
        QuitMenu::draw_quit_menu();
    }

    void MainMenu::open_credits_menu()
    {
        CreditsMenu::draw_credits_menu();
    }
} // game
