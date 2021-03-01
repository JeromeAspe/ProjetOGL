#include "MonoBehaviour.h"

MonoBehaviour::MonoBehaviour() : Component() {

}
MonoBehaviour::MonoBehaviour(GameObject* _gameObject) : Component(_gameObject) {

}
MonoBehaviour::~MonoBehaviour() {

}