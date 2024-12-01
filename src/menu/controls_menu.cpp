#include "src/menu/controls_menu.h"  // Include the header file for ControlsMenu class
#include "src/lib/FEHImages.h"      // For handling images with FEHImage class
#include "src/menu/menus.h"
#include "src/util/constants.h"     // For constants like file paths and button coordinates
#include "src/util/input.h"         // For touchscreen input handling

namespace game
{
    /**
     * @brief Default constructor for the ControlsMenu class.
     *
     * Initializes a ControlsMenu instance with no specific functionality required
     * during construction.
     */
    ControlsMenu::ControlsMenu() = default;

    /**
     * @brief Default destructor for the ControlsMenu class.
     *
     * Cleans up any resources associated with the ControlsMenu instance.
     */
    ControlsMenu::~ControlsMenu() = default;

    /**
     * @brief Displays the controls menu on the LCD screen.
     *
     * Renders the controls menu background image onto the screen and updates the display.
     * This function prepares the controls menu interface for user interaction.
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
    }

    /**
     * @brief Handles user input in the controls menu.
     *
     * Waits for the user to interact with the controls menu interface. If the "Back" button is pressed,
     * navigates to the main menu by returning the appropriate menu state.
     *
     * @return Menus::MainMenu if the "Back" button is clicked.
     */
    Menus ControlsMenu::handle_controls_menu_input()
    {
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
                return Menus::MainMenu; // Navigate to the main menu
            }
        }
    }
} // namespace game
