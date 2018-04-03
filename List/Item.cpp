#include "Item.h"


template<typename A>
Item<A>::Item (const A & value, const A*& backward, const A*& forward)
{}

template<typename A>
Item::~Item ()
{}


template<typename A>
Item<A>*&
Item<A>::getNext () const
{
  return;
}
