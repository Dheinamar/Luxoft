#pragma once
#include "Tank.h"
class Player :
  public Tank
{
public:
  Player();
  static Player* get();
  ~Player();
private:
  static Player* instance_;
};

