/**
 * Project CrazyTanks
 */


#ifndef _DRAWER_H
#define _DRAWER_H

#include <memory>
#include <objidl.h>
#include <gdiplus.h>
#include <windows.h>

#pragma comment(lib, "gdiplus.lib")

#include "DrawObjectStrategy.h"
#include "DrawInfo.h"

using namespace std;
using namespace Gdiplus;

class Drawer
{
public:

  void drawField ();


  Graphics getGraphics () const;

  Pen* drawRed () const;

  static unique_ptr<Drawer> getInstance ();
private:

  /**
  * @param strategy
  */
  void setDrawStrategy (const DrawObjectStrategy& strategy);
private:
  static unique_ptr<Drawer> instance_;
  Graphics graphics_;
  const Pen red;
  unique_ptr<DrawInfo> drawInfo_;
  unique_ptr<DrawObjectStrategy> drawStrategy;
};

#endif //_DRAWER_H