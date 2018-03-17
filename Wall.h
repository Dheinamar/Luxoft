#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall :
  public GameObject
{
public:
  Wall (pair<int, int> coordinates);
  ~Wall ();
};

#endif // !WALL_H
