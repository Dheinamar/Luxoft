#ifndef TANK_H
#define TANK_H

#include "GameObject.h"

class Tank :
  public GameObject
{
public:
  Tank () : GameObject (true) {};
  ~Tank ();
};

#endif // !TANK_H