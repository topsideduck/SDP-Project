//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/main_menu.h"          // Include the header for the MainMenu class

#include "src/gameplay/arrow.h"
#include "src/lib/FEHImages.h"           // For displaying images on the LCD
#include "src/menu/menus.h"              // Include the Menus enum
#include "src/util/constants.h"          // Constants for button positions and sizes
#include "src/util/input.h"              // For handling input
#include "src/util/play_dance.h"
#include "thread"

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

    void MainMenu::main_menu_dance(const std::atomic<bool> *should_i_dance)
    {
        int dance_counter = 1;

        while (*should_i_dance)
        {
            play_dance(ArrowDirection::Sitting, &dance_counter, MAIN_MENU_DANCE_FRAME_X_COORDINATE,
                       MAIN_MENU_DANCE_FRAME_Y_COORDINATE, MAIN_MENU_DANCE_ITERATIONS_BETWEEN_FRAMES);
        }
    }


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
        std::atomic<bool> should_i_dance = true;

        std::thread dance_thread(main_menu_dance, &should_i_dance);

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
                should_i_dance = false;
                dance_thread.join();
                return Menus::MusicPickerMenu;
            }

            // Check if the user clicked the Instructions button
            if (x_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::InstructionsMenu;
            }

            // Check if the user clicked the Controls button
            if (x_coordinate >= MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::ControlsMenu;
            }

            // Check if the user clicked the Statistics button
            if (x_coordinate >= MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::StatisticsMenu;
            }

            // Check if the user clicked the Credits button
            if (x_coordinate >= MAIN_MENU_CREDITS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CREDITS_BUTTON_X_COORDINATE + MAIN_MENU_CREDITS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE + MAIN_MENU_CREDITS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::CreditsMenu;
            }

            // Check if the user clicked the Quit button
            if (x_coordinate >= MAIN_MENU_QUIT_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_QUIT_BUTTON_X_COORDINATE + MAIN_MENU_QUIT_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE + MAIN_MENU_QUIT_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::QuitMenu;
            }

            LCD.Update();
        }
    }
} // namespace game
