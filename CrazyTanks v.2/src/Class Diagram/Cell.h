/**
 * Project CrazyTanks
 */


#ifndef _CELL_H
#define _CELL_H

#include <utility>
#include <memory>

#include "GameObject.h"

using namespace std;

class Cell {
public: 
    
	shared_ptr<GameObject> getContent() const;
    
    /**
     * @param content
     */
	shared_ptr<GameObject> setContent(const GameObject& content);
    
    const pair<int, int> getCoordinates() const;
    
    /**
     * @param object
     */
    void add(const GameObject& object);
    
    void clear();
private: 
    shared_ptr<GameObject> content_;
    const pair<int, int> COORDINATES_;
};

#endif //_CELL_H