#include "src/menu/instructions_menu.h" // Include the header for the InstructionsMenu class
#include "src/lib/FEHImages.h"         // For managing images with FEHImage class
#include "src/menu/menus.h"            // Include the Menus enum
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
     * @brief Displays the instructions menu on the LCD screen.
     *
     * This method loads and displays the instructions menu image on the screen
     * and prepares the interface for user input.
     */
    void InstructionsMenu::draw_instructions_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the instructions menu image
        FEHImage instructions_menu_image{INSTRUCTIONS_MENU_IMAGE_FILE_PATH};
        instructions_menu_image.Draw(0, 0);

        // Update the LCD to display the instructions menu
        LCD.Update();
    }

    /**
     * @brief Handles user interaction in the instructions menu.
     *
     * Continuously checks for touch input. If the "Back" button is pressed,
     * transitions to the main menu.
     *
     * @return Menus::MainMenu when the "Back" button is clicked.
     */
    Menus InstructionsMenu::handle_instructions_menu_input()
    {
        // Continuously wait for user interaction
        while (true)
        {
            // Get the user's touch input coordinates
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Verify if the touch is within the "Back" button bounds
            if (x_coordinate >= INSTRUCTIONS_MENU_BACK_BUTTON_X_COORDINATE &&
                x_coordinate <= INSTRUCTIONS_MENU_BACK_BUTTON_X_COORDINATE + INSTRUCTIONS_MENU_BACK_BUTTON_X_SIZE &&
                y_coordinate >= INSTRUCTIONS_MENU_BACK_BUTTON_Y_COORDINATE &&
                y_coordinate <= INSTRUCTIONS_MENU_BACK_BUTTON_Y_COORDINATE + INSTRUCTIONS_MENU_BACK_BUTTON_Y_SIZE)
            {
                return Menus::MainMenu;
            }
        }
    }
} // namespace game
