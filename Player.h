#ifndef PLAYER_H
#define PLAYER_H

#include "Tank.h"
class Player :
  public Tank
{
public:
  Player () : Tank () {};
  static Player* get ();
  ~Player ();
private:
  static Player* instance_;
};

#endif // !PLAYER_H