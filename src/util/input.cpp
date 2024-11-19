//
// Created by Harikeshav R on 11/19/24.
//


#include "src/util/input.h"
#include <tuple>
#include "src/lib/FEHLCD.h"


std::tuple<float, float> get_input_coordinates()
{
    float x_coordinate, y_coordinate;
    float x_trash, y_trash;


    while (!LCD.Touch(&x_coordinate, &y_coordinate))
    {
    };

    while (LCD.Touch(&x_trash, &y_trash))
    {
    };


    return {x_coordinate, y_coordinate};
}
