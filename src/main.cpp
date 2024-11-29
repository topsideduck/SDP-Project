// #include <iostream>

// #include "src/lib/FEHLCD.h"
#include "src/menu/controls_menu.h"
#include "src/menu/credits_menu.h"
#include "src/menu/instructions_menu.h"
#include "src/menu/main_menu.h"
#include "src/menu/menus.h"
#include "src/menu/play_game_menu.h"
#include "src/menu/quit_menu.h"
#include "src/menu/statistics_menu.h"


// #include "src/lib/tigr.h"


[[noreturn]] int main()
{
    Menus current_menu = Menus::MainMenu;

    while (true)
    {
        switch (current_menu)
        {
            case Menus::ControlsMenu:
            {
                game::ControlsMenu::draw_controls_menu();
                current_menu = game::ControlsMenu::handle_controls_menu_input();
                break;
            }

            case Menus::CreditsMenu:
            {
                game::CreditsMenu::draw_credits_menu();
                current_menu = game::CreditsMenu::handle_credits_menu_input();
                break;
            }

            case Menus::InstructionsMenu:
            {
                game::InstructionsMenu::draw_instructions_menu();
                current_menu = game::InstructionsMenu::handle_instructions_menu_input();
                break;
            }

            case Menus::MainMenu:
            {
                game::MainMenu::draw_main_menu();
                current_menu = game::MainMenu::handle_main_menu_input();
                break;
            }

            case Menus::PlayGameMenu:
            {
                game::PlayGameMenu::draw_play_game_menu();
                current_menu = game::PlayGameMenu::handle_play_game_menu_input();
                break;
            }

            case Menus::QuitMenu:
            {
                game::QuitMenu::draw_quit_menu();
                current_menu = game::QuitMenu::handle_quit_menu_input();
                break;
            }

            case Menus::StatisticsMenu:
            {
                game::StatisticsMenu::draw_statistics_menu();
                current_menu = game::StatisticsMenu::handle_statistics_menu_input();
                break;
            }
        }
    }

    // while (true)
    // {
    //     // Read the keyboard and move the player.
    //     // if (tigrKeyDown(LCD.screen, TK_SPACE))
    //     //     std::cout << "space" << std::endl;
    //     // // if (tigrKeyHeld(screen, TK_LEFT) || tigrKeyHeld(screen, 'A'))
    //     // //     playerxs -= 10;
    //     // // if (tigrKeyHeld(screen, TK_RIGHT) || tigrKeyHeld(screen, 'D'))
    //     // //     playerxs += 10;
    //     LCD.Update();
    //     // Never end
    // }
}
