#ifndef TANK_H
#define TANK_H

#include "GameObject.h"

class Tank :
  public GameObject
{
public:
  ~Tank ();
protected:
  Tank (pair<int, int> coordinates, int health);
  int health_;
};

#endif // !TANK_H