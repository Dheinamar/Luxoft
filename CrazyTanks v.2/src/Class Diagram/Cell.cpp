/**
 * Project CrazyTanks
 */


#include "Cell.h"

/**
 * Cell implementation
 */


shared_ptr<GameObject>
Cell::getContent() const {
	return content_;
}

/**
 * @param content
 */
shared_ptr<GameObject>
Cell::setContent(const GameObject& content) {
	*content_ = content;
	return content_;
}

const pair<int, int>
Cell::getCoordinates() const {
	return COORDINATES_;
}

/**
 * @param object
 */
void
Cell::add(const GameObject& object) {
	setContent (object);
}

void Cell::clear() {
	content_.reset ();
}