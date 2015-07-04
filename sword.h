#pragma once

#include "Polycode.h"

using namespace Polycode;

class Sword : public ScenePrimitive {
public:
  Sword();
  void Update();
  bool isSwinging();
  void swing();
private:
  float animationPercent;
  bool swinging;
};
