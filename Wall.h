#ifndef WALL_H
#define WALL_H

#include "GameObject.h"

class Wall :
  public GameObject
{
public:
  Wall () :GameObject (true) {};
  ~Wall ();
};

#endif // !WALL_H
