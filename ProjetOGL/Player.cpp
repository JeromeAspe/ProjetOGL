#include "Player.h"

Player::Player() : MonoBehaviour() {}
Player::Player(GameObject* _gameObject) : MonoBehaviour(_gameObject) {}
Player::Player(std::string _nickname, float _speed) : MonoBehaviour() {
	nickname = _nickname;
	playerSpeed = _speed;
}
Player::Player(std::string _nickname, float _speed, GameObject* _gameObject) : MonoBehaviour(_gameObject) {
	nickname = _nickname;
	playerSpeed = _speed;
}
Player::~Player() {

}