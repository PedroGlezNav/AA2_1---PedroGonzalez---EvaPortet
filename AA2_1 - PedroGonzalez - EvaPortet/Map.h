#pragma once
#include "Includes.h"

#include "Portal.h"
#include "Chest.h"

class Map
{
public:
	std::vector<Portal> potals; //(4)
	std::vector<Chest> chests; //(x)
	std::vector<std::vector<char>> map{ { '#', '#', '#', ' ', '#', '#', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ ' ', ' ', ' ', ' ', ' ', ' ', ' '},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', ' ', ' ', ' ', ' ', ' ', '#'},
										{ '#', '#', '#', ' ', '#', '#', '#'} };

	Map();
};