/**
 * Project CrazyTanks
 */


#ifndef _DRAWENEMYSTRATEGY_H
#define _DRAWENEMYSTRATEGY_H

#include "DrawObjectStrategy.h"
#include "Drawer.h"


class DrawEnemyStrategy: public DrawObjectStrategy {
public:
  DrawEnemyStrategy ();
  void drawObject (const pair<int, int> coordinates) override;
private:
  const pair<int, int> size_;
};

#endif //_DRAWENEMYSTRATEGY_H