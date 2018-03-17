#include "Game.h"

Game* Game::instance_ = nullptr;

Game::Game ()
{
  field_ = Field::getInstance ();
}



Game*
Game::get ()
{
  if (!instance_)
    instance_ = new Game ();

  return instance_;
}



Field
Game::getField () const
{
  return *field_;
}



Game::~Game ()
{
}