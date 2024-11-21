//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/main_menu.h"          // Include the header for the MainMenu class

#include "src/lib/FEHImages.h"           // For displaying images on the LCD
#include "src/menu/controls_menu.h"      // Include the controls menu for navigation
#include "src/menu/credits_menu.h"       // Include the credits menu for navigation
#include "src/menu/instructions_menu.h"  // Include the instructions menu for navigation
#include "src/menu/play_game_menu.h"     // Include the play game menu for navigation
#include "src/menu/quit_menu.h"          // Include the quit menu for navigation
#include "src/menu/statistics_menu.h"    // Include the statistics menu for navigation
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

        // Flags for button clicks to navigate to respective menus
        bool open_play_game_menu_button_clicked = false,
                open_instructions_menu_button_clicked = false,
                open_controls_menu_button_clicked = false,
                open_statistics_menu_button_clicked = false,
                open_credits_menu_button_clicked = false,
                open_quit_menu_button_clicked = false;

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
                open_play_game_menu_button_clicked = true;
                break;
            }

            // Check if the user clicked the Instructions button
            if (x_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_Y_SIZE)
            {
                open_instructions_menu_button_clicked = true;
                break;
            }

            // Check if the user clicked the Controls button
            if (x_coordinate >= MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_Y_SIZE)
            {
                open_controls_menu_button_clicked = true;
                break;
            }

            // Check if the user clicked the Statistics button
            if (x_coordinate >= MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_Y_SIZE)
            {
                open_statistics_menu_button_clicked = true;
                break;
            }

            // Check if the user clicked the Credits button
            if (x_coordinate >= MAIN_MENU_CREDITS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CREDITS_BUTTON_X_COORDINATE + MAIN_MENU_CREDITS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE + MAIN_MENU_CREDITS_BUTTON_Y_SIZE)
            {
                open_credits_menu_button_clicked = true;
                break;
            }

            // Check if the user clicked the Quit button
            if (x_coordinate >= MAIN_MENU_QUIT_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_QUIT_BUTTON_X_COORDINATE + MAIN_MENU_QUIT_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE + MAIN_MENU_QUIT_BUTTON_Y_SIZE)
            {
                open_quit_menu_button_clicked = true;
                break;
            }
        }

        // Navigate to the appropriate menu based on the button clicked
        if (open_play_game_menu_button_clicked)
        {
            open_play_game_menu();
        }
        else if (open_instructions_menu_button_clicked)
        {
            open_instructions_menu();
        }
        else if (open_controls_menu_button_clicked)
        {
            open_controls_menu();
        }
        else if (open_statistics_menu_button_clicked)
        {
            open_statistics_menu();
        }
        else if (open_credits_menu_button_clicked)
        {
            open_credits_menu();
        }
        else if (open_quit_menu_button_clicked)
        {
            open_quit_menu();
        }
    }

    /**
     * @brief Opens the Play Game menu.
     */
    void MainMenu::open_play_game_menu()
    {
        PlayGameMenu::draw_play_game_menu();
    }

    /**
     * @brief Opens the Instructions menu.
     */
    void MainMenu::open_instructions_menu()
    {
        InstructionsMenu::draw_instructions_menu();
    }

    /**
     * @brief Opens the Controls menu.
     */
    void MainMenu::open_controls_menu()
    {
        ControlsMenu::draw_controls_menu();
    }

    /**
     * @brief Opens the Statistics menu.
     */
    void MainMenu::open_statistics_menu()
    {
        StatisticsMenu::draw_statistics_menu();
    }

    /**
     * @brief Opens the Credits menu.
     */
    void MainMenu::open_credits_menu()
    {
        CreditsMenu::draw_credits_menu();
    }

    /**
     * @brief Opens the Quit menu.
     */
    void MainMenu::open_quit_menu()
    {
        QuitMenu::draw_quit_menu();
    }
} // namespace game
