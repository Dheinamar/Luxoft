#ifndef WALL_H
#define WALL_H

#include "GameObject.h"
#include "Projectile.h"

class Wall :
  public GameObject
{
public:
  Wall (pair<int, int> coordinates);
  void getDamaged (Projectile projectile);
  ~Wall ();
};

#endif // !WALL_H
