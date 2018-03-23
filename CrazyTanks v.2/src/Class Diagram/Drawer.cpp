/**
 * Project CrazyTanks
 */


#include "Drawer.h"

 /**
  * Drawer implementation
  */


  /**
   * @param strategy
   */
void
Drawer::setDrawStrategy (const DrawObjectStrategy& strategy)
{

}

Drawer::Drawer (DrawInfo& drawInfo) : drawInfo_(&drawInfo)
{
  HWND hWnd = GetConsoleWindow ();
  PAINTSTRUCT  ps;
  HDC hDC = BeginPaint (hWnd, &ps);
  Graphics graphics (hDC);
  graphics_ (graphics);
}

void Drawer::drawField ()
{

}