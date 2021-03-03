#include "TransformSync.h"
#include "PacketDataJSon.h"
#include "json.hpp"

TransformSync::TransformSync(bool _isMine, ENet* _reseau)
{
	isMine = _isMine;
	reseau = _reseau;
}

TransformSync::TransformSync(bool _isMine, ENet* _reseau, GameObject* _object) : MonoBehaviour(_object)
{
	isMine = _isMine;
	reseau = _reseau;
}

void TransformSync::Update()
{
	UpdatePosition();
}

void TransformSync::UpdatePosition()
{
	if (isMine) {
		PacketDataJSon _packet;
		json::JSON _json = json::Array(gameObject->GetTransform()->GetPosition().x, gameObject->GetTransform()->GetPosition().y, gameObject->GetTransform()->GetPosition().z, gameObject->GetIndexEngine());
		//json::JSON _json = json::JSON(true);
		_packet.SetJsonContent(_json.dump().c_str());
		if (_packet.IsValid()) {
			unsigned int  taille = 0;
			void* data = _packet.Serialize(taille);
			_packet.Deserialize(data, taille);
			printf("%s", _packet.GetContent());
		}
	}
}
