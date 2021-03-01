#pragma once
#include "Object.h"
#include "Renderer.h"
#include "Transform.h"

class GameObject : public Object
{
	Renderer* renderer = nullptr;
	Transform* transform = nullptr;
};

