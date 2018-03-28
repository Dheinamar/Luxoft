/**
 * Project CrazyTanks
 */


#ifndef _GOLD_H
#define _GOLD_H

#include <memory>>

#include "GameObject.h"


class Gold : public GameObject
{
public:

  pair<int, int> getCoordinates () const override;

  Way getWay () const override;

  /**
  * @param coordinates
  */
  pair<int, int> setCoordinates (const pair<int, int> coordinates) override;

  /**
  * @param projectile
  */
  void getDamaged (Projectile& projectile) override;

  GameObject& clone (pair<int, int> coordinates) override;

  static unique_ptr<Gold> getInstance ();

  bool operator==(const GameObject& gameObject);
private:
  static unique_ptr<Gold> instance;
};

#endif //_GOLD_H