//
// Created by Harikeshav R on 11/29/24.
//

#include "src/gameplay/display_score.h"

#include "src/lib/FEHImages.h"
#include "src/util/constants.h"

#include <filesystem>
#include <string>


namespace game
{
    /**
     * @brief Default constructor for the DisplayScore class.
     *
     * This constructor doesn't initialize any members, as all initialization
     * happens directly within the methods where necessary.
     */
    DisplayScore::DisplayScore() = default;

    /**
     * @brief Destructor for the DisplayScore class.
     *
     * This destructor is automatically invoked when the object is destroyed,
     * but in this case, there are no dynamic resources to clean up.
     */
    DisplayScore::~DisplayScore() = default;

    /**
     * @brief Draws the current score on the screen.
     *
     * This method takes a score as input, converts it to individual digits, and
     * draws each digit at the appropriate position on the screen using image files.
     * The images for the digits are loaded from the file path based on the digit value.
     *
     * @param score The score to be displayed.
     */
    void DisplayScore::draw_score_on_screen(unsigned int score)
    {
        std::vector<unsigned int> numbers;

        // Handle the special case of zero
        if (score == 0)
        {
            numbers.push_back(0);
        }
        else
        {
            // Break the score into individual digits
            while (score > 0)
            {
                numbers.push_back(score % 10);
                score /= 10;
            }
        }

        // Reverse the numbers since we've stored them in reverse order
        std::ranges::reverse(numbers);

        // Start drawing digits at the specified x-coordinate
        int current_draw_x_coordinate = GAMEPLAY_SCORE_X_COORDINATE;

        // Loop through each digit in the score and draw it
        for (const unsigned int i: numbers)
        {
            // Construct the file path for the current digit's image
            std::filesystem::path number_file = FONT_NUMBER_BASE_FILE_NAME + std::to_string(i) + ".png";
            std::filesystem::path result = FONT_NUMBER_FILE_PATH / number_file;

            // Create an image object for the current digit and draw it
            FEHImage number{result.string().c_str()};
            number.Draw(current_draw_x_coordinate, GAMEPLAY_SCORE_Y_COORDINATE);

            // Move the x-coordinate to the right for the next digit
            current_draw_x_coordinate += FONT_NUMBER_X_SIZE;
        }

        // Update the display to reflect the drawn score
        LCD.Update();
    }
} // game
