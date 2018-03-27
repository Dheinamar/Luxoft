/**
 * Project CrazyTanks
 */


#ifndef _DRAWGOLDSTRATEGY_H
#define _DRAWGOLDSTRATEGY_H

#include "DrawObjectStrategy.h"
#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>

using namespace Gdiplus;

class DrawGoldStrategy: public DrawObjectStrategy {
public:
  DrawGoldStrategy ();
  void drawObject (const pair<int, int> coordinates,
                   Graphics& graphics, const Pen& pen) override;
private:
  const pair<int, int> SIZE;
};

#endif //_DRAWGOLDSTRATEGY_H