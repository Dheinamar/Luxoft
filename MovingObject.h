#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "GameObject.h"

enum Way
{
  UP = 0,
  RIGHT,
  DOWN,
  LEFT
};

class MovingObject :
  public GameObject
{
public:
  MovingObject (pair<int, int> coordinates, Way direction);
  bool moveForward ();
  ~MovingObject ();
protected:
  Way direction_;
};

#endif // !MOVINGOBJECT_H