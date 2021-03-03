#pragma once
#include "MonoBehaviour.h"
#include "ENet.h"
class TransformSync : MonoBehaviour
{

protected :
	bool isMine = false;
	ENet* reseau = nullptr;
public :

	TransformSync(bool _isMine, ENet* _reseau);
	TransformSync(bool _isMine, ENet* _reseau,GameObject* _object);

	void Update();
	void UpdatePosition();
};

