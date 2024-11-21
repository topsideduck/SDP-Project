//
// Created by Harikeshav R on 11/21/24.
//

#include "src/util/play_video.h"

#include <src/lib/FEHImages.h>
#include <src/lib/FEHLCD.h>

void play_video(const std::filesystem::path &frames_folder_path, const int number_of_frames,
                const std::string &base_file_name)
{
    int counter = 1;

    while (counter < number_of_frames)
    {
        std::filesystem::path frame_file = base_file_name + std::to_string(counter) + ".png";
        std::filesystem::path result = frames_folder_path / frame_file;

        LCD.Clear();
        FEHImage credits_frame{result.string().c_str()};
        credits_frame.Draw(0, 0);

        LCD.Update();

        counter++;
    }
}
