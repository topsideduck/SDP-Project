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
        float x_coordinate, y_coordinate;
        ArrowDirection arrow_direction;

        std::string arrow_image_file_path;
        FEHImage arrow_image;

        bool is_hit = false;

    public:
        explicit Arrow(ArrowDirection direction);

        ~Arrow();

        void update_arrow_position(float delta_x, float delta_y);

        void draw_arrow();

        bool is_out_of_bounds() const;

        bool is_points_received() const;

        int calculate_points_received_for_hit();

        ArrowDirection get_direction() const;
    };
} // game

#endif //ARROW_H
