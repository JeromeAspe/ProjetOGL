#include "Collider.h"

Collider::Collider()
{
}

Collider::Collider(GameObject* _attachedObejct,float _sizeMultiplier)
{
	attachedObject = _attachedObejct;
	bounds = new Bounds(attachedObject->GetTransform()->GetPosition(), attachedObject->GetTransform()->GetScale(), _sizeMultiplier);
	//ColliderManager::Instance()->Add(this);
}
void Collider::UpdateBounds()
{
	bounds->SetCenter(attachedObject->GetTransform()->GetPosition());
	bounds->SetSize(attachedObject->GetTransform()->GetScale());
}

bool Collider::IsInCollison() {
	//if(ColliderManager::Instance()->IsInCollision(this)
	//	return true;
	return false;
}

