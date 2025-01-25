/**
* @file maze.h
* @authors
* Sudharsan
*
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
*  This is the header for the class MazeFile, this is used to read maze files
*  generated by micro-mouse simulator
*/

#ifndef MAZE_SOLVER_ROBOT_MAZE_H
#define MAZE_SOLVER_ROBOT_MAZE_H


#include <array>
#include <vector>
#include <string>
#include <iostream>
#include "api.h"

namespace fp {

    class Maze {
    public:
        //---> Attributes <---//
        std::array<std::array<bool, 16>, 16> North_;
        std::array<std::array<bool, 16>, 16> South_;
        std::array<std::array<bool, 16>, 16> East_;
        std::array<std::array<bool, 16>, 16> West_;

        //---> Constructor 01: Default Constructor <---//
        Maze() : North_{}, South_{}, East_{}, West_{} {
            for (auto y = 0; y < 16; ++y) {
                for (auto x = 0; x < 16; ++x) {
                    if (x == 0) {
                        this->West_[15 - y][x] = true;
                        API::setWall(x, y, 'w');
                    } else {
                        this->West_[15 - y][x] = false;
                    }
                    if (x == 15) {
                        this->East_[15 - y][x] = true;
                        API::setWall(x, y, 'e');
                    } else {
                        this->East_[15 - y][x] = false;
                    }
                    if (y == 0) {
                        this->South_[15 - y][x] = true;
                        API::setWall(x, y, 's');
                    } else {
                        this->South_[15 - y][x] = false;
                    }
                    if (y == 15) {
                        this->North_[15 - y][x] = true;
                        API::setWall(x, y, 'n');
                    } else {
                        this->North_[15 - y][x] = false;
                    }
                }
            }
        }

        //---> Destructor <---//
        ~Maze() = default;

        //---> method prototypes <---//
        /**
         * @brief It updates the 'n','s','e','w' 2d array.
         * @param x
         * @param y
         * @param direction
         */
        void ReadMaze(std::array<int, 2> curr_node, char direction);

        /**
         * @brief Adds color to the tiles of the maze grid.
         * @param &X
         * @param &Y
         */
        static void ColorPath(std::array<int, 2>);


    };//--class Maze
}//--namespace fp



#endif //MAZE_SOLVER_ROBOT_MAZE_H
