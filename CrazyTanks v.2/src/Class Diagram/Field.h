/**
 * Project CrazyTanks
 */


#ifndef _FIELD_H
#define _FIELD_H

#include <vector>

#include "DrawInfo.h"
#include "Projectile.h"
#include "Tank.h"
#include "Wall.h"
#include "Cell.h"
#include "Gold.h"
#include "CreateObjectStrategy.h"


class Field : public DrawInfo
{
public:

  const vector<Projectile> getProjectiles () const override;

  const vector<Tank> getEnemies () const override;

  const int getMaxEnemies () const override;

  const vector<Wall> getWalls () const override;

  const Gold getGold () const override;

  Tank getPlayer () override;

  int getSize () override;

  int getTime () override;

  Cell** getField ();

  static unique_ptr<Field> getInstance ();

  /**
   * @param projectile
   */
  void addProjectile (const Projectile& projectile);

  /**
   * @param projectile
   */
  void removeProjectile (const Projectile& projectile);

  /**
   * @param enemy
   */
  void addEnemy (const Tank enemy);

  /**
   * @param enemy
   */
  void removeEnemy (const Tank enemy);

  /**
   * @param wall
   */
  void addWall (const Wall wall);

  /**
   * @param wall
   */
  void removeWall (const Wall wall);

  const int getWallSize () const;

  Cell& operator[](pair<int, int> indices) const;
private:
  static const int FIELD_SIZE = 10;
  static const int N_WAYS = 4;
  static const int N_WALLS = 6;
  static const int WALL_SIZE = 2;
  static const int N_ENEMIES = 6;
  Cell field_[FIELD_SIZE][FIELD_SIZE];
  static unique_ptr<Field> instance_;
  vector<Tank> enemies_;
  Tank player_;
  vector<Wall> walls_;
  Gold gold_;
  vector<Projectile> projectiles_;
  unique_ptr<CreateObjectStrategy> creationStrategy_;

  /**
   * @param strategy
   */
  void SetCreationStrategy (const CreateObjectStrategy& strategy);
};

#endif //_FIELD_H