//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/quit_menu.h" // Include the header for the QuitMenu class

#include "src/lib/FEHImages.h"   // For handling images using FEHImage
#include "src/menu/main_menu.h"  // For accessing main menu functionality
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

        // Flags to track whether the user clicked on the "Quit" or "Stay" button
        bool quit_game_clicked = false, open_main_menu_clicked = false;

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
                open_main_menu_clicked = true;
                break; // Exit the loop if "Stay" is clicked
            }

            // Check if the user clicked the "Quit" button
            if (x_coordinate >= QUIT_MENU_QUIT_BUTTON_X_COORDINATE &&
                x_coordinate <= QUIT_MENU_QUIT_BUTTON_X_COORDINATE + QUIT_MENU_QUIT_BUTTON_X_SIZE &&
                y_coordinate >= QUIT_MENU_QUIT_BUTTON_Y_COORDINATE &&
                y_coordinate <= QUIT_MENU_QUIT_BUTTON_Y_COORDINATE + QUIT_MENU_QUIT_BUTTON_Y_SIZE)
            {
                quit_game_clicked = true;
                break; // Exit the loop if "Quit" is clicked
            }
        }

        // If the "Quit" button was clicked, exit the game
        if (quit_game_clicked)
        {
            quit_game();
        }
        // If the "Stay" button was clicked, return to the main menu
        else if (open_main_menu_clicked)
        {
            open_main_menu();
        }
    }

    /**
     * @brief Opens the main menu by calling its draw method.
     *
     * This method transitions the screen from the quit menu to the main menu.
     */
    void QuitMenu::open_main_menu()
    {
        MainMenu::draw_main_menu();
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
