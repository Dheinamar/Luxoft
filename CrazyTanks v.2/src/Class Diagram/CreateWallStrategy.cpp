/**
 * Project CrazyTanks
 */


#include "CreateWallStrategy.h"

/**
 * CreateWallStrategy implementation
 */

vector<GameObject>
CreateWallStrategy::CreateObject (const GameObject& prototype, const int count)
{
  auto coordinates = getEnemiesCoordinates (count);
  vector<GameObject> created;

  for (auto i = 0; i < count; i++) {
    created.push_back (const_cast<GameObject&>(prototype).clone (coordinates[i]));
  }

  return created;
}

vector<pair<int, int>>
CreateWallStrategy::getWallsCoordinates () const
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