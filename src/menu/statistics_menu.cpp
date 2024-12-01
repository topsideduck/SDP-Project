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

    void StatisticsMenu::display_score(unsigned int score, const int y_coordinate)
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

    /**
     * @brief Displays the statistics menu and handles user input to return to the main menu.
     *
     * This method draws the statistics menu on the screen and listens for user touch input.
     * If the user clicks the "Back" button, it navigates back to the main menu.
     */
    void StatisticsMenu::draw_statistics_menu(const unsigned int high_score, const std::vector<unsigned int>& last_three_scores)
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the statistics menu image
        FEHImage statistics_menu_image{STATISTICS_MENU_IMAGE_FILE_PATH};
        statistics_menu_image.Draw(0, 0);

        display_score(high_score, STATISTICS_MENU_HIGH_SCORE_Y_COORDINATE);
        display_score(last_three_scores[2], STATISTICS_MENU_LAST_1_SCORE_Y_COORDINATE);
        display_score(last_three_scores[1], STATISTICS_MENU_LAST_2_SCORE_Y_COORDINATE);
        display_score(last_three_scores[0], STATISTICS_MENU_LAST_3_SCORE_Y_COORDINATE);

        // Update the LCD display to show the menu image
        LCD.Update();
    }

    Menus StatisticsMenu::handle_statistics_menu_input()
    {
        // Monitor user input in an infinite loop
        while (true)
        {
            // Get the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the user clicked the "Back" button
            if (x_coordinate >= STATISTICS_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= STATISTICS_MENU_BACK_BUTTON_X_COORDINATE + STATISTICS_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= STATISTICS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= STATISTICS_MENU_BACK_BUTTON_Y_COORDINATE + STATISTICS_MENU_BACK_BUTTON_Y_SIZE)
            {
                return Menus::MainMenu;
            }
        }
    }
} // namespace game
