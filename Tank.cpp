#include "Tank.h"

Tank::~Tank ()
{
}



Tank::Tank (pair<int, int> coordinates, int health) :
  GameObject (coordinates), health_ (health)
{
}
