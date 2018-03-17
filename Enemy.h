#ifndef ENEMY_H
#define ENEMY_H

#include "Tank.h"

class Enemy :
  public Tank
{
public:
  Enemy () : Tank () {};
  ~Enemy ();
};

#endif // !ENEMY_H