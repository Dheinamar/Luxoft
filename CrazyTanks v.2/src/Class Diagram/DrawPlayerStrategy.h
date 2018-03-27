/**
 * Project CrazyTanks
 */


#ifndef _DRAWPLAYERSTRATEGY_H
#define _DRAWPLAYERSTRATEGY_H

#include "DrawObjectStrategy.h"


class DrawPlayerStrategy : public DrawObjectStrategy
{
public:
  DrawPlayerStrategy ();
  void drawObject (const pair<int, int> coordinates, Way way,
                   Graphics& graphics, const Pen& pen) override;
private:
  const pair<int, int> SIZE;
  const pair<int, int> TURRET_SIZE;
  const Pen WHITE;
};

#endif //_DRAWPLAYERSTRATEGY_H