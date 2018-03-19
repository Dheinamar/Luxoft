#include "Wall.h"

Wall::Wall (pair<int, int> coordinates) : BigObject(coordinates)
{
}



void
Wall::getDamaged (Projectile projectile)
{
  BigObject::getDamaged(projectile);
}



Wall::~Wall ()
{
}
