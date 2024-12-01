//
// Created by Harikeshav R on 11/30/24.
//

#include "src/menu/music_picker_menu.h"

#include <string>
#include <tuple>

#include "src/lib/FEHImages.h"      // For handling images with FEHImage class
#include "src/menu/menus.h"
#include "src/util/constants.h"     // For constants like file paths and button coordinates
#include "src/util/input.h"         // For touchscreen input handling

namespace game
{
    /**
     * @brief Default constructor for the MusicPickerMenu class.
     *
     * Initializes the MusicPickerMenu object. No specific initialization is needed
     * as this is a simple menu with static image rendering and touch input handling.
     */
    MusicPickerMenu::MusicPickerMenu() = default;

    /**
     * @brief Destructor for the MusicPickerMenu class.
     *
     * Cleans up any resources (if applicable), but in this case, no explicit cleanup is needed.
     */
    MusicPickerMenu::~MusicPickerMenu() = default;

    /**
     * @brief Draws the music picker menu to the LCD.
     *
     * This method clears the LCD screen, loads the music picker menu image from a
     * specified file path, and draws it onto the screen.
     * After rendering, the LCD is updated to reflect the changes.
     */
    void MusicPickerMenu::draw_music_picker_menu()
    {
        // Clear the LCD screen to prepare for new rendering
        LCD.Clear();

        // Load and draw the music picker menu image
        FEHImage music_picker_menu_image{MUSIC_PICKER_MENU_IMAGE_FILE_PATH};
        music_picker_menu_image.Draw(0, 0);

        // Update the LCD display to show the new image
        LCD.Update();
    }

    /**
     * @brief Handles user input for the music picker menu.
     *
     * This method continuously monitors the touchscreen for user input.
     * If the user clicks on any of the available buttons, the corresponding
     * action is triggered (either selecting a music track or navigating back).
     *
     * @return A tuple consisting of the next menu, the selected music audio file path,
     *         and the corresponding info file path.
     *
     * The possible actions are:
     * - Selecting a music track: The user selects one of the available tracks,
     *   and the corresponding menu and file paths are returned.
     * - Navigating back: If the user clicks the back button, the main menu is returned
     *   along with empty strings for the music file paths.
     */
    std::tuple<Menus, std::string, std::string> MusicPickerMenu::handle_music_picker_menu_input()
    {
        // Continuously check for user input
        while (true)
        {
            // Get the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the user clicked the "Tailor Swift" music option
            if (x_coordinate >= MUSIC_PICKER_MENU_TAILOR_SWIF_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_TAILOR_SWIF_X_COORDINATE + MUSIC_PICKER_MENU_TAILOR_SWIF_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_TAILOR_SWIF_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_TAILOR_SWIF_Y_COORDINATE + MUSIC_PICKER_MENU_TAILOR_SWIF_Y_SIZE)
            {
                // Return the PlayGameMenu with the selected music file paths
                return {Menus::PlayGameMenu, MUSIC_TAILOR_SWIF_AUDIO_FILE_PATH, MUSIC_TAILOR_SWIF_INFO_FILE_PATH};
            }

            // Check if the user clicked the "Sicko Mode" music option
            if (x_coordinate >= MUSIC_PICKER_MENU_SICKO_MODE_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_SICKO_MODE_X_COORDINATE + MUSIC_PICKER_MENU_SICKO_MODE_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_SICKO_MODE_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_SICKO_MODE_Y_COORDINATE + MUSIC_PICKER_MENU_SICKO_MODE_Y_SIZE)
            {
                // Return the PlayGameMenu with the selected music file paths
                return {Menus::PlayGameMenu, MUSIC_SICKO_MODE_AUDIO_FILE_PATH, MUSIC_SICKO_MODE_INFO_FILE_PATH};
            }

            // Check if the user clicked the "Cinderella" music option
            if (x_coordinate >= MUSIC_PICKER_MENU_CINDERELLA_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_CINDERELLA_X_COORDINATE + MUSIC_PICKER_MENU_CINDERELLA_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_CINDERELLA_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_CINDERELLA_Y_COORDINATE + MUSIC_PICKER_MENU_CINDERELLA_Y_SIZE)
            {
                // Return the PlayGameMenu with the selected music file paths
                return {Menus::PlayGameMenu, MUSIC_CINDERELLA_AUDIO_FILE_PATH, MUSIC_CINDERELLA_INFO_FILE_PATH};
            }

            // Check if the user clicked the "Back" button to return to the main menu
            if (x_coordinate >= MUSIC_PICKER_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= MUSIC_PICKER_MENU_BACK_BUTTON_X_COORDINATE + MUSIC_PICKER_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= MUSIC_PICKER_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= MUSIC_PICKER_MENU_BACK_BUTTON_Y_COORDINATE + MUSIC_PICKER_MENU_BACK_BUTTON_Y_SIZE)
            {
                // Return the MainMenu and empty paths for the music selection
                return {Menus::MainMenu, "", ""};
            }
        }
    }
} // game
