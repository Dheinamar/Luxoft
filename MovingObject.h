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
  virtual pair<int, int> setCoordinates (pair<int, int> coordinates) = 0;
  bool moveForward ();
  ~MovingObject ();
protected:
  Way direction_;
};

#endif // !MOVINGOBJECT_H