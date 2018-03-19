#include "Field.h"

Field* Field::instance_ = nullptr;

Field::Field ()
{

  field_ = new Cell*[FIELD_SIZE] ();

  for (auto i = 0; i < FIELD_SIZE; i++) {
    field_[i] = static_cast<Cell*>(operator new(sizeof (Cell) * FIELD_SIZE));

    for (auto j = 0; j < FIELD_SIZE; j++) {
      field_[i][j] = Cell (pair<int, int> (i, j));
    }
  }
}



Field*
Field::getInstance ()
{
  if (!instance_) {
    instance_ = new Field ();

    instance_->walls_ = instance_->createWalls ();
    instance_->player_ = instance_->createPlayer ();
    instance_->enemies_ = instance_->createEnemies ();
  }

  return instance_;
}



Cell&
Field::operator[](pair<int, int> indices) const
{
  return field_[indices.first][indices.second];
}



Cell **
Field::get () const
{
  return field_;
}



void
Field::addProjectile (const Projectile* projectile)
{
  projectiles_.push_back (const_cast<Projectile*>(projectile));
}

void Field::removeProjectile (Projectile*  projectile)
{
  for (auto i = projectiles_.begin(); i != projectiles_.end(); i++) {
    if (*i == projectile) {
      i = projectiles_.erase (i);
    }
  }
}



Player &
Field::getPlayer () const
{
  return *player_;
}



Wall *
Field::createWalls ()
{
  const auto N_WALL_BLOCKS = N_WALLS * WALL_SIZE;
  auto wallCoordinates = getWallsCoordinates ();
  Wall* walls = static_cast<Wall*>(operator new(sizeof (Wall) *
                                                N_WALL_BLOCKS));
  for (int i = 0; i < N_WALL_BLOCKS; i++) {
    walls[i] = *new Wall (wallCoordinates[i]);
  }
  return walls;
}



Player*
Field::createPlayer ()
{
  auto playerCoordinates = pair<int, int> (FIELD_SIZE / 2, FIELD_SIZE - 1);

  while ((*this)[playerCoordinates].getContent () != nullptr) {
    --playerCoordinates.second;
  }

  player_ = Player::get (playerCoordinates, UP);
  return player_;
}



pair<int, int>*
Field::getWallsCoordinates () const
{
  const auto N_WALL_BLOCKS = N_WALLS * WALL_SIZE;
  auto wallCoordinates = randomizeWallsCoordinates ();

  auto wallBlocksPlaced = 0, allowedCoordinates = N_WALL_BLOCKS;
  while (N_WALL_BLOCKS != wallBlocksPlaced) {
    wallCoordinates = randomizeWallsCoordinates ();
    wallBlocksPlaced = 0;
    allowedCoordinates = N_WALL_BLOCKS;

    for (auto i = 0; i < N_WALL_BLOCKS; i++) {
      for (auto j = i + 1; j < N_WALL_BLOCKS; j++) {
        // Disabling diagonal blocks.
        if (wallCoordinates[i] == wallCoordinates[j] ||
          (wallCoordinates[i].first - 1 == wallCoordinates[j].first ||
           wallCoordinates[i].first + 1 == wallCoordinates[j].first &&
           wallCoordinates[i].second + 1 == wallCoordinates[j].second ||
           wallCoordinates[i].second - 1 == wallCoordinates[j].second)) {
          --allowedCoordinates;
          break;
        }
      }

      if (N_WALL_BLOCKS == allowedCoordinates) {
        ++wallBlocksPlaced;
      }
      else {
        break;
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
    wallCoordinates[i + 1].first = wallCoordinates[i].first =
      rand () % FIELD_SIZE;
    wallCoordinates[i + 1].second = wallCoordinates[i].second =
      rand () % FIELD_SIZE;
    bool isPossible[] = { true, true, true, true };

    for (auto j = 0; j < N_WAYS; j++) {
      if (wallCoordinates[i].first - 1 < 0) {
        isPossible[LEFT] = false;
      }
      if (wallCoordinates[i].second - 1 < 0) {
        isPossible[UP] = false;
      }
      if (wallCoordinates[i].first + 1 >= FIELD_SIZE) {
        isPossible[RIGHT] = false;
      }
      if (wallCoordinates[i].second + 1 >= FIELD_SIZE) {
        isPossible[DOWN] = false;
      }
    }

    auto way = rand () % N_WAYS;
    while (!isPossible[way]) {
      way = rand () % N_WAYS;
    }

    switch (way) {
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



pair<int, int>*
Field::getEnemiesCoordinates () const
{
  const auto ALLOWED_DISTANCE = 2;
  auto enemyCoordinates = randomizeEnemiesCoordinates ();

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
        const int DISTANCE = static_cast<const int>(
          sqrt (pow (enemiesVectorX, 2) +
                pow (enemiesVectorY, 2)) - 1);
        if (DISTANCE < ALLOWED_DISTANCE) {
          --allowedCoordinates;
          break;
        }
      }

      if ((*this)[enemyCoordinates[i]].getContent () == nullptr &&
          N_ENEMIES == allowedCoordinates) {
        ++enemiesPlaced;
      }
      else {
        break;
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
    enemyCoordinates[i].second = static_cast<int>(rand () % FIELD_SIZE *
                                                  upperEnemiesPart);
  }
  return enemyCoordinates;
}



Enemy*
Field::createEnemies ()
{
  auto enemyCoordinates = getEnemiesCoordinates ();
  Enemy* enemies = static_cast<Enemy*>(operator new(sizeof (Enemy) *
                                                    N_ENEMIES));
  for (int i = 0; i < N_ENEMIES; i++) {
    enemies[i] = *new Enemy (enemyCoordinates[i],
                        static_cast<Way>(rand () % N_WAYS));
  }
  return enemies;
}
