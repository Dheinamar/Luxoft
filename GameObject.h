#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utility>

using namespace std;

class Projectile;
class GameObject
{
public:
  GameObject (pair<int, int> coordinates);
  pair<int, int> getCoordinates () const;
  pair<int, int> setCoordinates (pair<int, int> coordinates);
  const int getTeam () const;
  ~GameObject ();

  void getDamaged (Projectile projectile);
protected:
  static const int NO_TEAM = -1;

  int team_;
  pair<int, int> coordinates_;
};

#endif // !GAMEOBJECT_H