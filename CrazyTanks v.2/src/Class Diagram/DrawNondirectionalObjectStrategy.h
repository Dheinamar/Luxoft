/**
* Project CrazyTanks
*/


#ifndef _DRAWNONDIRECTIONALOBJECTSTRATEGY_H
#define _DRAWNONDIRECTIONALOBJECTSTRATEGY_H

#include "DrawObjectStrategy.h"
#include "Way.h"

using namespace std;

class DrawNondirectionalObjectStrategy : public DrawObjectStrategy
{
public:

  /**
  * @param coordinates
  */
  virtual void drawObject (const pair<int, int> coordinates,
                           Graphics& graphics, const Pen& pen) = 0;
};

#endif //_DRAWNONDIRECTIONALOBJECTSTRATEGY_H