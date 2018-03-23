/**
 * Project CrazyTanks
 */


#ifndef _CREATEOBJECTSTRATEGY_H
#define _CREATEOBJECTSTRATEGY_H

#include <vector>

#include "GameObject.h"

using namespace std;

class CreateObjectStrategy {
public: 
    
    /**
     * @param prototype
     */
    virtual vector<GameObject> CreateObject(const GameObject& prototype) = 0;
};

#endif //_CREATEOBJECTSTRATEGY_H