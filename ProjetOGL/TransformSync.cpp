#include "TransformSync.h"
#include "PacketDataJSon.h"
#include "PlayerManager.h"
//#include "json.hpp"
#include <random>
#include <ctime>

TransformSync::TransformSync(bool _isMine, ENet* _reseau)
{
	isMine = _isMine;
	reseau = _reseau;
}

TransformSync::TransformSync(bool _isMine, ENet* _reseau, GameObject* _object) : MonoBehaviour(_object)
{
	isMine = _isMine;
	reseau = _reseau;
	srand(time(NULL));
	photonID = static_cast<float>(std::rand()) * static_cast<float>(std::rand());
	PlayerManager::Instance()->Add(this);
}

TransformSync::TransformSync(bool _isMine, int _id, ENet* _reseau, GameObject* _object) : MonoBehaviour(_object)
{
	isMine = _isMine;
	reseau = _reseau;
	photonID = _id;
	PlayerManager::Instance()->Add(this);
}

void TransformSync::Update()
{
	UpdateTimer();
}

void TransformSync::UpdatePosition()
{
	if (isMine) {
		PacketDataJSon _packet;
		std::string _msg = reseau->ConvertPacket(gameObject->GetTransform()->GetPosition(), photonID);
		_packet.SetJsonContent(_msg.c_str());
		if (_packet.IsValid()) {
			unsigned int  taille = 0;
			void* data = _packet.Serialize(taille);
			if (reseau->IsClient()) {
				reseau->SendPacket(false, _packet.GetContent());
			}
			if (reseau->IsServer()) {
				reseau->BroadcastPacket(false, _packet.GetContent());
			}
		}
	}
}

void TransformSync::UpdateElement(glm::vec3 _position)
{
	gameObject->GetTransform()->SetFinalPosition(_position);
}

void TransformSync::UpdateTimer()
{
	static double lastTime = glfwGetTime();
	
	// Compute time difference between current and last frame
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);
	timer += deltaTime;
	
	if (timer > 0.2f) {
		UpdatePosition();
		timer = 0;
	}
	lastTime = currentTime;
}

ENet* TransformSync::GetReseau()
{
	return reseau;
}

int TransformSync::GetID()
{
	return photonID;
}

bool TransformSync::IsMine()
{
	return isMine;
}
