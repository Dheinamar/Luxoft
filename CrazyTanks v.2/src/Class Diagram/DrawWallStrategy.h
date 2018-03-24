/**
 * Project CrazyTanks
 */


#ifndef _DRAWWALLSTRATEGY_H
#define _DRAWWALLSTRATEGY_H

#include "DrawObjectStrategy.h"


class DrawWallStrategy: public DrawObjectStrategy {
  void drawObject (const pair<int, int> coordinates,
                   Graphics& graphics, const Pen& pen) override;
};

#endif //_DRAWWALLSTRATEGY_H