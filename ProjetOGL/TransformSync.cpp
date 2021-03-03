#include "TransformSync.h"
#include "PacketDataJSon.h"
#include "PlayerManager.h"
#include "json.hpp"
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

void TransformSync::Update()
{
	UpdatePosition();
}

void TransformSync::UpdatePosition()
{
	if (isMine) {
		PacketDataJSon _packet;
		json::JSON _json = json::Array(gameObject->GetTransform()->GetPosition().x, gameObject->GetTransform()->GetPosition().y, gameObject->GetTransform()->GetPosition().z, photonID);
		//json::JSON _json = json::JSON(true);
		_packet.SetJsonContent(_json.dump().c_str());
		if (_packet.IsValid()) {
			unsigned int  taille = 0;
			void* data = _packet.Serialize(taille);
			
			reseau->BroadcastPacket(false, _packet.GetContent());
			_packet.Deserialize(data, taille);
			//printf("%s\n", _packet.GetContent());
			
			
		}
	}
}
