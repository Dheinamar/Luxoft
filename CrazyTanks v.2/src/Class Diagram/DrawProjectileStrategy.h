/**
 * Project CrazyTanks
 */


#ifndef _DRAWPROJECTILESTRATEGY_H
#define _DRAWPROJECTILESTRATEGY_H

#include "DrawObjectStrategy.h"


class DrawProjectileStrategy: public DrawObjectStrategy {
  void drawObject (const pair<int, int> coordinates,
                   Graphics& graphics, const Pen& pen) override;
};

#endif //_DRAWPROJECTILESTRATEGY_H