//
// Created by Harikeshav R on 11/19/24.
//

#include "src/menu/main_menu.h"          // Include the header for the MainMenu class

#include <thread>
#include "src/gameplay/arrow.h"
#include "src/lib/FEHImages.h"           // For displaying images on the LCD
#include "src/menu/menus.h"              // Include the Menus enum
#include "src/util/constants.h"          // Constants for button positions and sizes
#include "src/util/input.h"              // For handling input
#include "src/util/play_dance.h"

namespace game
{
    /**
     * @brief Default constructor for the MainMenu class.
     *
     * Initializes the MainMenu object. This is a default constructor and doesn't
     * require any specific initialization steps.
     */
    MainMenu::MainMenu() = default;

    /**
     * @brief Destructor for the MainMenu class.
     *
     * Cleans up any resources (if necessary) when the MainMenu object is destroyed.
     * In this case, no specific cleanup is required.
     */
    MainMenu::~MainMenu() = default;

    /**
     * @brief Handles the animation of a dance sequence in the main menu.
     *
     * This function continuously plays a dance animation on the screen as long as the
     * `should_i_dance` flag is true. The dance animation is managed through the `play_dance` function.
     *
     * @param should_i_dance A pointer to an atomic boolean flag that determines whether the dance should continue.
     */
    void MainMenu::main_menu_dance(const std::atomic<bool> *should_i_dance)
    {
        int dance_counter = 1;

        // Play dance as long as should_i_dance is true
        while (*should_i_dance)
        {
            play_dance(ArrowDirection::Sitting, &dance_counter, MAIN_MENU_DANCE_FRAME_X_COORDINATE,
                       MAIN_MENU_DANCE_FRAME_Y_COORDINATE, MAIN_MENU_DANCE_ITERATIONS_BETWEEN_FRAMES);
        }
    }

    /**
     * @brief Displays the main menu and processes user input to navigate to other menus.
     *
     * This method clears the LCD screen, draws the main menu image, and waits for the user
     * to interact with one of the buttons. Based on the button clicked, the function returns
     * the appropriate menu to navigate to.
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

    /**
     * @brief Handles user input for the main menu.
     *
     * This method monitors touchscreen input and checks if the user clicks on any of the
     * menu buttons (e.g., Play Game, Instructions, Controls, etc.). It triggers the appropriate
     * menu transition based on the user's input.
     *
     * @return The menu to navigate to based on the user's selection.
     */
    Menus MainMenu::handle_main_menu_input()
    {
        std::atomic<bool> should_i_dance = true;

        // Create a new thread to handle the dance animation
        std::thread dance_thread(main_menu_dance, &should_i_dance);

        // Continuously monitor user input
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
                should_i_dance = false; // Stop the dance animation
                dance_thread.join(); // Wait for the dance thread to finish
                return Menus::MusicPickerMenu; // Navigate to the music picker menu
            }

            // Check if the user clicked the Instructions button
            if (x_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_INSTRUCTIONS_BUTTON_X_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_INSTRUCTIONS_BUTTON_Y_COORDINATE + MAIN_MENU_INSTRUCTIONS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::InstructionsMenu; // Navigate to the instructions menu
            }

            // Check if the user clicked the Controls button
            if (x_coordinate >= MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CONTROLS_BUTTON_X_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CONTROLS_BUTTON_Y_COORDINATE + MAIN_MENU_CONTROLS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::ControlsMenu; // Navigate to the controls menu
            }

            // Check if the user clicked the Statistics button
            if (x_coordinate >= MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_STATISTICS_BUTTON_X_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_STATISTICS_BUTTON_Y_COORDINATE + MAIN_MENU_STATISTICS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::StatisticsMenu; // Navigate to the statistics menu
            }

            // Check if the user clicked the Credits button
            if (x_coordinate >= MAIN_MENU_CREDITS_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_CREDITS_BUTTON_X_COORDINATE + MAIN_MENU_CREDITS_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_CREDITS_BUTTON_Y_COORDINATE + MAIN_MENU_CREDITS_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::CreditsMenu; // Navigate to the credits menu
            }

            // Check if the user clicked the Quit button
            if (x_coordinate >= MAIN_MENU_QUIT_BUTTON_X_COORDINATE && x_coordinate <=
                MAIN_MENU_QUIT_BUTTON_X_COORDINATE + MAIN_MENU_QUIT_BUTTON_X_SIZE &&
                y_coordinate >= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE &&
                y_coordinate <= MAIN_MENU_QUIT_BUTTON_Y_COORDINATE + MAIN_MENU_QUIT_BUTTON_Y_SIZE)
            {
                should_i_dance = false;
                dance_thread.join();
                return Menus::QuitMenu; // Navigate to the quit menu
            }

            LCD.Update(); // Update the LCD to show any changes
        }
    }
} // namespace game
