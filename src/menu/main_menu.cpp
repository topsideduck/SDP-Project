//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/main_menu.h"

#include "statistics_menu.h"
#include "src/lib/FEHImages.h"
#include "src/menu/controls_menu.h"
#include "src/menu/credits_menu.h"
#include "src/menu/instructions_menu.h"
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

        bool
                open_instructions_menu_button_clicked = false,
                open_controls_menu_button_clicked = false,
                open_statistics_menu_button_clicked = false,
                open_credits_menu_button_clicked = false,
                open_quit_menu_button_clicked = false;

        while (true)
        {
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            if (x_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_X_SIZE && y_coordinate >=
                MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE && y_coordinate <= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE
                +
                MAIN_MENU_INSTRUCTIONS_BUTTON_Y_SIZE)
            {
                open_instructions_menu_button_clicked = true;
                break;
            }

            if (x_coordinate >= MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_X_SIZE && y_coordinate >=
                MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE && y_coordinate <= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE +
                MAIN_MENU_CONTROLS_BUTTON_Y_SIZE)
            {
                open_controls_menu_button_clicked = true;
                break;
            }

            if (x_coordinate >= MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_X_SIZE && y_coordinate >=
                MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE && y_coordinate <= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE +
                MAIN_MENU_STATISTICS_BUTTON_Y_SIZE)
            {
                open_statistics_menu_button_clicked = true;
                break;
            }

            if (x_coordinate >= MAIN_MENU_CREDITS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CREDITS_BUTTON_X_COORDINATE
                + MAIN_MENU_CREDITS_BUTTON_X_SIZE && y_coordinate >= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE + MAIN_MENU_CREDITS_BUTTON_Y_SIZE)
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

        if (open_instructions_menu_button_clicked)
        {
            open_instructions_menu();
        }

        else if (open_controls_menu_button_clicked)
        {
            open_controls_menu();
        }

        else if (open_statistics_menu_button_clicked)
        {
            open_statistics_menu();
        }

        else if (open_credits_menu_button_clicked)
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

    void MainMenu::open_statistics_menu()
    {
        StatisticsMenu::draw_statistics_menu();
    }

    void MainMenu::open_controls_menu()
    {
        ControlsMenu::draw_controls_menu();
    }

    void MainMenu::open_instructions_menu()
    {
        InstructionsMenu::draw_instructions_menu();
    }
} // game
