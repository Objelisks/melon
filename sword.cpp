#include "sword.h"

const Number swingSpeed = 15.0f;

Sword::Sword() : ScenePrimitive(ScenePrimitive::TYPE_BOX, 1.4, 0.1, 0.5) {
  this->swinging = false;
  this->animationPercent = 0.0f;
  this->setAnchorPoint(0.7, 0, 0);
}

void Sword::Update() {
  Number elapsed = CoreServices::getInstance()->getCore()->getElapsed();
  if(this->swinging) {
    this->animationPercent += elapsed * swingSpeed;
    if(this->animationPercent > 1.0f) {
      this->swinging = false;
    }
  }
  this->setYaw(this->animationPercent*90);
}

bool Sword::isSwinging() {
  return this->swinging;
}

void Sword::swing() {
  this->animationPercent = 0.0f;
  this->swinging = true;
}
