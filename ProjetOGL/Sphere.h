#pragma once
#include "GameObject.h"
#include "SphereCollider.h"

class Sphere : public GameObject
{
	SphereCollider* collider = nullptr;
};

