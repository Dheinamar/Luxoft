/**
 * Project CrazyTanks
 */


#ifndef _DRAWINFO_H
#define _DRAWINFO_H

class DrawInfo {
public: 
    
    virtual void getProjectiles() = 0;
    
    virtual const vector<Tank> getEnemies() const = 0;
    
    virtual const vector<Wall> getWalls() const = 0;
    
    virtual void getGold() = 0;
    
    virtual void getPlayer() = 0;
    
    virtual int getSize() = 0;
};

#endif //_DRAWINFO_H