/**
 * Project CrazyTanks
 */


#ifndef _CREATEWALLSTRATEGY_H
#define _CREATEWALLSTRATEGY_H

#include "CreateObjectStrategy.h"
#include "Field.h"
#include "Way.h"


class CreateWallStrategy: public CreateObjectStrategy {
public:
  vector<GameObject> CreateObject (const GameObject& prototype) override;
private:
  static const int N_WAYS = 4;
  vector<pair<int, int>> getWallCoordinates () const;
  vector<pair<int, int>> randomizeWallCoordinates (int wallSize) const;
};

#endif //_CREATEWALLSTRATEGY_H