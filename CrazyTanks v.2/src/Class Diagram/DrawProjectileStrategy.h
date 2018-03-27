/**
 * Project CrazyTanks
 */


#ifndef _DRAWPROJECTILESTRATEGY_H
#define _DRAWPROJECTILESTRATEGY_H

#include "DrawObjectStrategy.h"


class DrawProjectileStrategy : public DrawObjectStrategy
{
public:
  DrawProjectileStrategy ();
  void drawObject (const pair<int, int> coordinates, Way way,
                   Graphics& graphics, const Pen& pen) override;
private:
  const pair<int, int> SIZE;
};

#endif //_DRAWPROJECTILESTRATEGY_H