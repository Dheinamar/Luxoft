/**
 * Project CrazyTanks
 */


#ifndef _TANK_H
#define _TANK_H

#include "MovingObject.h"


class Tank: public MovingObject {
public: 
    
    void shoot();
    
    void moveUp();
    
    void moveLeft();
    
    void moveDown();
    
    void moveRight();
protected: 
    int health_;
    static const int TEAM = 0;
    pair<int, int> coordinates_;
private: 
    static const int MAX_HEALTH;
    
    void turnUp();
    
    void turnLeft();
    
    void turnDown();
    
    void turnRight();
};

#endif //_TANK_H