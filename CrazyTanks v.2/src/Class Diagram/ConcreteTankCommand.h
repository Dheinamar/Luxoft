/**
 * Project CrazyTanks
 */


#ifndef _CONCRETETANKCOMMAND_H
#define _CONCRETETANKCOMMAND_H

#include <memory>

#include "TankCommand.h"
#include "Tank.h"

using namespace std;

class ConcreteTankCommand: public TankCommand {
private: 
    unique_ptr<Tank> receiver_;
	void execute (Command command) const override;
};

#endif //_CONCRETETANKCOMMAND_H