#pragma once
#include "Bounds.h"
#include "GameObject.h"


class Collider
{
protected:
	GameObject* attachedObject = nullptr;
	Bounds* bounds = nullptr;

	bool enabled = true;

public:

	/*----Getter----*/
	inline GameObject& GetAttachedObject() { return *attachedObject; };
	inline Bounds& GetBounds() { return *bounds; };

	/*----Constructor----*/
	Collider();
	Collider(GameObject* _attachedObejct,float _sizeMultiplier);
	~Collider();

	void UpdateBounds();

	bool IsInCollison();

};