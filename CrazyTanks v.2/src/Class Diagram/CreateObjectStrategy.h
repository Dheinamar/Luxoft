/**
 * Project CrazyTanks
 */


#ifndef _CREATEOBJECTSTRATEGY_H
#define _CREATEOBJECTSTRATEGY_H

#include "GameObject.h"

class CreateObjectStrategy {
public: 
    
    /**
     * @param prototype
     * @param count
     */
    virtual GameObject CreateObject(const GameObject prototype, const int count) = 0;
};

#endif //_CREATEOBJECTSTRATEGY_H