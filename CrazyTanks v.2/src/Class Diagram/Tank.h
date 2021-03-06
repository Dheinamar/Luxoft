/**
 * Project CrazyTanks
 */


#ifndef _TANK_H
#define _TANK_H

#include "MovingObject.h"


class Tank : public MovingObject
{
public:

  Tank (pair<int, int> coordinates, int team);

  void shoot ();

  void moveUp ();

  void moveLeft ();

  void moveDown ();

  void moveRight ();
  
  pair<int, int> getCoordinates () const override;

  Way getWay () const override;

  pair<int, int> setCoordinates (const pair<int, int> coordinates) override;

  void getDamaged (Projectile& projectile) override;

  GameObject& clone (pair<int, int> coordinates) override;

  const int getHealth () const;

  bool operator==(const GameObject& gameObject) override;

protected:
  void moveForward () override;

  int health_;
  const int TEAM = 0;
  pair<int, int> coordinates_;
private:
  const int MAX_HEALTH;

  void turnUp ();

  void turnLeft ();

  void turnDown ();

  void turnRight ();
};

#endif //_TANK_H