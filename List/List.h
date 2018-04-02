#ifndef LIST_H
#define LIST_H

#include <memory>

using namespace std;

template <typename A>
class List
{
private:
  template <typename A>
  class Item
  {
  public:
    Item ();
    ~Item ();

    A& getValue ();
    shared_ptr<Item<A>> getNext ();
    shared_ptr<Item<A>> getPrevious ();
  private:
    A value_;
    shared_ptr<Item<A>> forward_;
    shared_ptr<Item<A>> backward_;
  };
public:
  List ();
  ~List ();

  Item& getCurrent ();
  const bool moveForward ();
  const bool moveBackward ();
private:
  shared_ptr<Item<A>> begin_;
  shared_ptr<Item<A>> end_;
  shared_ptr<Item<A>> current_;
};


#endif // !LIST_H