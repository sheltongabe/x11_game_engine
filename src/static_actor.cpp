/**
 *  @file	static_actor.cpp
 *  @brief	define the implementation of the static actor
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-17-2018
 *  @version	0.0
 */

#include "static_actor.h"

//
// Default Constructor
//
StaticActor::StaticActor() : 
		Actor(),
		position(Vector2D(0, 0)) {

}

// 
// update (double)
//
void StaticActor::update(double percentTimeElapsed) {

}

// 
// render ()
//
void StaticActor::render(const Drawable& window) {
	if(!this->isVisible())
		return;
	
	// Render
	this->transformedSprite->draw(this->position.getX(), this->position.getY(), window);
}

// 
// setPosition (Vector2D)
//
void StaticActor::setPosition(const Vector2D& position) {
	this->position = position;
}

//
// getPosition
//
Vector2D StaticActor::getPosition() {
	return this->position;
}

//
// Destructor 
//
StaticActor::~StaticActor() {

}