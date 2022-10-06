#pragma once
#include "Includes.h"

#include "Player.h"
#include "Map.h"

class GameManager {
public:
	void Start();
	void Update();
	void Draw(Map currentMap, Player player);
	void Start(Map currentMap, bool isPlaying);
};