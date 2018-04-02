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

        if (coordinates.first < target.first &&
            coordinates.second < target.second) {
          // Probably should take this out of if.
          auto targetVectorX = abs (coordinates.first - target.first),
            targetVectorY = abs (coordinates.second - target.second);
          const int DISTANCE = static_cast<const int>(
            sqrt (pow (targetVectorX, 2) +
                  pow (targetVectorX, 2)));

          auto axisXVectorX = abs (coordinates.first + DISTANCE - target.first),
            axisXVectorY = abs (coordinates.second - target.second),
            axisYVectorX = abs (coordinates.first - target.first),
            axisYVectorY = abs (coordinates.second + DISTANCE - target.second);
          const int AXIS_X_DISTANCE = static_cast<const int>(
            sqrt (pow (axisXVectorX, 2) +
                  pow (axisXVectorY, 2))),
            AXIS_Y_DISTANCE = static_cast<const int>(
              sqrt (pow (axisYVectorX, 2) +
                    pow (axisYVectorY, 2)));
          if (AXIS_X_DISTANCE < AXIS_Y_DISTANCE) {
            j->execute (Command::MOVE_RIGHT);
          }
          else {
            j->execute (Command::MOVE_DOWN);
          }
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