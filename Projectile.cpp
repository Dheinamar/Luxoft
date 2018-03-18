#include "Projectile.h"
#include "Field.h"



Projectile::Projectile (pair<int, int> coordinates, Way direction) :
  MovingObject (coordinates, direction)
{
}

bool Projectile::moveForward ()
{
  if (!MovingObject::moveForward ()) {
    pair<int, int> frontCoordinates;
    switch (direction_) {
    case UP:
      frontCoordinates = pair<int, int> (coordinates_.first,
                                         coordinates_.second - 1);
      break;
    case RIGHT:
      frontCoordinates = pair<int, int> (coordinates_.first + 1,
                                         coordinates_.second);
      break;
    case DOWN:
      frontCoordinates = pair<int, int> (coordinates_.first,
                                         coordinates_.second + 1);
      break;
    case LEFT:
      frontCoordinates = pair<int, int> (coordinates_.first - 1,
                                         coordinates_.second);
      break;
    default:
      break;
    }

    auto frontObject = (*Field::getInstance ())[frontCoordinates].
      getContent ();

    if (frontObject != nullptr) {
      frontObject->getDamaged (*this);
    }
    return false;
  }
  return true;
}



void
Projectile::getDamaged (Projectile projectile)
{
  GameObject::getDamaged (projectile);
  this->~Projectile ();
}



Projectile::~Projectile ()
{
}
