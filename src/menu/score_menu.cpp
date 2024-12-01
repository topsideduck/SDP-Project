//
// Created by Harikeshav R on 12/1/24.
//

#include "src/menu/score_menu.h"

#include "src/lib/FEHImages.h"   // For handling images using FEHImage
#include "src/menu/menus.h"      // Include the Menus enum
#include "src/util/constants.h"  // For constants like file paths and button coordinates
#include "src/util/input.h"      // For getting touch input from the user

#include <filesystem>
#include <vector>

namespace game
{
    /**
     * @brief Default constructor for the ScoreMenu class.
     */
    ScoreMenu::ScoreMenu() = default;

    /**
     * @brief Destructor for the ScoreMenu class.
     */
    ScoreMenu::~ScoreMenu() = default;

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
    void ScoreMenu::display_score(unsigned int score, const int y_coordinate)
    {
        std::vector<unsigned int> numbers;

        // If score is zero, push a single 0 to the vector
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

        // Reverse the digits to restore their original order
        std::ranges::reverse(numbers);

        // Calculate starting X-coordinate to center the score on the screen
        int current_draw_x_coordinate = (320 - (numbers.size() * FONT_NUMBER_X_SIZE)) / 2;

        // Iterate through the digits, load their respective images, and draw them
        for (const unsigned int i: numbers)
        {
            std::filesystem::path number_file = FONT_NUMBER_BASE_FILE_NAME + std::to_string(i) + ".png";
            std::filesystem::path result = FONT_NUMBER_FILE_PATH / number_file;

            // Load and draw the image for the current digit
            FEHImage number{result.string().c_str()};
            number.Draw(current_draw_x_coordinate, y_coordinate);

            // Move to the next X-coordinate for subsequent digits
            current_draw_x_coordinate += FONT_NUMBER_X_SIZE;
        }
    }

    /**
     * @brief Draws the score menu screen, showing the current score and high score.
     *
     * Depending on whether the current score is a new high score, it displays
     * a different background image. The scores are displayed using the display_score() method.
     *
     * @param score The player's current score.
     * @param high_score The player's highest score.
     */
    void ScoreMenu::draw_score_menu(const unsigned int score, const unsigned int high_score)
    {
        // Clear the LCD screen
        LCD.Clear();

        // Determine which image to use based on whether the score is a new high score
        if (score >= high_score)
        {
            FEHImage score_menu_image{SCORE_MENU_NEW_HIGH_SCORE_IMAGE_FILE_PATH};
            score_menu_image.Draw(0, 0);
        }
        else
        {
            FEHImage score_menu_image{SCORE_MENU_IMAGE_FILE_PATH};
            score_menu_image.Draw(0, 0);
        }

        // Display the current score and the high score
        display_score(score, SCORE_MENU_SCORE_Y_COORDINATE);
        display_score(high_score, SCORE_MENU_HIGH_SCORE_Y_COORDINATE);

        // Update the screen with the drawn elements
        LCD.Update();
    }

    /**
     * @brief Handles user interaction on the score menu.
     *
     * Monitors touch input to determine whether the user wants to play again
     * or return to the main menu. Returns the corresponding menu enum.
     *
     * @return Menus::MusicPickerMenu if the "Play Again" button is clicked,
     *         Menus::MainMenu if the "Back" button is clicked.
     */
    Menus ScoreMenu::handle_score_menu_input()
    {
        while (true)
        {
            // Retrieve touch input coordinates
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the "Play Again" button was clicked
            if (x_coordinate >= SCORE_MENU_PLAY_AGAIN_BUTTON_X_COORDINATE &&
                x_coordinate <= SCORE_MENU_PLAY_AGAIN_BUTTON_X_COORDINATE + SCORE_MENU_PLAY_AGAIN_BUTTON_X_SIZE &&
                y_coordinate >= SCORE_MENU_PLAY_AGAIN_BUTTON_Y_COORDINATE &&
                y_coordinate <= SCORE_MENU_PLAY_AGAIN_BUTTON_Y_COORDINATE + SCORE_MENU_PLAY_AGAIN_BUTTON_Y_SIZE)
            {
                return Menus::MusicPickerMenu;
            }

            // Check if the "Back" button was clicked
            if (x_coordinate >= SCORE_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= SCORE_MENU_BACK_BUTTON_X_COORDINATE + SCORE_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= SCORE_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= SCORE_MENU_BACK_BUTTON_Y_COORDINATE + SCORE_MENU_BACK_BUTTON_Y_SIZE)
            {
                return Menus::MainMenu;
            }
        }
    }
} // namespace game
