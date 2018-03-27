/**
 * Project CrazyTanks
 */


#ifndef _DRAWOBJECTSTRATEGY_H
#define _DRAWOBJECTSTRATEGY_H

#include <utility>
#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>

#include "Way.h"

using namespace std;
using namespace Gdiplus;

class DrawObjectStrategy
{
public:

  /**
  * @param coordinates
  */
  virtual void drawObject (const pair<int, int> coordinates, Way way,
                           Graphics& graphics, const Pen& pen) = 0;
};

#endif //_DRAWOBJECTSTRATEGY_H