#ifndef GAME_H
#define GAME_H

#include "Field.h"

class Game
{
public:
  Game();
  static Game* get();
  ~Game();
private:
  static Game* instance_;
  Field field_;
};

#endif // !GAME_H
