/**
 * Project CrazyTanks
 */


#include "ConcreteTankCommand.h"

 /**
  * ConcreteTankCommand implementation
  */

ConcreteTankCommand::ConcreteTankCommand (const Tank& receiver)
{
  receiver_.reset (&const_cast<Tank&>(receiver));
}

void
ConcreteTankCommand::execute (Command command) const
{
  switch (command) {
  case SHOOT:
    receiver_->shoot ();
    break;
  case MOVE_DOWN:
    receiver_->moveDown ();
    break;
  case MOVE_LEFT:
    receiver_->moveLeft ();
    break;
  case MOVE_RIGHT:
    receiver_->moveRight ();
    break;
  case MOVE_UP:
    receiver_->moveUp ();
    break;
  }
}

const Tank &
ConcreteTankCommand::getReceiver () const
{
  return *receiver_;
}
