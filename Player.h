#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"
class Player :
  public Tank
{
public:
  Player (pair<int, int> coordinates, Way direction);
  static Player* get (pair<int, int> coordinates, Way direction);
  ~Player ();
private:
  static const int TEAM = 1;
  static const int HEALTH = 3;
  static Player* instance_;
};

#endif // !PLAYER_H