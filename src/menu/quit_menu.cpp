#include "src/menu/quit_menu.h" // Include the header for the QuitMenu class
#include "src/lib/FEHImages.h"   // For handling images using FEHImage
#include "src/menu/menus.h"      // Include the Menus enum
#include "src/util/constants.h"  // For constants like file paths and button coordinates
#include "src/util/input.h"      // For getting touch input from the user

namespace game
{
    /**
     * @brief Default constructor for the QuitMenu class.
     */
    QuitMenu::QuitMenu() = default;

    /**
     * @brief Destructor for the QuitMenu class.
     */
    QuitMenu::~QuitMenu() = default;

    /**
     * @brief Draws the quit menu on the screen.
     *
     * This method loads and displays the quit menu image, preparing the interface for user interaction.
     */
    void QuitMenu::draw_quit_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the quit menu image
        FEHImage quit_menu_image{QUIT_MENU_IMAGE_FILE_PATH};
        quit_menu_image.Draw(0, 0);

        // Update the LCD display to show the menu image
        LCD.Update();
    }

    /**
     * @brief Handles user interaction with the quit menu.
     *
     * Continuously checks for touch input to determine whether the user selects "Stay" or "Quit."
     *
     * @return Menus::MainMenu if the user selects "Stay."
     */
    Menus QuitMenu::handle_quit_menu_input()
    {
        // Monitor user input in an infinite loop
        while (true)
        {
            // Get the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the user clicked the "Stay" button
            if (x_coordinate >= QUIT_MENU_STAY_BUTTON_X_COORDINATE &&
                x_coordinate <= QUIT_MENU_STAY_BUTTON_X_COORDINATE + QUIT_MENU_STAY_BUTTON_X_SIZE &&
                y_coordinate >= QUIT_MENU_STAY_BUTTON_Y_COORDINATE &&
                y_coordinate <= QUIT_MENU_STAY_BUTTON_Y_COORDINATE + QUIT_MENU_STAY_BUTTON_Y_SIZE)
            {
                return Menus::MainMenu;
            }

            // Check if the user clicked the "Quit" button
            if (x_coordinate >= QUIT_MENU_QUIT_BUTTON_X_COORDINATE &&
                x_coordinate <= QUIT_MENU_QUIT_BUTTON_X_COORDINATE + QUIT_MENU_QUIT_BUTTON_X_SIZE &&
                y_coordinate >= QUIT_MENU_QUIT_BUTTON_Y_COORDINATE &&
                y_coordinate <= QUIT_MENU_QUIT_BUTTON_Y_COORDINATE + QUIT_MENU_QUIT_BUTTON_Y_SIZE)
            {
                quit_game();
            }
        }
    }

    /**
     * @brief Exits the game.
     *
     * This method terminates the program when the "Quit" button is clicked.
     */
    void QuitMenu::quit_game()
    {
        exit(0); // Exit the program
    }
} // namespace game
