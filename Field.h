#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"
#include "Wall.h"
#include "Player.h"
#include "Enemy.h"

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
  static const int FIELD_SIZE = 10;

  Field ();
  static Field* getInstance ();
  Cell& operator[](pair<int, int> indices) const;

  Cell** get () const;
private:
  static const int N_WAYS = 4;
  static const int N_WALLS = 6;
  static const int WALL_SIZE = 2;
  static const int N_ENEMIES = 6;

  static Field* instance_;
  Cell** field_;
  Wall* walls_;
  Player* player_;
  Enemy* enemies_;

  Wall* createWalls ();
  Player* createPlayer ();
  pair<int, int>* getWallsCoordinates () const;
  pair<int, int>* randomizeWallsCoordinates () const;
  pair<int, int>* getEnemiesCoordinates () const;
  pair<int, int>* randomizeEnemiesCoordinates () const;
  Enemy* createEnemies ();
};

#endif // !FIELD_H
