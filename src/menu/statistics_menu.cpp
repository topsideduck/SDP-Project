//
// Created by Harikeshav R on 11/21/24.
//

#include "src/menu/statistics_menu.h" // Include the header for the StatisticsMenu class

#include "src/lib/FEHImages.h"         // For handling images using FEHImage
#include "src/menu/menus.h"            // Include the Menus enum
#include "src/util/constants.h"        // For constants like file paths and button coordinates
#include "src/util/input.h"            // For getting touch input from the user

#include <vector>

namespace game
{
    /**
     * @brief Default constructor for the StatisticsMenu class.
     */
    StatisticsMenu::StatisticsMenu() = default;

    /**
     * @brief Destructor for the StatisticsMenu class.
     */
    StatisticsMenu::~StatisticsMenu() = default;

    /**
     * @brief Displays a numeric score on the screen at a specified Y-coordinate.
     *
     * This function breaks down the given score into individual digits,
     * loads corresponding image files for each digit, and draws them centered
     * horizontally at the specified Y-coordinate.
     *
     * @param score The numeric score to display.
     * @param y_coordinate The Y-coordinate where the score should be drawn.
     */
    void StatisticsMenu::display_score(unsigned int score, const int y_coordinate)
    {
        std::vector<unsigned int> numbers;

        // If score is zero, add a single digit '0' to the vector
        if (score == 0)
        {
            numbers.push_back(0);
        }
        else
        {
            // Extract digits from the score and store them in reverse order
            while (score > 0)
            {
                numbers.push_back(score % 10);
                score /= 10;
            }
        }

        // Reverse the digits to restore their correct order
        std::ranges::reverse(numbers);

        // Calculate starting X-coordinate to center the score on the screen
        int current_draw_x_coordinate = (320 - (numbers.size() * FONT_NUMBER_X_SIZE)) / 2;

        // Iterate through each digit, load its respective image, and draw it
        for (const unsigned int digit: numbers)
        {
            std::filesystem::path number_file = FONT_NUMBER_BASE_FILE_NAME + std::to_string(digit) + ".png";
            std::filesystem::path result = FONT_NUMBER_FILE_PATH / number_file;

            // Load and draw the image for the current digit
            FEHImage number{result.string().c_str()};
            number.Draw(current_draw_x_coordinate, y_coordinate);

            // Move to the next position for the subsequent digit
            current_draw_x_coordinate += FONT_NUMBER_X_SIZE;
        }
    }

    /**
     * @brief Draws the statistics menu screen, displaying the high score and the last three scores.
     *
     * This method clears the screen, loads the statistics menu image, and displays
     * the high score along with the last three scores at their respective Y-coordinates.
     *
     * @param high_score The player's highest score.
     * @param last_three_scores A vector containing the last three scores,
     *                          with the most recent score at the end.
     */
    void StatisticsMenu::draw_statistics_menu(const unsigned int high_score,
                                              const std::vector<unsigned int> &last_three_scores)
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the statistics menu background image
        FEHImage statistics_menu_image{STATISTICS_MENU_IMAGE_FILE_PATH};
        statistics_menu_image.Draw(0, 0);

        // Display the high score and last three scores at their respective positions
        display_score(high_score, STATISTICS_MENU_HIGH_SCORE_Y_COORDINATE);
        display_score(last_three_scores[2], STATISTICS_MENU_LAST_1_SCORE_Y_COORDINATE);
        display_score(last_three_scores[1], STATISTICS_MENU_LAST_2_SCORE_Y_COORDINATE);
        display_score(last_three_scores[0], STATISTICS_MENU_LAST_3_SCORE_Y_COORDINATE);

        // Update the screen to reflect the changes
        LCD.Update();
    }

    /**
     * @brief Handles user input in the statistics menu.
     *
     * This method continuously monitors for touch input. If the user clicks the "Back" button,
     * it returns the main menu enum.
     *
     * @return Menus::MainMenu if the "Back" button is clicked.
     */
    Menus StatisticsMenu::handle_statistics_menu_input()
    {
        // Continuously check for user input
        while (true)
        {
            // Retrieve the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the touch input falls within the bounds of the "Back" button
            if (x_coordinate >= STATISTICS_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= STATISTICS_MENU_BACK_BUTTON_X_COORDINATE + STATISTICS_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= STATISTICS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= STATISTICS_MENU_BACK_BUTTON_Y_COORDINATE + STATISTICS_MENU_BACK_BUTTON_Y_SIZE)
            {
                // Return to the main menu
                return Menus::MainMenu;
            }
        }
    }
} // namespace game
