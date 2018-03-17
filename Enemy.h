#ifndef ENEMY_H
#define ENEMY_H

#include "Tank.h"

class Enemy :
  public Tank
{
public:
  Enemy (pair<int, int> coordinates);
  ~Enemy ();
private:
  static const int HEALTH = 1;
};

#endif // !ENEMY_H