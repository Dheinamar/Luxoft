#include "Field.h"

Field* Field::instance_ = nullptr;

Field::Field ()
{
  auto fieldSize = getFieldSize ();

  field_ = new GameObject*[fieldSize];

  for (auto i = 0; i < fieldSize; i++) {
    field_[i] = new GameObject[fieldSize];
  }

  player_ = createPlayer ();
  enemies_ = createEnemies ();
}



Field*
Field::get ()
{
  if (!instance_)
    instance_ = new Field ();

  return instance_;
}



const int
Field::getFieldSize () const
{
  return 10;
}

const int
Field::getEnemiesCount () const
{
  return 6;
}



GameObject&
Field::add (const GameObject& gameObject, const pair<int, int> coordinates)
{
  field_[coordinates.first][coordinates.second] = gameObject;
  return const_cast<GameObject&> (gameObject);
}



Player
Field::createPlayer ()
{
  auto fieldSize = getFieldSize ();
  auto playerCoordinates = pair<int, int> (fieldSize - 1, fieldSize / 2);

  add (dynamic_cast<GameObject&>(*player_.get ()), playerCoordinates);
  return player_;
}



const pair<int, int>*
Field::getEnemiesCoordinates () const
{
  const auto nEnemies = getEnemiesCount ();
  pair<int, int>* enemyCoordinates;

  auto enemiesPlaced = 0;
  while (nEnemies != enemiesPlaced) {
    enemyCoordinates = randomizeEnemiesCoordinates ();
    enemiesPlaced = 0;

    for (auto i = 0; i < nEnemies; i++) {
      for (auto j = i + 1; j < nEnemies; j++) {
        if (field_[i][j].isEmpty()) {
          ++enemiesPlaced;
        }
      }
    }
  }

  return enemyCoordinates;
}



pair<int, int>*
Field::randomizeEnemiesCoordinates () const
{
  auto nEnemies = getEnemiesCount ();
  const double upperEnemiesPart = 2.0 / 3.0;
  auto enemyCoordinates = new pair<int, int>[nEnemies];

  for (auto i = 0; i < nEnemies; i++) {
    enemyCoordinates[i].first = rand () % getFieldSize ();
    enemyCoordinates[i].second = rand () % getFieldSize () * upperEnemiesPart;
  }
  return enemyCoordinates;
}



Enemy*
Field::createEnemies ()
{
  auto nEnemies = getEnemiesCount ();
  auto enemyCoordinates = getEnemiesCoordinates ();
  enemies_ = new Enemy[nEnemies];

  for (auto i = 0; i < nEnemies; i++) {
    add (dynamic_cast<GameObject&>(enemies_[i]), enemyCoordinates[i]);
  }
  return enemies_;
}
