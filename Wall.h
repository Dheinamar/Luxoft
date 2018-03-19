#ifndef WALL_H
#define WALL_H

#include "BigObject.h"
#include "Projectile.h"

class Wall :
  public BigObject
{
public:
  Wall (pair<int, int> coordinates);
  void getDamaged (Projectile projectile);
  ~Wall ();
};

#endif // !WALL_H
