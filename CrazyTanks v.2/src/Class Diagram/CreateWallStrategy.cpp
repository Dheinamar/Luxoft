/**
 * Project CrazyTanks
 */


#include "CreateWallStrategy.h"

 /**
  * CreateWallStrategy implementation
  */

vector<GameObject>
CreateWallStrategy::CreateObject (const GameObject& prototype)
{
  auto coordinates = getWallCoordinates ();
  vector<GameObject> created;

  for (auto i = 0; i < coordinates.size(); i++) {
    created.push_back(const_cast<GameObject&>(prototype).clone (coordinates[i]));
  }

  return created;
}

vector<pair<int, int>>
CreateWallStrategy::getWallCoordinates () const
{
  const auto WALL_SIZE = Field::getInstance ()->getWallSize ();
  auto wallCoordinates = randomizeWallCoordinates (WALL_SIZE);
  auto walls = Field::getInstance ()->getWalls ();

  auto wallBlocksPlaced = 0, allowedCoordinates = WALL_SIZE;
  while (WALL_SIZE != wallBlocksPlaced) {
    wallCoordinates = randomizeWallCoordinates (WALL_SIZE);
    wallBlocksPlaced = 0;
    allowedCoordinates = WALL_SIZE;

    for (auto i = 0; i < WALL_SIZE; i++) {
      for (auto j = 0; j < walls.size (); j++) {
        // Disabling diagonal blocks.
        if (wallCoordinates[i] == walls[j].getCoordinates () ||
          (wallCoordinates[i].first - 1 == walls[j].getCoordinates ().first ||
           wallCoordinates[i].first + 1 == walls[j].getCoordinates ().first &&
           wallCoordinates[i].second + 1 == walls[j].getCoordinates ().second ||
           wallCoordinates[i].second - 1 == walls[j].getCoordinates ().second)) {
          --allowedCoordinates;
          break;
        }
      }

      if ((*Field::getInstance ())[wallCoordinates[i]].getContent () == nullptr &&
          WALL_SIZE == allowedCoordinates) {
        ++wallBlocksPlaced;
      }
      else {
        break;
      }
    }
  }

  return wallCoordinates;
}

vector<pair<int, int>>
CreateWallStrategy::randomizeWallCoordinates (int wallSize) const
{
  const auto FIELD_SIZE = Field::getInstance ()->getSize ();
  vector<pair<int, int>> wallCoordinates;

  wallCoordinates.push_back (pair<int, int> (rand () % FIELD_SIZE,
                                             rand () % FIELD_SIZE));
  for (auto i = 1; i < wallSize; i++) {
    wallCoordinates.push_back (wallCoordinates[0]);
  }
  bool isPossible[] = { true, true, true, true };

  if (wallCoordinates[0].first - wallSize < 0) {
    isPossible[LEFT] = false;
  }
  if (wallCoordinates[0].second - wallSize < 0) {
    isPossible[UP] = false;
  }
  if (wallCoordinates[0].first + wallSize >= FIELD_SIZE) {
    isPossible[RIGHT] = false;
  }
  if (wallCoordinates[0].second + wallSize >= FIELD_SIZE) {
    isPossible[DOWN] = false;
  }

  auto way = rand () % N_WAYS;
  while (!isPossible[way]) {
    way = rand () % N_WAYS;
  }

  switch (way) {
  case UP:
    for (auto i = 1; i < wallSize; i++) {
      --wallCoordinates[i].second;
    }
    break;
  case RIGHT:
    for (auto i = 1; i < wallSize; i++) {
      ++wallCoordinates[i].first;
    }
    break;
  case DOWN:
    for (auto i = 1; i < wallSize; i++) {
      ++wallCoordinates[i].second;
    }
    break;
  case LEFT:
    for (auto i = 1; i < wallSize; i++) {
      --wallCoordinates[i].first;
    }
    break;
  default:
    break;
  }
  return wallCoordinates;
}