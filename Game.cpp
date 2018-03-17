#include "Game.h"

Game* Game::instance_ = nullptr;

Game::Game ()
{
  field_.get ();
}



Game*
Game::get ()
{
  if (!instance_)
    instance_ = new Game ();

  return instance_;
}



Game::~Game ()
{
}