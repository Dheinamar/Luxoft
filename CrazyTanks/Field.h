#ifndef FIELD_H
#define FIELD_H

#include <memory>

#include "GameObject.h"
#include "Player.h"

class Field
{
public:
  Field();
  static Field* get();
  int getFieldSize() const;

  GameObject& add(const GameObject &gameObject, const int x, const int y);
private:
  static Field* instance_;
  GameObject** field_;
  Player player_;

  Player createPlayer();
};

#endif // !FIELD_H
