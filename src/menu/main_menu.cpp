//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/main_menu.h"          // Include the header for the MainMenu class

#include "src/lib/FEHImages.h"           // For displaying images on the LCD
#include "src/menu/menus.h"              // Include the Menus enum
#include "src/util/constants.h"          // Constants for button positions and sizes
#include "src/util/input.h"              // For handling input

namespace game
{
    /**
     * @brief Default constructor for the MainMenu class.
     */
    MainMenu::MainMenu() = default;

    /**
     * @brief Destructor for the MainMenu class.
     */
    MainMenu::~MainMenu() = default;

    /**
     * @brief Displays the main menu and processes user input to navigate to other menus.
     *
     * This method draws the main menu and listens for touch input to navigate to
     * different sub-menus (e.g., play game, instructions, controls, statistics, credits, quit).
     * It detects the specific button clicked and then transitions to the respective menu.
     */
    void MainMenu::draw_main_menu()
    {
        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the main menu image
        FEHImage main_menu_image{MAIN_MENU_IMAGE_FILE_PATH};
        main_menu_image.Draw(0, 0);

        // Update the LCD to display the menu
        LCD.Update();
    }

    Menus MainMenu::handle_main_menu_input()
    {
        // Monitor user touch input continuously
        while (true)
        {
            // Get the coordinates of the user's touch input
            auto [x_coordinate, y_coordinate] = get_input_coordinates();

            // Check if the user clicked the Play Game button
            if (x_coordinate >= MAIN_MENU_PLAY_GAME_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_PLAY_GAME_BUTTON_X_COORDINATE + MAIN_MENU_PLAY_GAME_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_PLAY_GAME_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_PLAY_GAME_BUTTON_Y_COORDINATE + MAIN_MENU_PLAY_GAME_BUTTON_Y_SIZE)
            {
                return Menus::PlayGameMenu;
            }

            // Check if the user clicked the Instructions button
            if (x_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_Y_SIZE)
            {
                return Menus::InstructionsMenu;
            }

            // Check if the user clicked the Controls button
            if (x_coordinate >= MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_Y_SIZE)
            {
                return Menus::ControlsMenu;
            }

            // Check if the user clicked the Statistics button
            if (x_coordinate >= MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_Y_SIZE)
            {
                return Menus::StatisticsMenu;
            }

            // Check if the user clicked the Credits button
            if (x_coordinate >= MAIN_MENU_CREDITS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CREDITS_BUTTON_X_COORDINATE + MAIN_MENU_CREDITS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE + MAIN_MENU_CREDITS_BUTTON_Y_SIZE)
            {
                return Menus::CreditsMenu;
            }

            // Check if the user clicked the Quit button
            if (x_coordinate >= MAIN_MENU_QUIT_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_QUIT_BUTTON_X_COORDINATE + MAIN_MENU_QUIT_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE + MAIN_MENU_QUIT_BUTTON_Y_SIZE)
            {
                return Menus::QuitMenu;
            }
        }
    }
} // namespace game
