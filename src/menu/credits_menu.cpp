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
     *
     * Initializes a CreditsMenu instance with no specific functionality required
     * during construction.
     */
    CreditsMenu::CreditsMenu() = default;

    /**
     * @brief Default destructor for the CreditsMenu class.
     *
     * Cleans up any resources associated with the CreditsMenu instance.
     */
    CreditsMenu::~CreditsMenu() = default;

    /**
     * @brief Plays the credits video on the LCD screen.
     *
     * This method renders the credits video by displaying sequential image frames
     * from a specified folder path. It prepares the interface for user interaction
     * after the video has ended.
     */
    void CreditsMenu::draw_credits_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Play the credits video using frames from a specified folder
        play_video(CREDITS_MENU_VIDEO_FRAMES_PATH, CREDITS_MENU_VIDEO_NUMBER_OF_FRAMES, CREDITS_MENU_BASE_FILE_NAME);
    }

    /**
     * @brief Handles user input in the credits menu.
     *
     * Waits for the user to interact with the screen. If the "Back" button is pressed,
     * transitions to the main menu by returning the appropriate menu state.
     *
     * @return Menus::MainMenu if the "Back" button is clicked.
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
                return Menus::MainMenu; // Navigate to the main menu
            }
        }
    }
} // namespace game
