/**
 *  @file	actor.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-17-2018
 *  @version	0.0
 */

#include "actor.h"

//
// Default Constructor
//
Actor::Actor() :
		transformedSprite(nullptr),
		transformationsDirty(UNCHANGED) {
	this->load();
}

// 
// load ()
//
void Actor::load() {

}

// 
// setVisible (bool)
//
void Actor::setVisible(bool visible) {
	this->visible = visible;
}

// 
// isVisible ()
//
bool Actor::isVisible() {
	return this->visible;
}

//
// Destructor 
//
Actor::~Actor() {
	delete this->transformedSprite;
}