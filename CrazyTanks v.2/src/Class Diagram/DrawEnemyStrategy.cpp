/**
 * Project CrazyTanks
 */


#include "DrawEnemyStrategy.h"

 /**
  * DrawEnemyStrategy implementation
  */

DrawEnemyStrategy::DrawEnemyStrategy () :size_ (pair<int, int> (30, 30))
{}

void
DrawEnemyStrategy::drawObject (const pair<int, int> coordinates)
{
  Drawer::getInstance ()->getGraphics ().
    DrawRectangle (Drawer::getInstance ()->drawRed (),
                   coordinates.first, coordinates.second,
                   size_.first, size_.second);
}