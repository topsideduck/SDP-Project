#ifndef PLAY_VIDEO_H
#define PLAY_VIDEO_H

#include <filesystem> // For handling file paths

/**
 * @brief Plays a video by displaying sequential image frames.
 *
 * This function takes a folder containing video frames as image files and displays them
 * sequentially on the LCD screen to simulate video playback.
 *
 * @param frames_folder_path The path to the folder containing the frame images.
 * @param number_of_frames The total number of frames to display.
 * @param base_file_name The base name of the frame files (excluding the numeric suffix and file extension).
 */
void play_video(const std::filesystem::path &frames_folder_path, int number_of_frames,
                const std::string &base_file_name);

#endif // PLAY_VIDEO_H
