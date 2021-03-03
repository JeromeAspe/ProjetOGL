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
	UpdatePosition();
}

void TransformSync::UpdatePosition()
{
	if (isMine) {
		PacketDataJSon _packet;
		std::string _msg = reseau->ConvertPacket(gameObject->GetTransform()->GetPosition(), photonID);
		/*json::JSON _json = json::Object();
		_json["x"] = gameObject->GetTransform()->GetPosition().x;//json::Array(gameObject->GetTransform()->GetPosition().x, gameObject->GetTransform()->GetPosition().y, gameObject->GetTransform()->GetPosition().z, photonID);
		_json["y"] = gameObject->GetTransform()->GetPosition().y;
		_json["z"] = gameObject->GetTransform()->GetPosition().z;
		_json["id"] = photonID;*/
		_packet.SetJsonContent(_msg.c_str());
		if (_packet.IsValid()) {
			unsigned int  taille = 0;
			void* data = _packet.Serialize(taille);
			
			reseau->BroadcastPacket(false, _packet.GetContent());
			//_packet.Deserialize(data, taille);
			//json::JSON _converted = json::JSON::Load(_packet.GetContent());
			//printf("%d\n", _converted["id"]);
			
			
		}
	}
}

void TransformSync::UpdateElement(glm::vec3 _position)
{
	gameObject->GetTransform()->SetPosition(_position);
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
