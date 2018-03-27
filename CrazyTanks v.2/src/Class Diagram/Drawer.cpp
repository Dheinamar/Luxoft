/**
 * Project CrazyTanks
 */

#define _CRT_SECURE_NO_WARNINGS

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
  auto way = gameObject.getWay ();
  coordinates.first = coordinates.first * CELL_SIZE + FIELD_BORDER;
  coordinates.second = coordinates.second * CELL_SIZE + FIELD_BORDER;
  drawStrategy_->drawObject (coordinates, way, graphics_, pen);
}

Drawer::Drawer (const DrawInfo& drawInfo, const HDC hdc, const HDC bufferHdc) :
  drawInfo_ (unique_ptr<DrawInfo> (const_cast<DrawInfo*>(&drawInfo))),
  graphics_ (bufferHdc), hdc_ (hdc), bufferHdc_ (bufferHdc),
  RED (Color (255, 0, 0)), GOLD (Color (255, 215, 0)),
  BLUE (Color (0, 0, 255)), BLACK (Color (0, 0, 0)),
  GRAY (Color (128, 128, 128)), WHITE (Color (255, 255, 255))
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
    drawObject (dynamic_cast<GameObject&>(projectiles[i]), BLACK);
  }

  auto walls = drawInfo_->getWalls ();
  setDrawStrategy (DrawWallStrategy ());
  for (auto i = 0; i < walls.size (); ++i) {
    drawObject (walls[i], GRAY);
  }
}

void Drawer::drawUi ()
{
  const auto FIELD_SIZE = drawInfo_->getSize ();

  // Top border of game field.
  graphics_.DrawRectangle (&WHITE,
                           0,
                           0,
                           FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 2,
                           FIELD_BORDER);
  // Left border of game field.
  graphics_.DrawRectangle (&WHITE,
                           0,
                           FIELD_BORDER,
                           FIELD_BORDER,
                           FIELD_SIZE * CELL_SIZE);
  // Right border of game field.
  graphics_.DrawRectangle (&WHITE,
                           FIELD_SIZE * CELL_SIZE + FIELD_BORDER,
                           FIELD_BORDER,
                           FIELD_BORDER,
                           FIELD_SIZE * CELL_SIZE);
  // Bottom border of game field.
  graphics_.DrawRectangle (&WHITE,
                           0,
                           FIELD_SIZE * CELL_SIZE + FIELD_BORDER,
                           FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 2,
                           FIELD_BORDER);

  // UI captions' column.
  RECT
    healthCaption = { FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 3,
    FIELD_BORDER,
    FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 3 + CAPTION_SIZE,
    FIELD_BORDER + CAPTION_SIZE },
    scoreCaption = { FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 3,
    (FIELD_BORDER + CAPTION_SIZE) + FIELD_BORDER,
    FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 3 + CAPTION_SIZE,
    (FIELD_BORDER + CAPTION_SIZE) * 2 },
    timeCaption = { FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 3,
    (FIELD_BORDER + CAPTION_SIZE) * 2 + FIELD_BORDER,
    FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 3 + CAPTION_SIZE,
    (FIELD_BORDER + CAPTION_SIZE) * 3 };
  DrawText (bufferHdc_,
            "Health",
            -1,
            &healthCaption,
            DT_SINGLELINE | DT_RIGHT | DT_TOP);
  DrawText (bufferHdc_,
            "Score",
            -1,
            &scoreCaption,
            DT_SINGLELINE | DT_RIGHT | DT_TOP);
  DrawText (bufferHdc_,
            "Time",
            -1,
            &timeCaption,
            DT_SINGLELINE | DT_RIGHT | DT_TOP);

}

void Drawer::drawStats ()
{
  const auto FIELD_SIZE = drawInfo_->getSize ();
  char* health, *score, *time;
  _itoa (drawInfo_->getPlayer ().getHealth (), health, 10);
  _itoa (drawInfo_->getMaxEnemies (), score, 10);
  _itoa (drawInfo_->getTime (), time, 10);

  // UI stats' column.
  RECT
    healthStat = { FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 4 + CAPTION_SIZE,
    FIELD_BORDER,
    FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 4 + CAPTION_SIZE * 2,
    FIELD_BORDER + CAPTION_SIZE },
    scoreStat = { FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 4 + CAPTION_SIZE,
    (FIELD_BORDER + CAPTION_SIZE) + FIELD_BORDER,
    FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 4 + CAPTION_SIZE * 2,
    (FIELD_BORDER + CAPTION_SIZE) * 2 },
    timeStat = { FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 4 + CAPTION_SIZE,
    (FIELD_BORDER + CAPTION_SIZE) * 2 + FIELD_BORDER,
    FIELD_SIZE * CELL_SIZE + FIELD_BORDER * 4 + CAPTION_SIZE * 2,
    (FIELD_BORDER + CAPTION_SIZE) * 3 };
  DrawText (bufferHdc_,
            health,
            -1,
            &healthStat,
            DT_SINGLELINE | DT_RIGHT | DT_TOP);
  DrawText (bufferHdc_,
            score,
            -1,
            &scoreStat,
            DT_SINGLELINE | DT_RIGHT | DT_TOP);
  DrawText (bufferHdc_,
            time,
            -1,
            &timeStat,
            DT_SINGLELINE | DT_RIGHT | DT_TOP);

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
