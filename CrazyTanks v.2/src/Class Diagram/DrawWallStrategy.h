/**
 * Project CrazyTanks
 */


#ifndef _DRAWWALLSTRATEGY_H
#define _DRAWWALLSTRATEGY_H

#include "DrawObjectStrategy.h"


class DrawWallStrategy : public DrawObjectStrategy
{
public:
  DrawWallStrategy ();
  void drawObject (const pair<int, int> coordinates, Way way,
                   Graphics& graphics, const Pen& pen) override;
private:
  const pair<int, int> SIZE;
};

#endif //_DRAWWALLSTRATEGY_H