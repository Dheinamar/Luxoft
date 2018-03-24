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
  drawStrategy_.reset(const_cast<DrawObjectStrategy*>(&strategy));
}

Drawer::Drawer (const DrawInfo& drawInfo, const HDC hdc) :
  drawInfo_ (unique_ptr<DrawInfo>(const_cast<DrawInfo*>(&drawInfo))),
  graphics_ (hdc)
{

}

void
Drawer::drawField ()
{
  setDrawStrategy(Draw)
}

Graphics&
Drawer::getGraphics () const
{
  return const_cast<Graphics&>(graphics_);
}

const Pen&
Drawer::drawRed () const
{
  return RED;
}

unique_ptr<Drawer>&
Drawer::getInstance (const DrawInfo& drawInfo)
{
  if (instance_ == nullptr) {
    HWND hwnd = GetConsoleWindow ();
    PAINTSTRUCT  paintstruct;
    HDC hdc = BeginPaint (hwnd, &paintstruct);
    instance_ = unique_ptr<Drawer> ((new Drawer (drawInfo, hdc)));
  }
  return instance_;
}
