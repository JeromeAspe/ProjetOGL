#pragma once
#include "Collider.h"

class BoxCollider : public Collider
{
public:
	BoxCollider(GameObject* _object,float _sizeMultiplier);
};

