/**
 * Project CrazyTanks
 */


#ifndef _CONCRETETANKCOMMAND_H
#define _CONCRETETANKCOMMAND_H

#include <memory>

#include "TankCommand.h"
#include "Tank.h"

using namespace std;

class ConcreteTankCommand : public TankCommand
{
public:

  ConcreteTankCommand (const Tank& receiver);

  void execute (Command command) const override;
private:
  unique_ptr<Tank> receiver_;
};

#endif //_CONCRETETANKCOMMAND_H