#pragma once
#include "GameObject.h"
#include "BoxCollider.h"

class Cube : public GameObject
{
	BoxCollider* collider = nullptr;
};

