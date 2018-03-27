/**
 * Project CrazyTanks
 */


#include "DrawPlayerStrategy.h"

 /**
  * DrawPlayerStrategy implementation
  */

DrawPlayerStrategy::DrawPlayerStrategy () :SIZE (pair<int, int> (30, 30)),
                                           TURRET_SIZE (pair<int, int> (10, 15)),
                                           WHITE (Color (255, 255, 255))
{}

void DrawPlayerStrategy::drawObject (const pair<int, int> coordinates, Way way,
                                     Graphics & graphics, const Pen & pen)
{
  const auto TURRET_SIDE_INDENT = (SIZE.first - TURRET_SIZE.first) / 2,
    TURRET_BACK_INDENT = SIZE.second / 2;

  graphics.DrawRectangle (&pen, coordinates.first, coordinates.second,
                          SIZE.first, SIZE.second);
  switch (way) {
  case UP:
    graphics.DrawRectangle (&WHITE,
                            coordinates.first + TURRET_SIDE_INDENT,
                            coordinates.second,
                            TURRET_SIZE.first,
                            TURRET_SIZE.second);
    break;
  case LEFT:
    graphics.DrawRectangle (&WHITE,
                            coordinates.first,
                            coordinates.second + TURRET_SIDE_INDENT,
                            TURRET_SIZE.second,
                            TURRET_SIZE.first);
    break;
  case DOWN:
    graphics.DrawRectangle (&WHITE,
                            coordinates.first + TURRET_SIDE_INDENT,
                            coordinates.second + TURRET_BACK_INDENT,
                            TURRET_SIZE.first,
                            TURRET_SIZE.second);
    break;
  case RIGHT:
    graphics.DrawRectangle (&WHITE,
                            coordinates.first + TURRET_BACK_INDENT,
                            coordinates.second + TURRET_SIDE_INDENT,
                            TURRET_SIZE.second,
                            TURRET_SIZE.first);
    break;
  default:
    break;
  }
}
