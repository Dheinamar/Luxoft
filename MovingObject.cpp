#include "MovingObject.h"
#include "Field.h"

MovingObject::MovingObject (pair<int, int> coordinates, Way direction) :
  GameObject (coordinates), direction_ (direction)
{
}



bool MovingObject::moveForward ()
{
  pair<int, int> newCoordinates;
  switch (direction_) {
  case UP:
    newCoordinates = pair<int, int> (coordinates_.first,
                                     coordinates_.second - 1);
    if ((*Field::getInstance ())[newCoordinates].getContent () == nullptr ||
        newCoordinates.second < 0) {
      setCoordinates (newCoordinates);
      return true;
    }
    break;
  case RIGHT:
    newCoordinates = pair<int, int> (coordinates_.first + 1,
                                     coordinates_.second);
    if ((*Field::getInstance ())[newCoordinates].getContent () == nullptr ||
        newCoordinates.first >=Field::FIELD_SIZE) {
      setCoordinates (newCoordinates);
      return true;
    }
    break;
  case DOWN:
    newCoordinates = pair<int, int> (coordinates_.first,
                                     coordinates_.second + 1);
    if ((*Field::getInstance ())[newCoordinates].getContent () == nullptr ||
        newCoordinates.second >= Field::FIELD_SIZE) {
      setCoordinates (newCoordinates);
      return true;
    }
    break;
  case LEFT:
    newCoordinates = pair<int, int> (coordinates_.first - 1,
                                     coordinates_.second);
    if ((*Field::getInstance ())[newCoordinates].getContent () == nullptr ||
        newCoordinates.first < 0) {
      setCoordinates (newCoordinates);
      return true;
    }
    break;
  default:
    break;
  }
  return false;
}



MovingObject::~MovingObject ()
{
}