//
// Created by Harikeshav R on 11/29/24.
//

#include "src/gameplay/display_score.h"

#include "src/lib/FEHImages.h"
#include "src/util/constants.h"

#include "filesystem"
#include "string"


namespace game
{
    DisplayScore::DisplayScore() = default;

    DisplayScore::~DisplayScore() = default;

    void DisplayScore::draw_score_on_screen(int score)
    {
        std::vector<int> numbers;

        while (score > 0)
        {
            numbers.push_back(score % 10);
            score /= 10;
        }

        std::ranges::reverse(numbers);

        int current_draw_x_coordinate = GAMEPLAY_SCORE_X_COORDINATE;

        for (const int i : numbers)
        {
            std::filesystem::path number_file = FONT_NUMBER_BASE_FILE_NAME + std::to_string(i) + ".png";
            std::filesystem::path result = FONT_NUMBER_FILE_PATH / number_file;

            std::cout << result.string() << std::endl;

            FEHImage number{result.string().c_str()};
            number.Draw(current_draw_x_coordinate, GAMEPLAY_SCORE_Y_COORDINATE);

            LCD.Update();

            current_draw_x_coordinate += FONT_NUMBER_X_SIZE;
        }
    }
} // game
