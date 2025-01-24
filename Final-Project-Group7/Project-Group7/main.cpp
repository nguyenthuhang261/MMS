#include <stdio.h>
#include <memory>
#include "LandBasedRobot.h"
#include "LandBasedTracked.h"
#include "LandBasedWheeled.h"
#include "Maze.h"
#include "API.h"
#include "Algorithm.h"

int main()
{
	fp::Algorithm algo;
	fp::Maze maze;
	std::shared_ptr<fp::LandBasedRobot> robot = std::make_shared<fp::LandBasedWheeled>("Husky", 4, 34, 22, 34, 34, 45, 0,  0, 'n'); // std::string name = "Husky",  int wheel_num = 4, double speed = 34, double width = 22, double length = 34, double height = 34, double capacity = 45, int x = 0, int y = 0, char direction = 'n'
	
	algo.SolveMaze(maze,robot);
	std::cerr<<"Program ended "<<std::endl;
	return 0;
}
