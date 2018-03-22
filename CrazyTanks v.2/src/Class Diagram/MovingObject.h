/**
 * Project CrazyTanks
 */


#ifndef _MOVINGOBJECT_H
#define _MOVINGOBJECT_H

#include "GameObject.h"


class MovingObject: public GameObject {
public: 
    
    virtual void moveForward() = 0;
};

#endif //_MOVINGOBJECT_H