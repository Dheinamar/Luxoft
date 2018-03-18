#include "Cell.h"

Cell::Cell (pair<int, int> coordinates) :
  coordinates_ (coordinates), content_(nullptr)
{
}



GameObject*
Cell::getContent () const
{
  return content_;
}



GameObject*
Cell::setContent (GameObject& content)
{
  content_ = &content;
  return content_;
}



GameObject&
Cell::add (const GameObject& gameObject)
{
  setContent (const_cast<GameObject&>(gameObject));
  return const_cast<GameObject&> (gameObject);
}

Cell &
Cell::clear ()
{
  content_ = nullptr;
  return *this;
}



pair<int, int>
Cell::getCoordinates () const
{
  return coordinates_;
}



Cell::~Cell ()
{
}
