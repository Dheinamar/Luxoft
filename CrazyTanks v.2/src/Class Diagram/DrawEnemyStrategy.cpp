/**
 * Project CrazyTanks
 */


#include "DrawEnemyStrategy.h"

 /**
  * DrawEnemyStrategy implementation
  */

DrawEnemyStrategy::DrawEnemyStrategy () :SIZE (pair<int, int> (30, 30))
{}

void
DrawEnemyStrategy::drawObject (const pair<int, int> coordinates,
                               Graphics& graphics, const Pen& pen)
{
  graphics.DrawRectangle (&pen, coordinates.first, coordinates.second,
                          SIZE.first, SIZE.second);
}