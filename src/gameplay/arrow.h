//
// Created by Harikeshav R on 11/29/24.
//

#ifndef ARROW_H
#define ARROW_H

#include "string"
#include "src/lib/FEHImages.h"


enum ArrowDirection
{
    Left,
    Right,
    Up,
    Down
};


namespace game
{
    class Arrow
    {
    private:
        int x_coordinate, y_coordinate;
        std::string arrow_image_file_path;
        ArrowDirection arrow_direction;
        FEHImage arrow_image;

    public:
        explicit Arrow(ArrowDirection direction);

        ~Arrow();

        void update_arrow_position(int delta_x, int delta_y);

        void draw_arrow();

        bool is_out_of_bounds();
    };
} // game

#endif //ARROW_H
