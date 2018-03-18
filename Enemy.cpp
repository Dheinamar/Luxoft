#include "Enemy.h"

Enemy::Enemy (pair<int, int> coordinates, Way direction) :
  Tank(coordinates, direction, Enemy::HEALTH)
{
}



Enemy::~Enemy ()
{
}
