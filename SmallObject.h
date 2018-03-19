#ifndef SMALLOBJECT_H
#define SMALLOBJECT_H

#include "GameObject.h"

class SmallObject : public GameObject
{
public:
  SmallObject (const pair<int, int> coordinates);
  ~SmallObject ();
};

#endif // !SMALLOBJECT_H