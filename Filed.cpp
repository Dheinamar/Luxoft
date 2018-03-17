#include "Field.h"

Field* Field::instance_ = nullptr;

Field::Field() {
  auto fieldSize = getFieldSize();

  field_ = new GameObject*[fieldSize];

  for (int i = 0; i < fieldSize; i++)
  {
    field_[i] = new GameObject[fieldSize];
  }
}



Field*
Field::get() {
  if (!instance_)
    instance_ = new Field();

  return instance_;
}



int
Field::getFieldSize() const {
  return 10;
}



GameObject&
Field::add(const GameObject& gameObject, const int x, const int y) {
  field_[x][y] = gameObject;
  return const_cast<GameObject&> (gameObject);
}