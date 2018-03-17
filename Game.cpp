#include "Game.h"

Game* Game::instance_ = nullptr;

Game::Game()
{
}



Game*
Game::get() {
  if (!instance_)
    instance_ = new Game();

  return instance_;
}



Game::~Game()
{
}



Player*
Game::createPlayer() {
  auto fieldSize = field_.getFieldSize();
  field_.add(player_, fieldSize - 1, fieldSize / 2);
  return &player_;
}