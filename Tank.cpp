#include "Tank.h"
#include "Field.h"

bool
Tank::moveUp ()
{
  direction_ = UP;
  return moveForward ();
}



bool
Tank::moveRight ()
{
  direction_ = RIGHT;
  return moveForward ();
}



bool
Tank::moveDown ()
{
  direction_ = DOWN;
  return moveForward ();
}



bool
Tank::moveLeft ()
{
  direction_ = LEFT;
  return moveForward ();
}



void Tank::Shoot () const
{
  pair<int, int> projectileCoordinates = coordinates_;
  switch (direction_) {
  case UP:
    --projectileCoordinates.second;
    break;
  case RIGHT:
    ++projectileCoordinates.first;
    break;
  case DOWN:
    ++projectileCoordinates.second;
    break;
  case LEFT:
    --projectileCoordinates.first;
    break;
  default:
    break;
  }

  auto projectile = Projectile (projectileCoordinates, direction_);
  Field::getInstance ()->addProjectile (projectile);
}



void
Tank::getDamaged (Projectile projectile)
{
  GameObject::getDamaged (projectile);
  --health_;
  if (0 == health_) {
    this->~Tank ();
  }
}



Tank::~Tank ()
{
}



Tank::Tank (pair<int, int> coordinates, Way direction, int health) :
  MovingObject (coordinates, direction), health_ (health)
{
}
