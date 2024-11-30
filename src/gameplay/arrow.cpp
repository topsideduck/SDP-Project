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
            case ArrowDirection::Left:
            {
                x_coordinate = LEFT_ARROW_START_X_COORDINATE;
                y_coordinate = LEFT_ARROW_START_Y_COORDINATE;
                arrow_image_file_path = LEFT_ARROW_IMAGE_FILE_PATH;

                break;
            }

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
                arrow_image_file_path = DOWN_ARROW_IMAGE_FILE_PATH;

                break;
            }

            case ArrowDirection::Right:
            {
                x_coordinate = RIGHT_ARROW_START_X_COORDINATE;
                y_coordinate = RIGHT_ARROW_START_Y_COORDINATE;
                arrow_image_file_path = RIGHT_ARROW_IMAGE_FILE_PATH;

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

    bool Arrow::is_out_of_bounds() const
    {
        switch (arrow_direction)
        {
            case ArrowDirection::Left:
            {
                return x_coordinate == LEFT_ARROW_END_X_COORDINATE && y_coordinate <= LEFT_ARROW_END_Y_COORDINATE;
            }

            case ArrowDirection::Up:
            {
                return x_coordinate == UP_ARROW_END_X_COORDINATE && y_coordinate <= UP_ARROW_END_Y_COORDINATE;
            }

            case ArrowDirection::Down:
            {
                return x_coordinate == DOWN_ARROW_END_X_COORDINATE && y_coordinate <= DOWN_ARROW_END_Y_COORDINATE;
            }

            case ArrowDirection::Right:
            {
                return x_coordinate == RIGHT_ARROW_END_X_COORDINATE && y_coordinate <= RIGHT_ARROW_END_Y_COORDINATE;
            }
        }
        return false;
    }

    int Arrow::calculate_points_received_for_hit()
    {
        if (is_hit)
        {
            return 0;
        }

        int end_y_coordinate;

        switch (arrow_direction)
        {
            case ArrowDirection::Left:
            {
                end_y_coordinate = LEFT_ARROW_END_Y_COORDINATE;
                break;
            }

            case ArrowDirection::Up:
            {
                end_y_coordinate = UP_ARROW_END_Y_COORDINATE;
                break;
            }

            case ArrowDirection::Down:
            {
                end_y_coordinate = DOWN_ARROW_END_Y_COORDINATE;
                break;
            }

            case ArrowDirection::Right:
            {
                end_y_coordinate = RIGHT_ARROW_END_Y_COORDINATE;
                break;
            }
            default:
            {
                end_y_coordinate = 0;
            }
        }

        const int distance = abs(y_coordinate - end_y_coordinate);
        int points_received;


        if (distance < 30 && distance >= 20)
        {
            is_hit = true;
            points_received = 1;
        }
        else if (distance < 20 && distance >= 10)
        {
            is_hit = true;
            points_received = 2;
        }
        else if (distance < 10 && distance >= 0)
        {
            is_hit = true;
            points_received = 3;
        }
        else
        {
            points_received = 0;
        }

        return points_received;
    }

    bool Arrow::is_points_received() const
    {
        return is_hit;
    }
} // game
