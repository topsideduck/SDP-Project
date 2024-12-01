#include "src/menu/controls_menu.h"
#include "src/menu/credits_menu.h"
#include "src/menu/instructions_menu.h"
#include "src/menu/main_menu.h"
#include "src/menu/menus.h"
#include "src/menu/play_game_menu.h"
#include "src/menu/quit_menu.h"
#include "src/menu/statistics_menu.h"
#include "src/util/audio_manager.h"
#include "util/constants.h"


[[noreturn]] int main()
{
    Menus current_menu = Menus::MainMenu;

    game::AudioManager menu_audio_manager(MENU_BG_MUSIC_FILE_PATH);

    while (true)
    {
        switch (current_menu)
        {
            case Menus::ControlsMenu:
            {
                menu_audio_manager.play();

                game::ControlsMenu::draw_controls_menu();
                current_menu = game::ControlsMenu::handle_controls_menu_input();

                menu_audio_manager.stop();

                break;
            }

            case Menus::CreditsMenu:
            {
                menu_audio_manager.play();

                game::CreditsMenu::draw_credits_menu();
                current_menu = game::CreditsMenu::handle_credits_menu_input();

                menu_audio_manager.stop();

                break;
            }

            case Menus::InstructionsMenu:
            {
                menu_audio_manager.play();

                game::InstructionsMenu::draw_instructions_menu();
                current_menu = game::InstructionsMenu::handle_instructions_menu_input();

                menu_audio_manager.stop();

                break;
            }

            case Menus::MainMenu:
            {
                menu_audio_manager.play();

                game::MainMenu::draw_main_menu();
                current_menu = game::MainMenu::handle_main_menu_input();

                menu_audio_manager.stop();

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
                menu_audio_manager.play();

                game::QuitMenu::draw_quit_menu();
                current_menu = game::QuitMenu::handle_quit_menu_input();

                menu_audio_manager.stop();

                break;
            }

            case Menus::StatisticsMenu:
            {
                menu_audio_manager.play();

                game::StatisticsMenu::draw_statistics_menu();
                current_menu = game::StatisticsMenu::handle_statistics_menu_input();

                menu_audio_manager.stop();

                break;
            }
        }
    }
}
