//
// Created by Harikeshav R on 11/21/24.
//

#include "src/menu/statistics_menu.h" // Include the header for the StatisticsMenu class

#include "src/lib/FEHImages.h"         // For handling images using FEHImage
#include "src/menu/main_menu.h"        // For accessing main menu functionality
#include "src/util/constants.h"        // For constants like file paths and button coordinates
#include "src/util/input.h"            // For getting touch input from the user

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
     * @brief Displays the statistics menu and handles user input to return to the main menu.
     *
     * This method draws the statistics menu on the screen and listens for user touch input.
     * If the user clicks the "Back" button, it navigates back to the main menu.
     */
    void StatisticsMenu::draw_statistics_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the statistics menu image
        FEHImage statistics_menu_image{STATISTICS_MENU_IMAGE_FILE_PATH};
        statistics_menu_image.Draw(0, 0);

        // Update the LCD display to show the menu image
        LCD.Update();

        // Flag to track whether the user clicked the "Back" button
        bool back_to_main_menu_clicked = false;

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
                back_to_main_menu_clicked = true;
                break; // Exit the loop if "Back" is clicked
            }
        }

        // If the "Back" button was clicked, return to the main menu
        if (back_to_main_menu_clicked)
        {
            open_main_menu();
        }
    }

    /**
     * @brief Opens the main menu by calling its draw method.
     *
     * This method transitions the screen from the statistics menu to the main menu.
     */
    void StatisticsMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // namespace game
