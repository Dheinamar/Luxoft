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

Drawer::Drawer (DrawInfo& drawInfo, HWND hWnd, PAINTSTRUCT  ps) :
  drawInfo_(&drawInfo), graphics_(BeginPaint (hWnd, &ps))
{
  
}

void Drawer::drawField ()
{

}

Graphics Drawer::getGraphics () const
{
  return graphics_;
}
