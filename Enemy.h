#pragma once
#include "Tank.h"
class Enemy :
  public Tank
{
public:
  Enemy () : Tank () {};
  ~Enemy ();
};
