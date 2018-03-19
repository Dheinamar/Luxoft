#include "BigObject.h"
#include "Field.h"

BigObject::BigObject (pair<int, int> coordinates) :
  GameObject (coordinates)
{
  (*Field::getInstance ())[coordinates].add (this);
}



BigObject::~BigObject ()
{
  (*Field::getInstance ())[coordinates_].clear ();
}
