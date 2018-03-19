#ifndef TANK_H
#define TANK_H

#include "MovingObject.h"
#include "Projectile.h"

class Tank :
  public MovingObject, public BigObject
{
public:
  pair<int, int> setCoordinates (pair<int, int> coordinates);

  bool moveUp ();
  bool moveRight ();
  bool moveLeft ();
  bool moveDown ();
  void shoot () const;
  void getDamaged (Projectile projectile);
  bool moveForward ();

  ~Tank ();
protected:
  Tank (pair<int, int> coordinates, Way direction, int health, int team);
  int health_;
  int team_;
};

#endif // !TANK_H