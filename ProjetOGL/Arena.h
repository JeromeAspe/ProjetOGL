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

