#include "Enemy.h"

Enemy::Enemy (pair<int, int> coordinates) : Tank(coordinates, Enemy::HEALTH)
{
}



Enemy::~Enemy ()
{
}
