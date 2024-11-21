//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/controls_menu.h"  // Include the header file for ControlsMenu class

#include "src/lib/FEHImages.h"      // For handling images with FEHImage class
#include "src/menu/main_menu.h"     // For accessing the main menu functionality
#include "src/util/constants.h"     // For constants like file paths and button coordinates
#include "src/util/input.h"         // For touchscreen input handling

namespace game
{
    /**
     * @brief Default constructor for the ControlsMenu class.
     */
    ControlsMenu::ControlsMenu() = default;

    /**
     * @brief Destructor for the ControlsMenu class.
     */
    ControlsMenu::~ControlsMenu() = default;

    /**
     * @brief Draws the controls menu on the LCD and handles navigation to the main menu.
     *
     * This method displays the controls menu background image on the screen. It waits for user input
     * to determine if the "Back" button is pressed. When the back button is clicked, the method
     * navigates back to the main menu.
     */
    void ControlsMenu::draw_controls_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the controls menu image
        FEHImage controls_menu_image{CONTROLS_MENU_IMAGE_FILE_PATH};
        controls_menu_image.Draw(0, 0);

        // Update the LCD to display the image
        LCD.Update();

        bool back_to_main_menu_clicked = false;

        // Continuously wait for user interaction
        while (true)
        {
            // Get the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the touch is within the "Back" button bounds
            if (x_coordinate >= CONTROLS_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= CONTROLS_MENU_BACK_BUTTON_X_COORDINATE + CONTROLS_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= CONTROLS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= CONTROLS_MENU_BACK_BUTTON_Y_COORDINATE + CONTROLS_MENU_BACK_BUTTON_Y_SIZE)
            {
                back_to_main_menu_clicked = true;
                break; // Exit the loop
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
    void ControlsMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
    }
} // game
