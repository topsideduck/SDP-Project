#include "src/util/play_dance.h" // Include header for play_dance functionality
#include <filesystem>            // For handling file paths
#include "src/gameplay/arrow.h"  // Include ArrowDirection enum
#include "src/util/constants.h"  // Include dance-related constants

/**
 * @brief Displays a dance animation based on the specified direction and updates the animation frame.
 *
 * This function selects and renders the appropriate dance frame for the given direction.
 * The frame updates according to the `dance_counter` and the specified update rate. Once all frames
 * are displayed, the counter resets to loop the animation.
 *
 * @param direction The direction for which the dance animation should be played (e.g., Left, Right, Up, etc.).
 * @param dance_counter Pointer to the frame counter controlling the animation progress.
 * @param x_coordinate X-coordinate for drawing the frame on the screen.
 * @param y_coordinate Y-coordinate for drawing the frame on the screen.
 * @param update_rate The rate at which the animation frames are updated.
 */
void play_dance(const ArrowDirection direction, int *dance_counter, int x_coordinate, int y_coordinate, int update_rate)
{
    std::string dance_frame_base_file_name;
    int number_of_dance_frames{};

    // Determine the base filename and number of frames for the given direction
    switch (direction)
    {
        case (ArrowDirection::Left):
        {
            dance_frame_base_file_name = DANCE_LEFT_BASE_FILE_NAME;
            number_of_dance_frames = DANCE_LEFT_NUMBER_OF_FRAMES;
            break;
        }
        case (ArrowDirection::Up):
        {
            dance_frame_base_file_name = DANCE_UP_BASE_FILE_NAME;
            number_of_dance_frames = DANCE_UP_NUMBER_OF_FRAMES;
            break;
        }
        case (ArrowDirection::Down):
        {
            dance_frame_base_file_name = DANCE_DOWN_BASE_FILE_NAME;
            number_of_dance_frames = DANCE_DOWN_NUMBER_OF_FRAMES;
            break;
        }
        case (ArrowDirection::Right):
        {
            dance_frame_base_file_name = DANCE_RIGHT_BASE_FILE_NAME;
            number_of_dance_frames = DANCE_RIGHT_NUMBER_OF_FRAMES;
            break;
        }
        case (ArrowDirection::Standing):
        {
            dance_frame_base_file_name = DANCE_STANDING_BASE_FILE_NAME;
            number_of_dance_frames = DANCE_STANDING_NUMBER_OF_FRAMES;
            break;
        }
        case (ArrowDirection::Sitting):
        {
            dance_frame_base_file_name = DANCE_SITTING_BASE_FILE_NAME;
            number_of_dance_frames = DANCE_SITTING_NUMBER_OF_FRAMES;
            break;
        }
    }

    // Construct the file path for the current dance frame
    const std::filesystem::path dance_frame_file = dance_frame_base_file_name +
                                                   std::to_string((*dance_counter) / update_rate + 1) + ".png";
    const std::filesystem::path result = DANCE_FRAMES_PATH / dance_frame_file;

    // Load and draw the dance frame
    FEHImage dance_frame{result.string().c_str()};
    dance_frame.Draw(x_coordinate, y_coordinate);

    // Increment the counter and reset if the animation completes
    (*dance_counter)++;

    if (*dance_counter >= update_rate * number_of_dance_frames)
    {
        *dance_counter = 1;
    }
}
