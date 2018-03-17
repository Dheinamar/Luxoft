#include "Field.h"

Field* Field::instance_ = nullptr;

Field::Field ()
{

  field_ = new GameObject*[FIELD_SIZE];

  for (auto i = 0; i < FIELD_SIZE; i++) {
    field_[i] = new GameObject[FIELD_SIZE];
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



GameObject&
Field::add (const GameObject& gameObject, const pair<int, int> coordinates)
{
  field_[coordinates.first][coordinates.second] = gameObject;
  return const_cast<GameObject&> (gameObject);
}



Wall *
Field::createWalls ()
{
  auto enemyCoordinates = getEnemiesCoordinates ();
  Enemy* enemies = new Enemy[N_WALLS];

  for (auto i = 0; i < N_WALLS; i++) {
    add (dynamic_cast<GameObject&>(enemies_[i]), enemyCoordinates[i]);
  }
  return enemies;
}

Player
Field::createPlayer ()
{
  auto playerCoordinates = pair<int, int> (FIELD_SIZE / 2, FIELD_SIZE - 1);

  while (!field_[playerCoordinates.first][playerCoordinates.second].
         isEmpty ()) {
    --playerCoordinates.second;
  }

  add (dynamic_cast<GameObject&>(*player_.get ()), playerCoordinates);
  return player_;
}



const pair<int, int>*
Field::getWallsCoordinates () const
{
  const auto N_WALL_BLOCKS = N_WALLS * WALL_SIZE;
  pair<int, int>* wallCoordinates;

  auto wallBlocksPlaced = 0, allowedCoordinates = N_WALL_BLOCKS;
  while (N_WALL_BLOCKS != wallBlocksPlaced) {
    wallCoordinates = randomizeWallsCoordinates ();
    wallBlocksPlaced = 0;
    allowedCoordinates = N_WALL_BLOCKS;

    for (auto i = 0; i < N_WALL_BLOCKS; i++) {
      for (auto j = i + 1; j < N_WALL_BLOCKS; j++) {
        if (wallCoordinates[i] == wallCoordinates[j] ||
            (wallCoordinates[i].second + 1 == wallCoordinates[j].second &&
             wallCoordinates[i].first - 1 == wallCoordinates[j].first ||
             wallCoordinates[i].first + 1 == wallCoordinates[j].first)) {
          --allowedCoordinates;
        }
      }

      if (N_WALL_BLOCKS == allowedCoordinates) {
        ++wallBlocksPlaced;
      }
    }
  }

  return wallCoordinates;
}



pair<int, int>*
Field::randomizeWallsCoordinates () const
{
  const auto N_WALL_BLOCKS = N_WALLS * WALL_SIZE;
  pair<int, int>* wallCoordinates = new pair<int, int>[N_WALL_BLOCKS];

  for (auto i = 0; i < N_WALL_BLOCKS; i += WALL_SIZE) {
    wallCoordinates[i + 1].first =
      wallCoordinates[i].first =
      rand () % FIELD_SIZE;
    wallCoordinates[i + 1].second =
      wallCoordinates[i].second =
      rand () % FIELD_SIZE;

    switch (rand () % N_WAYS) {
    case UP:
      --wallCoordinates[i + 1].second;
      break;
    case RIGHT:
      ++wallCoordinates[i + 1].first;
      break;
    case DOWN:
      ++wallCoordinates[i + 1].second;
      break;
    case LEFT:
      --wallCoordinates[i + 1].first;
      break;
    default:
      break;
    }
  }
  return wallCoordinates;
}



const pair<int, int>*
Field::getEnemiesCoordinates () const
{
  const auto ALLOWED_DISTANCE = 2;
  pair<int, int>* enemyCoordinates;

  auto enemiesPlaced = 0, allowedCoordinates = N_ENEMIES;
  while (N_ENEMIES != enemiesPlaced) {
    enemyCoordinates = randomizeEnemiesCoordinates ();
    enemiesPlaced = 0;
    allowedCoordinates = N_ENEMIES;

    for (auto i = 0; i < N_ENEMIES; i++) {
      for (auto j = i + 1; j < N_ENEMIES; j++) {
        auto enemiesVectorX = abs (enemyCoordinates[i].first -
                                   enemyCoordinates[j].first),
          enemiesVectorY = abs (enemyCoordinates[i].second -
                                enemyCoordinates[j].second);
        const int DISTANCE = sqrt (pow (enemiesVectorX, 2) +
                                   pow (enemiesVectorY, 2));

        if (DISTANCE < ALLOWED_DISTANCE) {
          --allowedCoordinates;
        }
      }

      if (field_[enemyCoordinates[i].first][enemyCoordinates[i].second].
          isEmpty () &&
          N_ENEMIES == allowedCoordinates) {
        ++enemiesPlaced;
      }
    }
  }

  return enemyCoordinates;
}



pair<int, int>*
Field::randomizeEnemiesCoordinates () const
{
  const double upperEnemiesPart = 2.0 / 3.0;
  auto enemyCoordinates = new pair<int, int>[N_ENEMIES];

  for (auto i = 0; i < N_ENEMIES; i++) {
    enemyCoordinates[i].first = rand () % FIELD_SIZE;
    enemyCoordinates[i].second = rand () % FIELD_SIZE * upperEnemiesPart;
  }
  return enemyCoordinates;
}



Enemy*
Field::createEnemies ()
{
  auto enemyCoordinates = getEnemiesCoordinates ();
  Enemy* enemies = new Enemy[N_ENEMIES];

  for (auto i = 0; i < N_ENEMIES; i++) {
    add (dynamic_cast<GameObject&>(enemies_[i]), enemyCoordinates[i]);
  }
  return enemies;
}
