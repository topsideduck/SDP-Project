//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/instructions_menu.h" // Include the header for the InstructionsMenu class
#include "src/lib/FEHImages.h"         // For managing images with FEHImage class
#include "src/menu/main_menu.h"        // For accessing the main menu functionality
#include "src/util/constants.h"        // For predefined constants such as file paths and button coordinates
#include "src/util/input.h"            // For handling touchscreen input

namespace game
{
    /**
     * @brief Default constructor for the InstructionsMenu class.
     */
    InstructionsMenu::InstructionsMenu() = default;

    /**
     * @brief Destructor for the InstructionsMenu class.
     */
    InstructionsMenu::~InstructionsMenu() = default;

    /**
     * @brief Draws the instructions menu and handles user interaction.
     *
     * This method displays the instructions menu screen, waits for the user to click
     * the "Back" button, and navigates to the main menu when the button is clicked.
     */
    void InstructionsMenu::draw_instructions_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the instructions menu image
        FEHImage instructions_menu_image{INSTRUCTIONS_MENU_IMAGE_FILE_PATH};
        instructions_menu_image.Draw(0, 0);

        // Update the LCD display to show the loaded image
        LCD.Update();

        // Flag to indicate if the "Back to Main Menu" button is clicked
        bool back_to_main_menu_clicked = false;

        // Continuously check for user input
        while (true)
        {
            // Retrieve the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the touch is within the bounds of the "Back" button
            if (x_coordinate >= INSTRUCTIONS_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= INSTRUCTIONS_MENU_BACK_BUTTON_X_COORDINATE + INSTRUCTIONS_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= INSTRUCTIONS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= INSTRUCTIONS_MENU_BACK_BUTTON_Y_COORDINATE + INSTRUCTIONS_MENU_BACK_BUTTON_Y_SIZE)
            {
                back_to_main_menu_clicked = true;
                break; // Exit the loop if the "Back" button is clicked
            }
        }

        // Navigate to the main menu if the "Back" button was clicked
        if (back_to_main_menu_clicked)
        {
            open_main_menu();
        }
    }

    /**
     * @brief Opens the main menu by calling its draw method.
     *
     * This method transitions the screen to the main menu interface.
     */
    void InstructionsMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // namespace game
