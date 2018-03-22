/**
 * Project CrazyTanks
 */


#ifndef _GOLD_H
#define _GOLD_H

#include "GameObject.h"


class Gold: public GameObject {
public: 
    
    static unique_ptr<Gold> getInstance();
private: 
    static unique_ptr<Gold> instance;
};

#endif //_GOLD_H