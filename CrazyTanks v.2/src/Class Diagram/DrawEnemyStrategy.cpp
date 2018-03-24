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
DrawEnemyStrategy::drawObject (const pair<int, int> coordinates,
                               Graphics graphics, const Pen pen)
{
  graphics.DrawRectangle (&pen, coordinates.first, coordinates.second,
                          size_.first, size_.second);
}