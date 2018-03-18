#ifndef TANK_H
#define TANK_H

#include "MovingObject.h"
#include "Projectile.h"

class Tank :
  public MovingObject
{
public:
  bool moveUp ();
  bool moveRight ();
  bool moveLeft ();
  bool moveDown ();
  void Shoot () const;
  void getDamaged (Projectile projectile);

  ~Tank ();
protected:
  Tank (pair<int, int> coordinates, Way direction, int health);
  int health_;
};

#endif // !TANK_H