/**
 * Project CrazyTanks
 */


#ifndef _DRAWPLAYERSTRATEGY_H
#define _DRAWPLAYERSTRATEGY_H

#include "DrawObjectStrategy.h"


class DrawPlayerStrategy: public DrawObjectStrategy {
  void drawObject (const pair<int, int> coordinates,
                   Graphics& graphics, const Pen& pen) override;
};

#endif //_DRAWPLAYERSTRATEGY_H