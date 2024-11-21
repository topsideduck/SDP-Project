//
// Created by Harikeshav R on 11/21/24.
//

#ifndef PLAY_VIDEO_H
#define PLAY_VIDEO_H

#include "filesystem"

void play_video(const std::filesystem::path& frames_folder_path, int number_of_frames, const std::string& base_file_name);

#endif //PLAY_VIDEO_H
