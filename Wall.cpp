#include "Wall.h"

Wall::Wall (pair<int, int> coordinates) : GameObject(coordinates)
{
}



void
Wall::getDamaged (Projectile projectile)
{
  GameObject::getDamaged(projectile);
}



Wall::~Wall ()
{
}
