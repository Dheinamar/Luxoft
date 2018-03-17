#include "Player.h"

Player* Player::instance_ = nullptr;

Player::Player (pair<int, int> coordinates) : Tank(coordinates, Player::HEALTH)
{
}



Player*
Player::get (pair<int, int> coordinates)
{
  if (!instance_)
    instance_ = new Player (coordinates);

  return instance_;
}



Player::~Player ()
{
}
