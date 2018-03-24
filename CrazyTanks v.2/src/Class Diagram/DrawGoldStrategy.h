/**
 * Project CrazyTanks
 */


#ifndef _DRAWGOLDSTRATEGY_H
#define _DRAWGOLDSTRATEGY_H

#include "DrawObjectStrategy.h"
#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>


class DrawGoldStrategy: public DrawObjectStrategy {
  void drawObject (const pair<int, int> coordinates,
                   Graphics& graphics, const Pen& pen) override;
};

#endif //_DRAWGOLDSTRATEGY_H