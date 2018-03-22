/**
 * Project CrazyTanks
 */


#ifndef _GAME_H
#define _GAME_H

#include <memory>

#include "Field.h"

using namespace std;

class Game {
public: 
    
    void controlPlayer();
    
    void controlAi();
    
    Field getField() const;
    
    static unique_ptr<Game> getInstance();
    
    /**
     * @param playerWon
     */
    void endGame(const bool playerWon);
private: 
    Field field_;
    static unique_ptr<Game> instance_;
    
    void chooseAiTarget();
};

#endif //_GAME_H