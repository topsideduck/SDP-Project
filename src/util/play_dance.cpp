//
// Created by Harikeshav R on 11/30/24.
//

#include "src/util/play_dance.h"

#include "src/gameplay/arrow.h"
#include "src/util/constants.h"

#include "filesystem"


void play_dance(const ArrowDirection direction, int *dance_counter, int x_coordinate, int y_coordinate, int update_rate)
{
    std::string dance_frame_base_file_name;
    int number_of_dance_frames{};

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
        }
    }

    const std::filesystem::path dance_frame_file = dance_frame_base_file_name + std::to_string(
                                                       (*dance_counter) / update_rate + 1) + ".png";
    const std::filesystem::path result = DANCE_FRAMES_PATH / dance_frame_file;

    FEHImage dance_frame{result.string().c_str()};
    dance_frame.Draw(x_coordinate, y_coordinate);

    (*dance_counter)++;

    if (*dance_counter >= update_rate * number_of_dance_frames)
    {
        *dance_counter = 1;
    }
}
