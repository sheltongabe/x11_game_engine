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
// Destructor 
//
Actor::~Actor() {
	delete this->transformedSprite;
}