#include "List.h"


template <typename A>
List<A>::List ()
{}


template <typename A>
List<A>::~List ()
{
  current_ = begin_;
  
  while (current_->List<A>::Item<A>::getNext () != nullptr) {

  }
}