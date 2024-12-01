//
// Created by Harikeshav R on 11/30/24.
//

#ifndef MAINGAME_H
#define MAINGAME_H

#include "src/gameplay/arrow.h"

namespace game
{
    /**
     * @class MainGame
     * @brief Main class that controls the gameplay loop.
     *
     * The MainGame class handles the core game logic, including user input,
     * arrow generation, velocity changes, scoring, and drawing. It also manages
     * the background audio and animation for the dance actions.
     */
    class MainGame
    {
    public:
        /**
         * @brief Default constructor for the MainGame class.
         *
         * Initializes the MainGame object, setting up any necessary game state.
         */
        MainGame();

        /**
         * @brief Destructor for the MainGame class.
         *
         * Cleans up any resources allocated during the gameplay loop.
         */
        ~MainGame();

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
        static unsigned int main_loop(const std::string &music_audio_file_path,
                                      const std::string &music_info_file_path);
    };
} // game

#endif //MAINGAME_H
