#include "List.h"


template <typename A>
List<A>::List () : current_ (nullptr), begin_ (nullptr), end_ (nullptr)
{}


template <typename A>
List<A>::~List ()
{
  current_ = begin_;

  while (current_->getNext () != nullptr) {
    moveForward ();
    delete current_->getPrevious ();
  }
  delete current_;
  delete begin_;
  delete end_;
}

template<typename A>
Item<A> &
List<A>::getCurrent ()
{
  return *current_;
}

template<typename A>
const bool
List<A>::moveForward ()
{
  if (current_->getNext () != nullptr) {
    current_ = current_->getNext ();
    return true;
  }

  return false;
}

template<typename A>
const bool
List<A>::moveBackward ()
{
  if (current_->getPrevious () != nullptr) {
    current_ = current_->getPrevious ();
    return true;
  }

  return false;
}

template<typename A>
void
List<A>::pushBack (const A & value)
{
  if (current_ == end_) {
    current_->repointNext (new Item<A> (value));
  }
  end_->repointNext (new Item<A> (value));
}

template<typename A>
void
List<A>::pushFront (const A & value)
{
  if (current_ == begin_) {
    current_->repointPrevious (new Item<A>(value, ));
  }
  begin_->repointPrevious (new Item<A> (value));
}
