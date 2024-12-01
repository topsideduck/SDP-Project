//
// Created by Harikeshav R on 11/29/24.
//

#include "src/gameplay/arrow.h"

#include "src/lib/FEHImages.h"
#include "src/util/constants.h"


namespace game
{
    /**
     * @brief Constructs an Arrow object with a specified direction.
     *
     * This constructor initializes the arrow's direction, position, and image file path based on the given direction.
     * The image associated with the arrow is loaded after the attributes are set.
     *
     * @param direction The direction of the arrow (Left, Right, Up, Down).
     */
    Arrow::Arrow(const ArrowDirection direction)
    {
        this->arrow_direction = direction;

        // Initialize arrow position and image based on direction
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

        // Load the arrow image from the specified file path
        arrow_image.Open(arrow_image_file_path.c_str());
    }

    /**
     * @brief Destructor for the Arrow class.
     *
     * This destructor releases any resources associated with the Arrow object,
     * such as closing the image used for drawing the arrow.
     */
    Arrow::~Arrow()
    {
        arrow_image.Close();
    }

    /**
     * @brief Updates the position of the arrow.
     *
     * This function modifies the arrow's position based on the specified deltas for the x and y coordinates.
     *
     * @param delta_x The change in the x-coordinate.
     * @param delta_y The change in the y-coordinate.
     */
    void Arrow::update_arrow_position(const float delta_x, const float delta_y)
    {
        x_coordinate += delta_x;
        y_coordinate += delta_y;
    }

    /**
     * @brief Draws the arrow on the screen.
     *
     * This function renders the arrow at its current position on the LCD screen.
     */
    void Arrow::draw_arrow()
    {
        arrow_image.Draw(x_coordinate, y_coordinate);
    }

    /**
     * @brief Checks if the arrow is out of bounds.
     *
     * This function checks if the arrow has reached the predefined end position for its direction.
     *
     * @return True if the arrow has reached the end of its path, false otherwise.
     */
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

    /**
     * @brief Calculates the points received for a successful hit on the target.
     *
     * This function calculates the points based on how close the arrow is to the target. The closer the arrow is to the
     * target's final position, the more points are awarded.
     *
     * @return The points received for hitting the target, or 0 if no hit was detected.
     */
    int Arrow::calculate_points_received_for_hit()
    {
        if (is_hit)
        {
            return 0; // Return 0 if points have already been received
        }

        float end_y_coordinate;

        // Determine the target position based on the direction of the arrow
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
                end_y_coordinate = 0; // Default case in case of invalid direction
            }
        }

        // Calculate the distance between the current position and the target
        const int distance = abs(y_coordinate - end_y_coordinate);
        int points_received;

        // Award points based on the distance
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

    /**
     * @brief Checks if the arrow has already received points for a hit.
     *
     * This function returns whether the arrow has already received points based on its proximity to the target.
     *
     * @return True if the arrow has been hit and points have been received, false otherwise.
     */
    bool Arrow::is_points_received() const
    {
        return is_hit;
    }

    /**
     * @brief Gets the direction of the arrow.
     *
     * This function returns the current direction of the arrow.
     *
     * @return The direction of the arrow as an ArrowDirection enum value.
     */
    ArrowDirection Arrow::get_direction() const
    {
        return arrow_direction;
    }
} // game
