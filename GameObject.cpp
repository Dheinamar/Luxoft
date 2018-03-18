#include "GameObject.h"
#include "Field.h"

GameObject::GameObject (pair<int, int> coordinates) :
  coordinates_ (coordinates)
{
}



pair<int, int>
GameObject::getCoordinates () const
{
  return coordinates_;
}



pair<int, int>
GameObject::setCoordinates (pair<int, int> coordinates)
{
  return coordinates_ = coordinates;
}



void GameObject::getDamaged (Projectile projectile)
{
  projectile.~Projectile ();
}



GameObject::~GameObject ()
{
  (*Field::getInstance ())[coordinates_].clear ();
}
