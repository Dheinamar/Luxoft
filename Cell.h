#ifndef CELL_H
#define CELL_H

#include "GameObject.h"

class Cell
{
public:
  Cell (pair<int, int> coordinates);

  GameObject* getContent () const;
  GameObject* setContent (const GameObject* content);
  pair<int, int> getCoordinates () const;

  GameObject* add (const GameObject* gameObject);
  Cell& clear ();

  ~Cell ();
private:
  GameObject * content_;
  pair<int, int> coordinates_;
};

#endif // !CELL_H

