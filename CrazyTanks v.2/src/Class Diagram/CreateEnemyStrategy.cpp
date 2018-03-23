/**
 * Project CrazyTanks
 */


#include "CreateEnemyStrategy.h"

 /**
  * CreateEnemyStrategy implementation
  */

vector<GameObject>
CreateEnemyStrategy::CreateObject (const GameObject& prototype)
{
  auto coordinates = getEnemyCoordinates ();
  vector<GameObject> created;

  created.push_back(const_cast<GameObject&>(prototype).clone (coordinates));

  return created;
}

pair<int, int>
CreateEnemyStrategy::getEnemyCoordinates () const
{
  const auto ALLOWED_DISTANCE = 2;
  auto enemyCoordinates = randomizeEnemyCoordinates ();
  auto enemies = Field::getInstance ()->getEnemies ();

  auto enemyPlaced = false;
  auto allowedCoordinates = true;
  while (true != enemyPlaced) {
    enemyCoordinates = randomizeEnemyCoordinates ();
    allowedCoordinates = true;

    for (auto i = 0; i < enemies.size (); i++) {
      auto enemiesVectorX = abs (enemyCoordinates.first -
                                 enemies[i].getCoordinates().first),
        enemiesVectorY = abs (enemyCoordinates.second -
                              enemies[i].getCoordinates().second);
      const int DISTANCE = static_cast<const int>(
        sqrt (pow (enemiesVectorX, 2) +
              pow (enemiesVectorY, 2)) - 1);
      if (DISTANCE < ALLOWED_DISTANCE) {
        allowedCoordinates = false;
        break;
      }
    }

    if ((*Field::getInstance ())[enemyCoordinates].getContent () == nullptr &&
        allowedCoordinates) {
      enemyPlaced = true;
    }
  }

  return enemyCoordinates;
}


pair<int, int>
CreateEnemyStrategy::randomizeEnemyCoordinates () const
{
  const auto FIELD_SIZE = Field::getInstance ()->getSize ();
  const double upperEnemiesPart = 2.0 / 3.0;
  pair<int, int> enemyCoordinates;

  enemyCoordinates = pair<int, int> (rand () % FIELD_SIZE,
                                     static_cast<int>(rand () % FIELD_SIZE *
                                                      upperEnemiesPart));
  return enemyCoordinates;
}