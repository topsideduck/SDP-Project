#include "src/util/play_video.h" // Include custom header file for video playback functionality
#include <filesystem>           // For handling file paths
#include "src/lib/FEHImages.h"  // For handling image files with FEHImage class
#include "src/lib/FEHLCD.h"     // For managing LCD display operations

/**
 * @brief Plays a video by displaying a sequence of image frames stored in a specified folder.
 *
 * This function iteratively loads and displays a series of frames from a folder, simulating video playback.
 * Each frame file is expected to have a base name followed by a numerical suffix and the ".png" extension.
 * For each frame, the screen is cleared, the image is loaded, drawn, and updated on the LCD.
 *
 * @param frames_folder_path The path to the folder containing the frame images.
 * @param number_of_frames The total number of frames to display.
 * @param base_file_name The base name of the frame files, without the numeric suffix or extension.
 */
void play_video(const std::filesystem::path &frames_folder_path, const int number_of_frames,
                const std::string &base_file_name)
{
    int counter = 1; // Start with the first frame

    // Loop through each frame in sequence
    while (counter < number_of_frames)
    {
        // Construct the full path to the current frame file
        std::filesystem::path frame_file = base_file_name + std::to_string(counter) + ".png";
        std::filesystem::path result = frames_folder_path / frame_file;

        // Clear the LCD screen
        LCD.Clear();

        // Load and draw the current frame
        FEHImage frame_image{result.string().c_str()};
        frame_image.Draw(0, 0);

        // Update the LCD display to show the drawn frame
        LCD.Update();

        // Move to the next frame
        counter++;
    }
}
