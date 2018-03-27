/**
 * Project CrazyTanks
 */


#include "DrawGoldStrategy.h"

/**
 * DrawGoldStrategy implementation
 */

DrawGoldStrategy::DrawGoldStrategy () :SIZE (pair<int, int> (30, 30))
{}

void DrawGoldStrategy::drawObject (const pair<int, int> coordinates, Way way,
                                   Graphics & graphics, const Pen & pen)
{
  graphics.DrawRectangle (&pen, coordinates.first, coordinates.second,
                          SIZE.first, SIZE.second);
}
