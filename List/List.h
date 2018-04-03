#ifndef LIST_H
#define LIST_H

template <typename A>
class List
{
private:
  template <typename A>
  class Item
  {
  public:
    Item (const A& value,
          const Item<A>*& backward,
          const Item<A>*& forward);
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



template<typename A>
template<typename A>
inline List<A>::Item<A>::Item (const A & value,
                               const Item<A>*& backward,
                               const Item<A>*& forward) {}



template <typename A>
List<A>::List () {}


template <typename A>
List<A>::~List () {
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
List<A>::getCurrent () {
  return *current_;
}

template<typename A>
const bool
List<A>::moveForward () {
  if (current_->getNext () != nullptr) {
    current_ = current_->getNext ();
    return true;
  }

  return false;
}

template<typename A>
const bool
List<A>::moveBackward () {
  if (current_->getPrevious () != nullptr) {
    current_ = current_->getPrevious ();
    return true;
  }

  return false;
}

template<typename A>
void
List<A>::pushBack (const A & value) {
  if (current_ == end_) {
    current_->repointNext (new Item<A> (value));
  }
  end_->repointNext (new Item<A> (value));
}

template<typename A>
void
List<A>::pushFront (const A & value) {
  if (current_ == begin_) {
    current_->repointPrevious (new Item<A> (value, ));
  }
  begin_->repointPrevious (new Item<A> (value));
}




#endif // !LIST_H