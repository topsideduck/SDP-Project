//
// Created by Harikeshav R on 11/30/24.
//

#include "src/gameplay/main_game.h"

#include "src/gameplay/arrow_manager.h"
#include "src/gameplay/display_score.h"
#include "src/lib/FEHImages.h"
#include "src/util/audio_manager.h"
#include "src/util/constants.h"
#include "src/util/play_dance.h"


namespace game
{
    /**
     * @brief Default constructor for the MainGame class.
     *
     * Initializes the MainGame object, setting up any necessary game state.
     */
    MainGame::MainGame() = default;

    /**
     * @brief Destructor for the MainGame class.
     *
     * Cleans up any resources allocated during the gameplay loop.
     */
    MainGame::~MainGame() = default;

    /**
     * @brief Main game loop where the game logic is executed.
     *
     * This function runs the primary game loop, handling inputs, arrow generation,
     * movement, scoring, and rendering. It also plays the game audio and handles
     * the dance animations based on player input.
     *
     * @param music_audio_file_path The file path to the background music.
     * @param music_info_file_path The file path to the music info image.
     * @return The final score achieved in the game.
     */
    unsigned int MainGame::main_loop(const std::string &music_audio_file_path, const std::string &music_info_file_path)
    {
        unsigned int score = 0; // Initialize the score variable

        unsigned int random_arrow_generation_index = 0; // Tracks the timing for generating arrows
        unsigned int random_arrow_generation_delay = 0; // Time delay between arrow generations

        unsigned int random_time_delay_generation_bounds_index = 0; // Tracks changes in generation bounds

        float velocity = 1; // Initial velocity of arrows
        unsigned int arrow_velocity_change_index = 0; // Tracks how often to change arrow velocity

        int dance_counter = 1; // Counter for the dance animation frames

        ArrowDirection old_direction{}; // Holds the last direction the player pressed

        // Create instances for managing arrows, background, and audio
        ArrowManager arrow_manager;
        FEHImage background_image{MAIN_GAME_IMAGE_FILE_PATH};
        FEHImage info_image{music_info_file_path.c_str()};

        AudioManager game_audio_manager(music_audio_file_path); // Initialize audio manager and play music
        game_audio_manager.play();

        // Main game loop continues while the audio is still playing
        while (!game_audio_manager.is_playback_complete())
        {
            LCD.Clear(); // Clear the screen at the start of each loop iteration

            // Draw the background and info image
            background_image.Draw(0, 0);
            info_image.Draw(235, 0);

            ArrowDirection direction_to_check{}; // Variable to store the current direction based on input

            // Check the player's input and assign the corresponding arrow direction
            if (tigrKeyHeld(LCD.screen, TK_LEFT) || tigrKeyHeld(LCD.screen, 'A'))
            {
                direction_to_check = ArrowDirection::Left;
            }
            else if (tigrKeyHeld(LCD.screen, TK_UP) || tigrKeyHeld(LCD.screen, 'W'))
            {
                direction_to_check = ArrowDirection::Up;
            }
            else if (tigrKeyHeld(LCD.screen, TK_DOWN) || tigrKeyHeld(LCD.screen, 'S'))
            {
                direction_to_check = ArrowDirection::Down;
            }
            else if (tigrKeyHeld(LCD.screen, TK_RIGHT) || tigrKeyHeld(LCD.screen, 'D'))
            {
                direction_to_check = ArrowDirection::Right;
            }
            else
            {
                direction_to_check = ArrowDirection::Standing; // No key pressed, standing still
            }

            // Update the score based on the arrows that match the pressed direction
            score += arrow_manager.gather_scores(direction_to_check);

            // Reset the dance animation counter when the direction changes
            if (old_direction != direction_to_check)
            {
                dance_counter = 1;
            }

            // Play the dance animation corresponding to the pressed direction
            play_dance(direction_to_check, &dance_counter, MAIN_GAME_DANCE_FRAME_X_COORDINATE,
                       MAIN_GAME_DANCE_FRAME_Y_COORDINATE, DANCE_ITERATIONS_BETWEEN_FRAMES);

            // Display the updated score on the screen
            DisplayScore::draw_score_on_screen(score);

            // Handle random arrow generation and timing delays
            if (random_arrow_generation_delay == random_arrow_generation_index)
            {
                arrow_manager.create_random_arrow(); // Create a new arrow
                random_arrow_generation_delay = arrow_manager.create_random_generation_delay(); // Set the new delay
                random_arrow_generation_index = 0; // Reset the generation index
            }

            // Increase the velocity of arrows after a certain number of iterations
            if (velocity <= ARROW_MAX_VELOCITY && arrow_velocity_change_index == ARROW_VELOCITY_CHANGE_DELAY_LOOPS)
            {
                velocity++; // Increase the velocity
                arrow_velocity_change_index = 0; // Reset the change index
            }

            // Update the random time delay bounds after a specific number of iterations
            if (random_time_delay_generation_bounds_index == RANDOM_TIME_DELAY_CHANGE_DELAY_LOOPS)
            {
                arrow_manager.update_random_time_delay_generation_bounds(); // Update the bounds
                random_time_delay_generation_bounds_index = 0; // Reset the index
            }

            // Move the arrows with the current velocity, and update their positions
            arrow_manager.move_all_arrows(0, -velocity);
            arrow_manager.draw_all_arrows(); // Draw the arrows on the screen
            arrow_manager.delete_invalid_arrows(); // Delete arrows that are out of bounds or already hit

            // Increment the indices to control timing
            random_arrow_generation_index++;
            arrow_velocity_change_index++;
            random_time_delay_generation_bounds_index++;

            old_direction = direction_to_check; // Update the old direction

            LCD.Update(); // Update the display with the new frame
        }

        game_audio_manager.stop(); // Stop the game audio when the loop finishes

        return score; // Return the final score
    }
} // game
