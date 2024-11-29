//
// Created by Harikeshav R on 11/19/24.
//

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
     * @brief Displays the quit menu and handles user input to either quit the game or return to the main menu.
     *
     * This method draws the quit menu on the screen and listens for user touch input.
     * Depending on the user's touch, it either quits the game or returns to the main menu.
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
     * This method terminates the program by calling exit(0).
     */
    void QuitMenu::quit_game()
    {
        exit(0); // Exit the program
    }
} // namespace game
