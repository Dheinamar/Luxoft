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
  drawStrategy_.reset (const_cast<DrawObjectStrategy*>(&strategy));
}

void
Drawer::drawObject (const GameObject& gameObject, const Pen& pen)
{
  auto coordinates = gameObject.getCoordinates ();
  coordinates.first = coordinates.first * CELL_SIZE + FIELD_START.first;
  coordinates.second = coordinates.second * CELL_SIZE + FIELD_START.second;
  drawStrategy_->drawObject (coordinates, graphics_, pen);
}

Drawer::Drawer (const DrawInfo& drawInfo, const HDC hdc, const HDC bufferHdc) :
  drawInfo_ (unique_ptr<DrawInfo> (const_cast<DrawInfo*>(&drawInfo))),
  graphics_ (bufferHdc), hdc_ (hdc), bufferHdc_ (bufferHdc)
{}

void
Drawer::drawField ()
{
  pair<int, int> coordinates;

  auto enemies = drawInfo_->getEnemies ();
  setDrawStrategy (DrawEnemyStrategy ());
  for (auto i = 0; i < enemies.size (); ++i) {
    drawObject (enemies[i], RED);
  }

  setDrawStrategy (DrawGoldStrategy ());
  drawObject (drawInfo_->getGold (), GOLD);

  setDrawStrategy (DrawPlayerStrategy ());
  drawObject (drawInfo_->getPlayer (), BLUE);

  auto projectiles = drawInfo_->getProjectiles ();
  setDrawStrategy (DrawProjectileStrategy ());
  for (auto i = 0; i < projectiles.size (); ++i) {
    drawObject (projectiles[i], BLACK);
  }

  auto walls = drawInfo_->getWalls ();
  setDrawStrategy (DrawWallStrategy ());
  for (auto i = 0; i < walls.size (); ++i) {
    drawObject (walls[i], BLACK);
  }
}

Graphics&
Drawer::getGraphics () const
{
  return const_cast<Graphics&>(graphics_);
}

unique_ptr<Drawer>&
Drawer::getInstance (const DrawInfo& drawInfo)
{
  if (instance_ == nullptr) {
    HWND hwnd = GetConsoleWindow ();
    PAINTSTRUCT  paintstruct;
    HDC hdc = BeginPaint (hwnd, &paintstruct),
      bufferHdc = CreateCompatibleDC (hdc);
    instance_ = unique_ptr<Drawer> ((new Drawer (drawInfo, hdc, bufferHdc)));
  }
  return instance_;
}
