#include "Collider.h"

Collider::Collider()
{
}

Collider::Collider(GameObject* _attachedObejct)
{
	attachedObject = _attachedObejct;
	bounds = new Bounds(attachedObject->GetTransform()->GetPosition(), attachedObject->GetTransform()->GetScale());
}
