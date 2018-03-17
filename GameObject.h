#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
  GameObject () : isEmpty_ (false) {};
  GameObject (bool isEmpty) : isEmpty_ (isEmpty) {};
  const bool isEmpty () const;
  ~GameObject ();
protected:
  bool isEmpty_;
};

#endif // !GAMEOBJECT_H