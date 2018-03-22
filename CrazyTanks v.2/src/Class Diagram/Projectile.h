/**
 * Project CrazyTanks
 */


#ifndef _PROJECTILE_H
#define _PROJECTILE_H

#include "MovingObject.h"


class Projectile: public MovingObject {
public: 
    
    /**
     * @param object
     */
    virtual void dealDamage(GameObject& object) = 0;
};

#endif //_PROJECTILE_H