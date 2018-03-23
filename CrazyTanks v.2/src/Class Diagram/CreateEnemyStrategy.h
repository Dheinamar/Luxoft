/**
 * Project CrazyTanks
 */


#ifndef _CREATEENEMYSTRATEGY_H
#define _CREATEENEMYSTRATEGY_H

#include "CreateObjectStrategy.h"
#include "Field.h"


class CreateEnemyStrategy : public CreateObjectStrategy
{
public:

  vector<GameObject> CreateObject (const GameObject& prototype) override;
private:

  pair<int, int> getEnemyCoordinates () const;
  pair<int, int> randomizeEnemyCoordinates () const;
};

#endif //_CREATEENEMYSTRATEGY_H