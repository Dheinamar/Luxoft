#ifndef ITEM_H
#define ITEM_H

template <typename A>
class Item
{
public:
  Item (const A& value, const A*& backward, const A*& forward);
  ~Item ();

  A& getValue () const;
  Item<A>*& getNext () const;
  Item<A>*& getPrevious () const;
  void repointNext (Item<A>* item);
  void repointPrevious (Item<A>* item);
private:
  A value_;
  Item<A>* forward_;
  Item<A>* backward_;
};


#endif // !ITEM_H