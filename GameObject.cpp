#include "GameObject.h"
#include "Field.h"

GameObject::GameObject (pair<int, int> coordinates) :
  coordinates_ (coordinates), team_ (NO_TEAM)
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



const int
GameObject::getTeam () const
{
  return team_;
}



GameObject::~GameObject ()
{
}



void
GameObject::getDamaged (Projectile projectile)
{
  projectile.~Projectile ();
}
