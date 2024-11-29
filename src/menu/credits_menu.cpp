//
// Created by Harikeshav R on 11/20/24.
//

#include "src/menu/credits_menu.h"  // Include the header for the CreditsMenu class

#include "src/lib/FEHLCD.h"         // For clearing and updating the screen
#include "src/menu/menus.h"         // Include the Menus enum
#include "src/util/constants.h"     // For predefined constants like paths and button coordinates
#include "src/util/input.h"         // For handling touchscreen input
#include "src/util/play_video.h"    // For video playback functionality

namespace game
{
    /**
     * @brief Default constructor for the CreditsMenu class.
     */
    CreditsMenu::CreditsMenu() = default;

    /**
     * @brief Destructor for the CreditsMenu class.
     */
    CreditsMenu::~CreditsMenu() = default;

    /**
     * @brief Draws the credits menu and handles user interaction.
     *
     * This method displays the credits video using sequential image frames. After the video
     * ends, it waits for user input to detect if the "Back" button is clicked. When the back
     * button is pressed, the method navigates back to the main menu.
     */
    void CreditsMenu::draw_credits_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Play the credits video using frames from a specified folder
        play_video(CREDITS_MENU_VIDEO_FRAMES_PATH, CREDITS_MENU_VIDEO_NUMBER_OF_FRAMES, CREDITS_MENU_BASE_FILE_NAME);
    }

    /**
     * @brief Opens the main menu by calling its draw method.
     *
     * This method transitions the screen to the main menu interface.
     */
    Menus CreditsMenu::handle_credits_menu_input()
    {
        // Continuously wait for user interaction
        while (true)
        {
            // Get the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the touch is within the "Back" button bounds
            if (x_coordinate >= CREDITS_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= CREDITS_MENU_BACK_BUTTON_X_COORDINATE + CREDITS_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= CREDITS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= CREDITS_MENU_BACK_BUTTON_Y_COORDINATE + CREDITS_MENU_BACK_BUTTON_Y_SIZE)
            {
                return Menus::MainMenu;
            }
        }
    }
} // game
