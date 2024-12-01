//
// Created by Harikeshav R on 11/30/24.
//

#ifndef MAINGAME_H
#define MAINGAME_H

#include "src/gameplay/arrow.h"

namespace game
{
    class MainGame
    {
    public:
        MainGame();

        ~MainGame();

        static unsigned int main_loop(const std::string& music_audio_file_path, const std::string& music_info_file_path);
    };
} // game

#endif //MAINGAME_H
