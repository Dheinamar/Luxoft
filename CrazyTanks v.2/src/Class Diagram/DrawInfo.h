/**
 * Project CrazyTanks
 */


#ifndef _DRAWINFO_H
#define _DRAWINFO_H

class DrawInfo {
public: 
    
    virtual void getProjectiles() = 0;
    
    virtual void getEnemies() = 0;
    
    virtual void getWalls() = 0;
    
    virtual void getGold() = 0;
    
    virtual void getPlayer() = 0;
    
    virtual void getSize() = 0;
};

#endif //_DRAWINFO_H