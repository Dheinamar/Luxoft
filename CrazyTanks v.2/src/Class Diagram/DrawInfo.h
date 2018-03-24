/**
 * Project CrazyTanks
 */


#ifndef _DRAWINFO_H
#define _DRAWINFO_H

#include <vector>
#include "Tank.h"
#include "Wall.h"
#include "Gold.h"

class DrawInfo {
public: 
    
    virtual const vector<Projectile> getProjectiles() const = 0;
    
    virtual const vector<Tank> getEnemies() const = 0;
    
    virtual const vector<Wall> getWalls() const = 0;
    
    virtual const Gold getGold() const = 0;
    
    virtual Tank getPlayer() = 0;
    
    virtual int getSize() = 0;
};

#endif //_DRAWINFO_H