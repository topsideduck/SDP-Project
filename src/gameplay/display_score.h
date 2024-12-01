//
// Created by Harikeshav R on 11/29/24.
//

#ifndef DISPLAYSCORE_H
#define DISPLAYSCORE_H

namespace game
{
    /**
     * @class DisplayScore
     * @brief Responsible for drawing the current score on the screen.
     *
     * The DisplayScore class manages the rendering of the score as a series of images
     * representing the digits of the score. It handles drawing each digit in the
     * correct order on the screen.
     */
    class DisplayScore
    {
    public:
        /**
         * @brief Default constructor for the DisplayScore class.
         *
         * Initializes the DisplayScore object. In this case, no additional setup is required.
         */
        DisplayScore();

        /**
         * @brief Destructor for the DisplayScore class.
         *
         * Cleans up any resources associated with the DisplayScore object.
         * In this case, no dynamic memory is allocated.
         */
        ~DisplayScore();

        /**
         * @brief Draws the current score on the screen.
         *
         * This static method takes the score as an argument, converts it into its
         * individual digits, and draws each digit on the screen. The digits are
         * drawn using preloaded image files.
         *
         * @param score The score to display.
         */
        static void draw_score_on_screen(unsigned int score);
    };
} // game

#endif //DISPLAYSCORE_H
