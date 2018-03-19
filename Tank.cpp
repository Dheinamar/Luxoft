#include "Tank.h"
#include "Field.h"

pair<int, int>
Tank::setCoordinates (pair<int, int> coordinates)
{
  BigObject::coordinates_ = coordinates;
  return MovingObject::coordinates_ = coordinates;
}



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



void
Tank::shoot () const
{
  auto shot = new Projectile (BigObject::coordinates_, direction_, this);
  shot->moveForward ();
}



void
Tank::getDamaged (Projectile projectile)
{
  BigObject::getDamaged (projectile);
  --health_;
  if (0 == health_) {
    this->~Tank ();
  }
}



bool
Tank::moveForward ()
{
  (*Field::getInstance ())[MovingObject::coordinates_].clear ();
  auto wasMoved = MovingObject::moveForward ();
  (*Field::getInstance ())[MovingObject::coordinates_].
    add (static_cast<BigObject*>(this));
  return wasMoved;
}



Tank::~Tank ()
{
}



Tank::Tank (pair<int, int> coordinates, Way direction, int health, int team) :
  MovingObject (coordinates, direction), BigObject (coordinates),
  health_ (health), team_ (team)
{
}
