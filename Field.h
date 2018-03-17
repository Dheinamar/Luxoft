#ifndef FIELD_H
#define FIELD_H

#include <utility>

#include "GameObject.h"
#include "Wall.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

enum Way
{
  UP = 0,
  RIGHT,
  DOWN,
  LEFT
};

class Field
{
public:
  Field ();
  static Field* get ();

  GameObject& add (const GameObject &gameObject,
                   const pair<int, int> coordinates);
private:
  const int N_WAYS = 4;
  const int FIELD_SIZE = 10;
  const int N_WALLS = 6;
  const int WALL_SIZE = 2;
  const int N_ENEMIES = 6;

  static Field* instance_;
  GameObject** field_;
  Wall* walls_;
  Player player_;
  Enemy* enemies_;

  Wall* createWalls ();
  Player createPlayer ();
  const pair<int, int>* getWallsCoordinates () const;
  pair<int, int>* randomizeWallsCoordinates () const;
  const pair<int, int>* getEnemiesCoordinates () const;
  pair<int, int>* randomizeEnemiesCoordinates () const;
  Enemy* createEnemies ();
};

#endif // !FIELD_H
