/**
 * Project CrazyTanks
 */


#include "DrawWallStrategy.h"

 /**
  * DrawWallStrategy implementation
  */

DrawWallStrategy::DrawWallStrategy () :SIZE (pair<int, int> (30, 30))
{}

void DrawWallStrategy::drawObject (const pair<int, int> coordinates, Way way,
                                   Graphics & graphics, const Pen & pen)
{
  graphics.DrawRectangle (&pen, coordinates.first, coordinates.second,
                          SIZE.first, SIZE.second);
}
