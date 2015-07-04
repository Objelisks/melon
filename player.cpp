#include "player.h"


const float playerSpeed = 0.05f;

Player::Player() : ScenePrimitive(ScenePrimitive::TYPE_SPHERE, 0.5, 16.0, 16.0) {
  this->setColor(1.0, 1.0, 0.0, 1.0);
	CoreServices::getInstance()->getInput()->addEventListener(this, InputEvent::EVENT_KEYDOWN);
	CoreServices::getInstance()->getInput()->addEventListener(this, InputEvent::EVENT_KEYUP);

  this->sword = new Sword();
  this->addChild(this->sword);
}

void Player::addToScene(PhysicsScene* scene) {
  this->controller = scene->addCharacterChild(this, 10.0, 1.0, 0.5);

}

void Player::setPosition(Vector3 pos) {
  this->controller->warpCharacter(pos);
}

void Player::Update() {
  Vector3 move = Vector3(this->movement.x, 0, this->movement.y);
  move.Normalize();
  move = move * playerSpeed;
  this->controller->setWalkDirection(move);
}

void Player::handleEvent(Event* e) {
	if(e->getDispatcher() != CoreServices::getInstance()->getInput()) {
    return;
  }

	InputEvent* inputEvent = (InputEvent*)e;

	if(inputEvent->getEventCode() == InputEvent::EVENT_KEYDOWN) {
    switch (inputEvent->keyCode()) {
      case KEY_UP:
        this->movement.y = 1.0;
        break;
      case KEY_DOWN:
        this->movement.y = -1.0;
        break;
      case KEY_LEFT:
        this->movement.x = 1.0;
        break;
      case KEY_RIGHT:
        this->movement.x = -1.0;
        break;
      case 'x':
        if(!this->sword->isSwinging()) {
          this->sword->swing();
        }
        break;
    }
  } else if(inputEvent->getEventCode() == InputEvent::EVENT_KEYUP) {
    switch (inputEvent->key) {
      case KEY_UP:
      case KEY_DOWN:
        this->movement.y = 0.0;
        break;
      case KEY_LEFT:
      case KEY_RIGHT:
        this->movement.x = 0.0;
        break;
    }
  }
}
