#include "Player.h"

Player* Player::instance_ = nullptr;


Player::Player()
{
}



Player*
Player::get() {
  if (!instance_)
    instance_ = new Player();

  return instance_;
}


Player::~Player()
{
}
