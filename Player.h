#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"
class Player :
  public Tank
{
public:
  Player (pair<int, int> coordinates);
  static Player* get (pair<int, int> coordinates);
  ~Player ();
private:
  static const int HEALTH = 3;
  static Player* instance_;
};

#endif // !PLAYER_H