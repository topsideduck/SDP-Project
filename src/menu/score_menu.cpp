//
// Created by Harikeshav R on 12/1/24.
//

#include "src/menu/score_menu.h"

#include "src/lib/FEHImages.h"   // For handling images using FEHImage
#include "src/menu/menus.h"      // Include the Menus enum
#include "src/util/constants.h"  // For constants like file paths and button coordinates
#include "src/util/input.h"      // For getting touch input from the user

#include <vector>
#include <filesystem>

namespace game
{
    ScoreMenu::ScoreMenu() = default;

    ScoreMenu::~ScoreMenu() = default;

    void ScoreMenu::display_score(unsigned int score, const int y_coordinate)
    {
        std::vector<unsigned int> numbers;

        while (score > 0)
        {
            numbers.push_back(score % 10);
            score /= 10;
        }

        std::ranges::reverse(numbers);

        int current_draw_x_coordinate = (320 - (numbers.size() * FONT_NUMBER_X_SIZE)) / 2;

        for (const unsigned int i: numbers)
        {
            std::filesystem::path number_file = FONT_NUMBER_BASE_FILE_NAME + std::to_string(i) + ".png";
            std::filesystem::path result = FONT_NUMBER_FILE_PATH / number_file;

            FEHImage number{result.string().c_str()};
            number.Draw(current_draw_x_coordinate, y_coordinate);

            current_draw_x_coordinate += FONT_NUMBER_X_SIZE;
        }
    }

    void ScoreMenu::draw_score_menu(const unsigned int score, const unsigned int high_score)
    {
        // Clear the LCD screen
        LCD.Clear();

        FEHImage score_menu_image{SCORE_MENU_IMAGE_FILE_PATH};
        score_menu_image.Draw(0, 0);

        display_score(score, SCORE_MENU_SCORE_Y_COORDINATE);
        display_score(high_score, SCORE_MENU_HIGH_SCORE_Y_COORDINATE);

        LCD.Update();
    }

    Menus ScoreMenu::handle_score_menu_input()
    {
        // Continuously check for user input
        while (true)
        {
            // Retrieve the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            if (x_coordinate >= SCORE_MENU_PLAY_AGAIN_BUTTON_X_COORDINATE &&
                x_coordinate <= SCORE_MENU_PLAY_AGAIN_BUTTON_X_COORDINATE + SCORE_MENU_PLAY_AGAIN_BUTTON_X_SIZE &&
                y_coordinate >= SCORE_MENU_PLAY_AGAIN_BUTTON_Y_COORDINATE &&
                y_coordinate <= SCORE_MENU_PLAY_AGAIN_BUTTON_Y_COORDINATE + SCORE_MENU_PLAY_AGAIN_BUTTON_Y_SIZE)
            {
                return Menus::MusicPickerMenu;
            }

            // Check if the touch is within the bounds of the "Back" button
            if (x_coordinate >= SCORE_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= SCORE_MENU_BACK_BUTTON_X_COORDINATE + SCORE_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= SCORE_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= SCORE_MENU_BACK_BUTTON_Y_COORDINATE + SCORE_MENU_BACK_BUTTON_Y_SIZE)
            {
                return Menus::MainMenu;
            }
        }
    }
} // game
