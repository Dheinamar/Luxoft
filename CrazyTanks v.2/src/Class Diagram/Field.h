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
#include "CreateWallStrategy.h"
#include "CreateEnemyStrategy.h"


class Field : public DrawInfo
{
public:

  Field ();

  const vector<Projectile> getProjectiles () const override;

  vector<Tank>& getEnemies () const override;

  const int getMaxEnemies () const override;

  const vector<Wall> getWalls () const override;

  const Gold getGold () const override;

  unique_ptr<Tank>& getPlayer () const override;

  const int getSize () const override;

  const int getTime () const override;

  void setTime (const int time);

  Cell** getField ();

  static unique_ptr<Field>& getInstance ();

  /**
   * @param projectile
   */
  void addProjectile (const Projectile& projectile);

  /**
   * @param projectile
   */
  void removeProjectile (Projectile& projectile);

  /**
   * @param enemy
   */
  void addEnemy (const Tank& enemy);

  /**
   * @param enemy
   */
  void removeEnemy (Tank& enemy);

  /**
   * @param wall
   */
  void addWall (const Wall& wall);

  /**
   * @param wall
   */
  void removeWall (Wall& wall);

  const int getWallSize () const;

  Cell& operator[](pair<int, int> indices) const;
private:
  static const int FIELD_SIZE = 10;
  static const int N_WAYS = 4;
  static const int N_WALLS = 6;
  static const int WALL_SIZE = 2;
  static const int N_ENEMIES = 6;
  static const pair<int, int> PLAYER_COORDINATES;
  int time_;
  Cell** field_;
  static unique_ptr<Field> instance_;
  vector<Tank> enemies_;
  static unique_ptr<Tank> player_;
  vector<Wall> walls_;
  Gold gold_;
  vector<Projectile> projectiles_;
  unique_ptr<CreateObjectStrategy> creationStrategy_;

  /**
   * @param strategy
   */
  void SetCreationStrategy (const CreateObjectStrategy& strategy);

  void createFortress ();
};

#endif //_FIELD_H