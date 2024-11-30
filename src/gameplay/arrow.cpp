//
// Created by Harikeshav R on 11/29/24.
//

#include "src/gameplay/arrow.h"

#include "src/lib/FEHImages.h"
#include "src/util/constants.h"



namespace game
{
    Arrow::Arrow(const ArrowDirection direction)
    {
        this->arrow_direction = direction;

        switch (direction)
        {
            case ArrowDirection::Up:
            {
                x_coordinate = UP_ARROW_START_X_COORDINATE;
                y_coordinate = UP_ARROW_START_Y_COORDINATE;
                arrow_image_file_path = UP_ARROW_IMAGE_FILE_PATH;
                break;
            }

            case ArrowDirection::Down:
            {
                x_coordinate = DOWN_ARROW_START_X_COORDINATE;
                y_coordinate = DOWN_ARROW_START_Y_COORDINATE;
                break;
            }

            case ArrowDirection::Left:
            {
                x_coordinate = LEFT_ARROW_START_X_COORDINATE;
                y_coordinate = LEFT_ARROW_START_Y_COORDINATE;
                break;
            }

            case ArrowDirection::Right:
            {
                x_coordinate = RIGHT_ARROW_START_X_COORDINATE;
                y_coordinate = RIGHT_ARROW_START_Y_COORDINATE;
                break;
            }
        }

        arrow_image.Open(arrow_image_file_path.c_str());
    }

    Arrow::~Arrow()
    {
        arrow_image.Close();
    }

    void Arrow::update_arrow_position(const int delta_x, const int delta_y)
    {
        x_coordinate += delta_x;
        y_coordinate += delta_y;
    }

    void Arrow::draw_arrow()
    {
        arrow_image.Draw(x_coordinate, y_coordinate);
    }


} // game
