#ifndef LIST_H
#define LIST_H

#include "Item.h"

template <typename A>
class List
{
public:
  List ();
  ~List ();

  Item<A>& getCurrent ();
  const bool moveForward ();
  const bool moveBackward ();
  void pushBack (const A& value);
  void pushFront (const A& value);
private:
  Item<A>* begin_;
  Item<A>* end_;
  Item<A>* current_;
};


#endif // !LIST_H