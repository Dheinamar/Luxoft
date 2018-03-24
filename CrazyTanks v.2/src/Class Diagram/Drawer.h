/**
 * Project CrazyTanks
 */


#ifndef _DRAWER_H
#define _DRAWER_H

#include <memory>
#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>

#include "DrawObjectStrategy.h"
#include "DrawInfo.h"

using namespace std;
using namespace Gdiplus;

class Drawer
{
public:

  Drawer (const DrawInfo& drawInfo, const HDC hdc);

  void drawField ();


  Graphics& getGraphics () const;

  const Pen& drawRed () const;

  static unique_ptr<Drawer>& getInstance (const DrawInfo& drawInfo);
private:

  /**
  * @param strategy
  */
  void setDrawStrategy (const DrawObjectStrategy& strategy);
private:
  static unique_ptr<Drawer> instance_;
  HDC context;
  HDC memoryContext;
  Graphics graphics_;
  const Pen RED = Color(255, 255, 0, 0);
  unique_ptr<DrawInfo> drawInfo_;
  unique_ptr<DrawObjectStrategy> drawStrategy_;
};

#endif //_DRAWER_H