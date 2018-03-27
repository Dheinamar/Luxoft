/**
 * Project CrazyTanks
 */


#include "DrawProjectileStrategy.h"

 /**
  * DrawProjectileStrategy implementation
  */

DrawProjectileStrategy::DrawProjectileStrategy () :SIZE (pair<int, int> (5, 10))
{}

void DrawProjectileStrategy::drawObject (const pair<int, int> coordinates,
                                         Way way,
                                         Graphics & graphics,
                                         const Pen & pen)
{
  switch (way) {
  case UP:
    // Fallthrough.
  case DOWN:
    graphics.DrawRectangle (&pen, coordinates.first, coordinates.second,
                            SIZE.first, SIZE.second);
    break;
  case LEFT:
    // Fallthrough.
  case RIGHT:
    graphics.DrawRectangle (&pen, coordinates.first, coordinates.second,
                            SIZE.first, SIZE.second);
    break;
  default:
    break;
  }
}
