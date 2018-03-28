/**
 * Project CrazyTanks
 */


#ifndef _GAME_H
#define _GAME_H

#include <memory>
#include <conio.h>

#include "Field.h"
#include "Command.h"
#include "ConcreteTankCommand.h"

using namespace std;

class Game
{
public:

  void controlPlayer ();

  void controlAi ();

  Field& getField () const;

  static unique_ptr<Game>& getInstance ();

  /**
   * @param playerWon
   */
  void endGame (const bool playerWon);

  void play ();
private:
  static const int ARROW_UP = 72;
  static const int ARROW_LEFT = 75;
  static const int ARROW_RIGHT = 77;
  static const int ARROW_DOWN = 80;
  static const int SPACE = 32;
  Field field_;
  static unique_ptr<Game> instance_;
  ConcreteTankCommand playerCommand_;
  vector<ConcreteTankCommand> enemyCommands_;

  pair<int, int> chooseAiTarget ();
};

#endif //_GAME_H