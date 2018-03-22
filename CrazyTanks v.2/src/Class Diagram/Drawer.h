/**
 * Project CrazyTanks
 */


#ifndef _DRAWER_H
#define _DRAWER_H

#include <memory>

#include "DrawObjectStrategy.h"
#include "DrawInfo.h"

using namespace std;

class Drawer {
public: 
    
    void drawField();

	static unique_ptr<Drawer> getInstance ();
private: 
    unique_ptr<DrawInfo> drawInfo_;
    unique_ptr<DrawObjectStrategy> drawStrategy;

	/**
	* @param strategy
	*/
	void setDrawStrategy (const DrawObjectStrategy& strategy);
private:
	static unique_ptr<Drawer> instance_;
};

#endif //_DRAWER_H