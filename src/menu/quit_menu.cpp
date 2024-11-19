//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/quit_menu.h"
#include "src/lib/FEHImages.h"
#include "src/menu/main_menu.h"
#include "src/util/constants.h"
#include "src/util/input.h"

namespace game
{
    QuitMenu::QuitMenu() = default;

    QuitMenu::~QuitMenu() = default;

    void QuitMenu::draw_quit_menu()
    {
        LCD.Clear();
        FEHImage quit_menu_image{QUIT_MENU_IMAGE_FILE_PATH};
        quit_menu_image.Draw(0, 0);

        bool quit_game_clicked = false, open_main_menu_clicked = false;

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();
            if (x_coordinate >= QUIT_MENU_YES_BUTTON_X_COORDINATE && x_coordinate <= QUIT_MENU_YES_BUTTON_X_COORDINATE +
                QUIT_MENU_YES_BUTTON_X_SIZE && y_coordinate >= QUIT_MENU_YES_BUTTON_Y_COORDINATE && y_coordinate <=
                QUIT_MENU_YES_BUTTON_Y_COORDINATE + QUIT_MENU_YES_BUTTON_Y_SIZE)
            {
                quit_game_clicked = true;
                break;
            }

            if (x_coordinate >= QUIT_MENU_NO_BUTTON_X_COORDINATE && x_coordinate <= QUIT_MENU_NO_BUTTON_X_COORDINATE +
                QUIT_MENU_NO_BUTTON_X_SIZE && y_coordinate >= QUIT_MENU_NO_BUTTON_Y_COORDINATE && y_coordinate <=
                QUIT_MENU_NO_BUTTON_Y_COORDINATE + QUIT_MENU_NO_BUTTON_Y_SIZE)
            {
                open_main_menu_clicked = true;
                break;
            }
        }

        if (quit_game_clicked)
        {
            quit_game();
        }

        else if (open_main_menu_clicked)
        {
            open_main_menu();
        }
    }

    void QuitMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }

    void QuitMenu::quit_game()
    {
        exit(0);
    }
} // game
