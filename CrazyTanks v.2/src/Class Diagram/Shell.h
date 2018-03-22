/**
 * Project CrazyTanks
 */


#ifndef _SHELL_H
#define _SHELL_H

#include "Projectile.h"
#include "Tank.h"


class Shell: public Projectile {
private: 
    Tank owner_;
};

#endif //_SHELL_H