#ifndef BIGOBJECT_H
#define BIGOBJECT_H

#include "GameObject.h"

class BigObject : public GameObject
{
public:
  BigObject (pair<int, int> coordinates);
  ~BigObject ();
};

#endif // !BIGOBJECT_H