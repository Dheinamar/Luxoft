/**
 * Project CrazyTanks
 */


#ifndef _GAMEOBJECT_H
#define _GAMEOBJECT_H

#include <utility>

#include "Way.h"

using namespace std;

class Projectile;
class GameObject {
public: 
    
    virtual pair<int, int> getCoordinates() const = 0;
    
    /**
     * @param coordinates
     */
    virtual pair<int, int> setCoordinates(const pair<int, int> coordinates) = 0;

    virtual Way getWay () const = 0;
    
    /**
     * @param projectile
     */
    virtual void getDamaged(Projectile& projectile) = 0;
    
    virtual GameObject& clone(pair<int, int> coordinates) = 0;

    virtual bool operator==(const GameObject& gamObject) = 0;
};

#endif //_GAMEOBJECT_H