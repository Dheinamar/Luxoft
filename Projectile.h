#pragma once
#include "MovingObject.h"
class Projectile :
  public MovingObject
{
public:
  Projectile (pair<int, int> coordinates, Way direction);
  bool moveForward ();
  void getDamaged (Projectile projectile);
  ~Projectile ();
};

