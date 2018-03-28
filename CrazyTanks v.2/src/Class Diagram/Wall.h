/**
 * Project CrazyTanks
 */


#ifndef _WALL_H
#define _WALL_H

#include "GameObject.h"


class Wall: public GameObject {
public:

  Wall (pair<int, int> coordinates);

  pair<int, int> getCoordinates () const override;

  /**
  * @param coordinates
  */
  pair<int, int> setCoordinates (const pair<int, int> coordinates) override;

  Way getWay () const override;

  /**
  * @param projectile
  */
  void getDamaged (Projectile& projectile) override;

  GameObject& clone (pair<int, int> coordinates) override;
};

#endif //_WALL_H;