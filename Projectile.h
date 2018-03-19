#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "MovingObject.h"
#include "SmallObject.h"
#include "BigObject.h"

class Tank;

class Projectile :
  public MovingObject, public SmallObject
{
public:
  Projectile (const pair<int, int> coordinates,
              const Way direction, const Tank* owner);
  pair<int, int> setCoordinates (pair<int, int> coordinates);

  bool moveForward ();
  void dealDamage (GameObject& damagedGameObject);
  void getDamaged (Projectile projectile);
  ~Projectile ();
private:
  const Tank* owner_;
};

#endif // !PROJECTILE_H