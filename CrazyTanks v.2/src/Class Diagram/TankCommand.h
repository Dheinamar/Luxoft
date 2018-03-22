/**
 * Project CrazyTanks
 */


#ifndef _TANKCOMMAND_H
#define _TANKCOMMAND_H

#include "Command.h"

class TankCommand {
public: 
    
    /**
     * @param command
     */
    virtual void execute(const Command command) const = 0;
};

#endif //_TANKCOMMAND_H