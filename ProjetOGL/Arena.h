#define ARENA_SIZE 1
#define ARENA_WALL_HEIGHT 2
#define ARENA_WALL_WIDTH

#pragma once
#include <vector>
#include "GameObject.h"

class Arena
{
private :
	std::vector<GameObject> arenaObjects;

	float wallSize = 1;
public:
	Arena();
	~Arena();

	void GenerateArena();
};

