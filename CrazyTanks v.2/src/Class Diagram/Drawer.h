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
#include "DrawEnemyStrategy.h"
#include "DrawGoldStrategy.h"
#include "DrawPlayerStrategy.h"
#include "DrawProjectileStrategy.h"
#include "DrawWallStrategy.h"
#include "DrawInfo.h"

using namespace std;
using namespace Gdiplus;

class Drawer
{
public:

  Drawer (const DrawInfo& drawInfo, const HDC hdc, const HDC bufferHdc);

  void drawField ();

  void drawUi ();

  void drawStats ();


  Graphics& getGraphics () const;

  static unique_ptr<Drawer>& getInstance (const DrawInfo& drawInfo);
private:

  /**
  * @param strategy
  */
  void setDrawStrategy (const DrawObjectStrategy& strategy);
private:
  static unique_ptr<Drawer> instance_;
  HDC hdc_;
  HDC bufferHdc_;
  Graphics graphics_;
  const Pen RED;
  const Pen GOLD;
  const Pen BLUE;
  const Pen BLACK;
  const Pen GRAY;
  const Pen WHITE;
  const int FIELD_BORDER = 15;
  const int CAPTION_SIZE = 35;
  const int CELL_SIZE = 40;
  const int STRING_LENGTH = 4;
  unique_ptr<DrawInfo> drawInfo_;
  unique_ptr<DrawObjectStrategy> drawStrategy_;

  void drawObject (const GameObject& gameObject, const Pen& pen);
};

#endif //_DRAWER_H