#include "MonoBehaviour.h"
#include "Engine.h"

MonoBehaviour::MonoBehaviour() : Component() {
	// Ajouter a l'engine
	Engine::GetInstance()->AddMonoBehaviours(this, indexEngine);
}
MonoBehaviour::MonoBehaviour(GameObject* _gameObject) : Component (_gameObject) {
	// ajouter a l'engine
	Engine::GetInstance()->AddMonoBehaviours(this, indexEngine);
}
MonoBehaviour::~MonoBehaviour() {

}
