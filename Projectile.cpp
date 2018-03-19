#include "Projectile.h"
#include "Field.h"

Projectile::Projectile (const pair<int, int> coordinates,
                        const Way direction, const Tank* owner) :
  MovingObject (coordinates, direction), SmallObject (coordinates),
  owner_ (owner)
{
  Field::getInstance ()->addProjectile (this);
}



pair<int, int>
Projectile::setCoordinates (pair<int, int> coordinates)
{
  SmallObject::coordinates_ = coordinates;
  return MovingObject::coordinates_ = coordinates;
}



bool
Projectile::moveForward ()
{
  auto wasMoved = MovingObject::moveForward ();

  if (MovingObject::coordinates_.first < 0 ||
      MovingObject::coordinates_.first >= Field::FIELD_SIZE ||
      MovingObject::coordinates_.second < 0 ||
      MovingObject::coordinates_.second >= Field::FIELD_SIZE) {
    Field::getInstance ()->removeProjectile (this);
    return true;
  }

  if (!wasMoved) {
    pair<int, int> frontCoordinates;
    switch (direction_) {
    case UP:
      frontCoordinates = pair<int, int>
        (MovingObject::coordinates_.first,
         MovingObject::coordinates_.second - 1);
      break;
    case RIGHT:
      frontCoordinates = pair<int, int>
        (MovingObject::coordinates_.first + 1,
         MovingObject::coordinates_.second);
      break;
    case DOWN:
      frontCoordinates = pair<int, int>
        (MovingObject::coordinates_.first,
         MovingObject::coordinates_.second + 1);
      break;
    case LEFT:
      frontCoordinates = pair<int, int>
        (MovingObject::coordinates_.first - 1,
         MovingObject::coordinates_.second);
      break;
    default:
      break;
    }

    auto frontObject = (*Field::getInstance ())[frontCoordinates].
      getContent ();

    if (frontObject != nullptr &&
        frontObject->getTeam () != owner_->MovingObject::getTeam ()) {
      dealDamage (*frontObject);
    }
    return false;
  }

  return true;
}



void
Projectile::dealDamage (GameObject& damagedGameObject)
{
  damagedGameObject.getDamaged (*this);
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
