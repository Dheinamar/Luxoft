#ifndef ENEMY_H
#define ENEMY_H

#include "Tank.h"

class Enemy :
  public Tank
{
public:
  Enemy (pair<int, int> coordinates, Way direction);
  ~Enemy ();
private:
  static const int HEALTH = 1;
  static const int TEAM = 2;
};

#endif // !ENEMY_H