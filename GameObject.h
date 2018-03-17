#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utility>

using namespace std;

class GameObject
{
public:
  GameObject (pair<int, int> coordinates);
  pair<int, int> getCoordinates () const;
  pair<int, int> setCoordinates (pair<int, int> coordinates);
  ~GameObject ();
protected:
  pair<int, int> coordinates_;
};

#endif // !GAMEOBJECT_H