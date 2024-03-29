#pragma once
#include "MonoBehaviour.h"
#include "ENet.h"
class TransformSync : MonoBehaviour
{

protected :
	bool isMine = false;
	ENet* reseau = nullptr;
	int photonID = 0;
	float timer = 0;
public :

	TransformSync(bool _isMine, ENet* _reseau);
	TransformSync(bool _isMine, ENet* _reseau,GameObject* _object);
	TransformSync(bool _isMine, int _id,ENet* _reseau,GameObject* _object);

	void Update();
	void UpdatePosition();
	void UpdateElement(glm::vec3 _position);

	void UpdateTimer();
	ENet* GetReseau();
	int GetID();
	bool IsMine();
	

};

