#ifndef FIELD_H
#define FIELD_H

#include <utility>

#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Field
{
public:
  Field ();
  static Field* get ();

  GameObject& add (const GameObject &gameObject,
                   const pair<int, int> coordinates);
private:
  static Field* instance_;
  GameObject** field_;
  Player player_;
  Enemy* enemies_;

  const int getFieldSize () const;
  const int getEnemiesCount () const;
  Player createPlayer ();
  const pair<int, int>* getEnemiesCoordinates () const;
  pair<int, int>* randomizeEnemiesCoordinates () const;
  Enemy* createEnemies ();
};

#endif // !FIELD_H
