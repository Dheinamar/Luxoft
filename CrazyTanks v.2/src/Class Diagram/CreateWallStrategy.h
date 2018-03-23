/**
 * Project CrazyTanks
 */


#ifndef _CREATEWALLSTRATEGY_H
#define _CREATEWALLSTRATEGY_H

#include "CreateObjectStrategy.h"
#include "Field.h"


class CreateWallStrategy: public CreateObjectStrategy {
public:
  vector<GameObject> CreateObject (const GameObject& prototype,
                                   const int count) override;
private:
  vector<pair<int, int>> getWallsCoordinates () const;
};

#endif //_CREATEWALLSTRATEGY_H