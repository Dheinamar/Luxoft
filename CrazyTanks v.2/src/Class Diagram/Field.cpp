/**
 * Project CrazyTanks
 */


#include "Field.h"

 /**
  * Field implementation
  */

unique_ptr<Field> Field::instance_ = nullptr;
unique_ptr<Tank> Field::player_ = nullptr;
const pair<int, int> Field::PLAYER_COORDINATES = pair<int, int> (FIELD_SIZE / 2,
                                                                 FIELD_SIZE - 3);

Cell**
Field::getField ()
{
  return field_;
}

unique_ptr<Field>&
Field::getInstance ()
{
  if (!instance_) {
    instance_.reset (new Field ());
  }

  return instance_;
}

/**
 * @param projectile
 */
void
Field::addProjectile (const Projectile& projectile)
{
  projectiles_.push_back (projectile);
}

/**
 * @param projectile
 */
void
Field::removeProjectile (Projectile& projectile)
{
  for (auto i = projectiles_.begin (); i != projectiles_.end (); i++) {
    if (projectile == *i) {
      projectiles_.erase (i);
    }
  }
}

/**
 * @param enemy
 */
void
Field::addEnemy (const Tank& enemy)
{
  enemies_.push_back (enemy);
}

/**
 * @param enemy
 */
void
Field::removeEnemy (Tank& enemy)
{
  for (auto i = enemies_.begin (); i != enemies_.end (); i++) {
    if (enemy == *i) {
      enemies_.erase (i);
    }
  }
}

/**
 * @param wall
 */
void
Field::addWall (const Wall& wall)
{
  walls_.push_back (wall);
}

/**
 * @param wall
 */
void
Field::removeWall (Wall& wall)
{
  for (auto i = walls_.begin (); i != walls_.end (); i++) {
    if (wall == *i) {
      walls_.erase (i);
    }
  }
}

const int
Field::getWallSize () const
{
  return WALL_SIZE;
}

Cell &
Field::operator[](pair<int, int> indices) const
{
  return field_[indices.first][indices.second];
}

/**
 * @param strategy
 */
void
Field::SetCreationStrategy (const CreateObjectStrategy& strategy)
{
  creationStrategy_.reset(const_cast<CreateObjectStrategy*>(&strategy));
}

void Field::createFortress ()
{
  gold_ = *Gold::getInstance ();
  addWall (Wall (pair<int, int> (gold_.getCoordinates ().first - 1,
                                 gold_.getCoordinates ().second)));
  addWall (Wall (pair<int, int> (gold_.getCoordinates ().first - 1,
                                 gold_.getCoordinates ().second - 1)));
  addWall (Wall (pair<int, int> (gold_.getCoordinates ().first,
                                 gold_.getCoordinates ().second - 1)));
  addWall (Wall (pair<int, int> (gold_.getCoordinates ().first + 1,
                                 gold_.getCoordinates ().second - 1)));
  addWall (Wall (pair<int, int> (gold_.getCoordinates ().first + 1,
                                 gold_.getCoordinates ().second)));
}

Field::Field ()
{
  field_ = new Cell*[FIELD_SIZE];
  for (auto i = 0; i < FIELD_SIZE; i++) {
    field_[i] = static_cast<Cell*>(operator new(sizeof (Cell) * FIELD_SIZE));
    for (auto j = 0; j < FIELD_SIZE; j++) {
      field_[i][j] = Cell (pair<int, int> (i, j));
    }
  }

  getPlayer ();
  createFortress ();
  SetCreationStrategy (CreateWallStrategy ());
  for (auto i = 0; i < N_WALLS; i++) {
    auto wall = creationStrategy_->CreateObject (walls_[0]);
    for (auto j = wall.begin(); j != wall.end(); j++) {
      addWall (dynamic_cast<Wall&>(*j));
    }
  }
  SetCreationStrategy (CreateEnemyStrategy ());
  for (auto i = 0; i < N_ENEMIES; i++) {
    auto enemy = creationStrategy_->CreateObject (Tank (pair<int, int> (0, 0),
                                                        2));
    for (auto j = enemy.begin (); j != enemy.end (); j++) {
      addEnemy (dynamic_cast<Tank&>(*j));
    }
  }
}

const vector<Projectile>
Field::getProjectiles () const
{
  return projectiles_;
}

vector<Tank>&
Field::getEnemies () const
{
  return const_cast<vector<Tank>&>(enemies_);
}

const int
Field::getMaxEnemies () const
{
  return N_ENEMIES;
}

const vector<Wall>
Field::getWalls () const
{
  return walls_;
}

const Gold
Field::getGold () const
{
  return gold_;
}

unique_ptr<Tank>&
Field::getPlayer () const
{
  if (!player_) {
    player_.reset (new Tank (PLAYER_COORDINATES, 1));
  }
  return player_;
}

const int
Field::getSize () const
{
  return FIELD_SIZE;
}

const int
Field::getTime () const
{
  return time_;
}

void Field::setTime (const int time)
{
  time_ = time;
}
