/**
 * Project CrazyTanks
 */


#ifndef _DRAWENEMYSTRATEGY_H
#define _DRAWENEMYSTRATEGY_H

#include "DrawObjectStrategy.h"
#include "Drawer.h"

class DrawEnemyStrategy : public DrawObjectStrategy
{
public:
  DrawEnemyStrategy ();
  void drawObject (const pair<int, int> coordinates, Way way,
                   Graphics& graphics, const Pen& pen) override;
private:
  const pair<int, int> SIZE;
  const pair<int, int> TURRET_SIZE;
  const Pen BLACK;
};

#endif //_DRAWENEMYSTRATEGY_H