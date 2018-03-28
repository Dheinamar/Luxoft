/**
 * Project CrazyTanks
 */


#include "Game.h"

 /**
  * Game implementation
  */


void
Game::controlPlayer ()
{
  auto key = _getch ();
  switch (key) {
  case ARROW_DOWN:
    playerCommand_.execute (Command::MOVE_DOWN);
    break;
  case ARROW_LEFT:
    playerCommand_.execute (Command::MOVE_LEFT);
    break;
  case ARROW_RIGHT:
    playerCommand_.execute (Command::MOVE_RIGHT);
    break;
  case ARROW_UP:
    playerCommand_.execute (Command::MOVE_UP);
    break;
  case SPACE:
    playerCommand_.execute (Command::SHOOT);
    break;
  default:
    break;
  }
}

void
Game::controlAi ()
{
  auto target = chooseAiTarget ();
  auto enemies = getField ().getEnemies ();
  for (auto i = enemies.begin (); i < enemies.end (); i++) {
    for (auto j = enemyCommands_.begin (); j != enemyCommands_.end (); j++) {
      if (const_cast<Tank&>(j->getReceiver ()) == *i) {
        auto coordinates = i->getCoordinates ();
        bool hasTargetInSight = false;
        switch (i->getWay ()) {
        case UP:
          // Fallthrough.
        case DOWN:
          for (auto k = 0; k < getField ().getSize (); k++) {
            if (k != coordinates.second &&
                getField ()[pair<int, int> (coordinates.first,
                                            k)].getContent != nullptr) {
              hasTargetInSight = true;
              break;
            }
          }
          break;
        case LEFT:
          // Fallthrough.
        case RIGHT:
          for (auto k = 0; k < getField ().getSize (); k++) {
            if (k != coordinates.first &&
                getField ()[pair<int, int> (k, coordinates.second)].getContent !=
                nullptr) {
              hasTargetInSight = true;
              break;
            }
          }
          break;
        default:
          break;
        }
        if (hasTargetInSight) {
          j->execute (Command::SHOOT);
          break;
        }
      }
    }
  }
}

Field&
Game::getField () const
{
  return *field_.getInstance ();
}

unique_ptr<Game>&
Game::getInstance ()
{

}

/**
 * @param playerWon
 */
void
Game::endGame (bool playerWon)
{

}

void
Game::play ()
{}

pair<int, int>
Game::chooseAiTarget ()
{

}