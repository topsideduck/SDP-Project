//
// Created by Harikeshav R on 11/30/24.
//

#include "src/gameplay/main_game.h"

#include "src/gameplay/arrow_manager.h"
#include "src/gameplay/display_score.h"
#include "src/lib/FEHImages.h"
#include "src/util/constants.h"
#include "src/util/play_dance.h"


namespace game
{
    MainGame::MainGame() = default;

    MainGame::~MainGame() = default;

    void MainGame::main_loop()
    {
        unsigned int score = 1;

        unsigned int random_arrow_generation_index = 0;
        unsigned int random_arrow_generation_delay = 0;

        float velocity = 1;
        unsigned int arrow_velocity_change_index = 0;

        int dance_counter = 1;

        ArrowDirection old_direction{};

        ArrowManager arrow_manager;

        FEHImage bg{"assets/SCORE.png"};

        while (true)
        {
            LCD.Clear();

            bg.Draw(0, 0);

            ArrowDirection direction_to_check{};

            if (tigrKeyHeld(LCD.screen, TK_LEFT) || tigrKeyHeld(LCD.screen, 'A'))
            {
                direction_to_check = ArrowDirection::Left;
            }
            else if (tigrKeyHeld(LCD.screen, TK_UP) || tigrKeyHeld(LCD.screen, 'W'))
            {
                direction_to_check = ArrowDirection::Up;
            }
            else if (tigrKeyHeld(LCD.screen, TK_DOWN) || tigrKeyHeld(LCD.screen, 'S'))
            {
                direction_to_check = ArrowDirection::Down;
            }
            else if (tigrKeyHeld(LCD.screen, TK_RIGHT) || tigrKeyHeld(LCD.screen, 'D'))
            {
                direction_to_check = ArrowDirection::Right;
            }
            else
            {
                direction_to_check = ArrowDirection::Standing;
            }

            score += arrow_manager.gather_scores(direction_to_check);

            if (old_direction != direction_to_check)
            {
                dance_counter = 1;
            }

            play_dance(direction_to_check, &dance_counter, MAIN_GAME_DANCE_FRAME_X_COORDINATE, MAIN_GAME_DANCE_FRAME_Y_COORDINATE, DANCE_ITERATIONS_BETWEEN_FRAMES);

            DisplayScore::draw_score_on_screen(score);

            if (random_arrow_generation_delay == random_arrow_generation_index)
            {
                arrow_manager.create_random_arrow();
                random_arrow_generation_delay = arrow_manager.create_random_generation_delay();
                random_arrow_generation_index = 0;
            }

            if (velocity <= ARROW_MAX_VELOCITY && arrow_velocity_change_index == ARROW_VELOCITY_CHANGE_DELAY_LOOPS)
            {
                arrow_velocity_change_index = 0;
                velocity++;
            }

            arrow_manager.move_all_arrows(0, -velocity);
            arrow_manager.draw_all_arrows();
            arrow_manager.delete_invalid_arrows();

            random_arrow_generation_index++;
            arrow_velocity_change_index++;

            old_direction = direction_to_check;

            LCD.Update();
        }
    }
} // game
