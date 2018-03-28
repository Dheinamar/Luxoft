/**
 * Project CrazyTanks
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "MovingObject.h"

class Tank;
class Projectile : public MovingObject
{
public:

  Projectile (pair<int, int> coordinates, Way way, Tank owner);

  /**
   * @param object
   */
  void dealDamage (GameObject& object);

  void moveForward () override;

  pair<int, int> getCoordinates () const override;

  Way getWay () const override;

  pair<int, int> setCoordinates (const pair<int, int> coordinates) override;

  void getDamaged (Projectile& projectile) override;

  GameObject& clone (pair<int, int> coordinates) override;

  bool operator==(const GameObject& gameObject) override;
private:
  Tank owner_;
};

#endif //_PROJECTILE_H