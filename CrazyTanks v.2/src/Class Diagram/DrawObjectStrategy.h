/**
 * Project CrazyTanks
 */


#ifndef _DRAWOBJECTSTRATEGY_H
#define _DRAWOBJECTSTRATEGY_H

#include <utility>

using namespace std;

class DrawObjectStrategy {
public: 
    
    /**
     * @param coordinates
     */
    virtual void drawObject(const pair<int, int> coordinates,
                            Graphics graphics, const Pen pen) = 0;
};

#endif //_DRAWOBJECTSTRATEGY_H