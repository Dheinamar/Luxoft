#include "Player.h"

Player* Player::instance_ = nullptr;

Player::Player (pair<int, int> coordinates, Way direction) :
  Tank(coordinates, direction, Player::HEALTH, Player::TEAM)
{
}



Player*
Player::get (pair<int, int> coordinates, Way direction)
{
  if (!instance_)
    instance_ = new Player (coordinates, direction);

  return instance_;
}



Player::~Player ()
{
}
