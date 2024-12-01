#include "gameplay/main_game.h"
#include "menu/music_picker_menu.h"
#include "menu/score_menu.h"
#include "src/menu/controls_menu.h"
#include "src/menu/credits_menu.h"
#include "src/menu/instructions_menu.h"
#include "src/menu/main_menu.h"
#include "src/menu/menus.h"
#include "src/menu/quit_menu.h"
#include "src/menu/statistics_menu.h"
#include "src/util/audio_manager.h"
#include "util/constants.h"
#include "util/score_handler.h"


[[noreturn]] int main()
{
    Menus current_menu = Menus::MainMenu;

    game::AudioManager menu_audio_manager(MUSIC_MENU_BG_FILE_PATH);

    std::string music_audio_file_path;
    std::string music_info_file_path;

    unsigned int final_score{};

    const game::ScoreHandler score_handler {SCORES_FILE_PATH};

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

            case Menus::MusicPickerMenu:
            {
                game::MusicPickerMenu::draw_music_picker_menu();
                auto [menu, audio_file_path, info_file_path] =
                        game::MusicPickerMenu::handle_music_picker_menu_input();

                current_menu = menu;
                music_audio_file_path = audio_file_path;
                music_info_file_path = info_file_path;

                break;
            }

            case Menus::PlayGameMenu:
            {
                final_score = game::MainGame::main_loop(music_audio_file_path, music_info_file_path);

                score_handler.save_score(final_score);

                current_menu = Menus::ScoreMenu;

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

            case Menus::ScoreMenu:
            {
                menu_audio_manager.play();

                game::ScoreMenu::draw_score_menu(final_score, score_handler.get_high_score());
                current_menu = game::ScoreMenu::handle_score_menu_input();

                menu_audio_manager.stop();

                break;
            }
            case Menus::StatisticsMenu:
            {
                menu_audio_manager.play();

                game::StatisticsMenu::draw_statistics_menu(score_handler.get_high_score(),
                                                           score_handler.get_last_three_scores());
                current_menu = game::StatisticsMenu::handle_statistics_menu_input();

                menu_audio_manager.stop();

                break;
            }
        }
    }
}
