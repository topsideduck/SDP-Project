//
// Created by Harikeshav R on 11/21/24.
//

#include "src/menu/play_game_menu.h" // Include the header for the PlayGameMenu class

#include "src/lib/FEHImages.h"       // For handling images using FEHImage
#include "src/menu/main_menu.h"      // For accessing main menu functionality
#include "src/util/constants.h"      // For constants like file paths and button coordinates
#include "src/util/input.h"          // For getting touch input from the user

namespace game
{
    /**
     * @brief Default constructor for the PlayGameMenu class.
     */
    PlayGameMenu::PlayGameMenu() = default;

    /**
     * @brief Destructor for the PlayGameMenu class.
     */
    PlayGameMenu::~PlayGameMenu() = default;

    /**
     * @brief Draws the play game menu and handles user interaction.
     *
     * This method displays the play game menu screen, listens for user touch input,
     * and navigates back to the main menu when the "Back" button is clicked.
     */
    void PlayGameMenu::draw_play_game_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the play game menu image
        FEHImage play_game_menu_image{PLAY_GAME_MENU_IMAGE_FILE_PATH};
        play_game_menu_image.Draw(0, 0);

        // Update the LCD display to show the menu image
        LCD.Update();

        // Flag to indicate whether the "Back to Main Menu" button is clicked
        bool back_to_main_menu_clicked = false;

        // Monitor user input in an infinite loop
        while (true)
        {
            // Get the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the touch input is within the bounds of the "Back" button
            if (x_coordinate >= PLAY_GAME_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= PLAY_GAME_MENU_BACK_BUTTON_X_COORDINATE + PLAY_GAME_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= PLAY_GAME_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= PLAY_GAME_MENU_BACK_BUTTON_Y_COORDINATE + PLAY_GAME_MENU_BACK_BUTTON_Y_SIZE)
            {
                back_to_main_menu_clicked = true;
                break; // Exit the loop when the "Back" button is clicked
            }
        }

        // Navigate to the main menu if the "Back" button is clicked
        if (back_to_main_menu_clicked)
        {
            open_main_menu();
        }
    }

    /**
     * @brief Opens the main menu by calling its draw method.
     *
     * This method transitions the screen from the play game menu to the main menu.
     */
    void PlayGameMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // namespace game
