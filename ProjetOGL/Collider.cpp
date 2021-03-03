#include "Collider.h"

Collider::Collider()
{
}

Collider::Collider(GameObject* _attachedObejct)
{
	attachedObject = _attachedObejct;
	bounds = new Bounds(attachedObject->GetTransform()->GetPosition(), attachedObject->GetTransform()->GetScale());
	//ColliderManager::Instance()->Add(this);
}

bool Collider::IsInCollison() {
	//if(ColliderManager::Instance()->IsInCollision(this)
	//	return true;
	return false;
}

