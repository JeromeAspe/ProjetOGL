#pragma once
#include "Collider.h"

class SphereCollider : public Collider
{
public :
	SphereCollider(GameObject* _object, float _sizeMultiplier);
};

