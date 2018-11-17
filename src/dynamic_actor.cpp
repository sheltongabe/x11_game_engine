/**
 *  @file	dynamic_actor.cpp
 *  @brief	Provide an implementation for DynamicActor
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-17-2018
 *  @version	0.1
 */

#include "dynamic_actor.h"

//
// Default Constructor
//
DynamicActor::DynamicActor() :
		StaticActor(),
		velocity(Vector2D(0, 0)),
		acceleration(Vector2D(0, 0)) {

}

// 
// update (double)
//
void DynamicActor::update(double percentTimeElapsed) {
	this->velocity += this->acceleration * percentTimeElapsed;
	this->position += this->velocity * percentTimeElapsed;
}

// 
// checkBounds (Scene*)
//
void DynamicActor::checkBounds(Scene* scene) {

}

// 
// applyForce (const Vector2D&)
//
void DynamicActor::applyForce(const Vector2D& force) {
	this->acceleration += force;
}

// 
// getVelocity () -> Vector2D
//
Vector2D DynamicActor::getVelocity() const {
	return this->velocity;
}

// 
// setVelocity (const Vector2D&)
//
void DynamicActor::setVelocity(const Vector2D& velocity) {
	this->velocity = velocity;
}

// 
// getAcceleration () -> Vector2D
//
Vector2D DynamicActor::getAcceleration() const {
	return this->acceleration;
}

// 
// setAcceleration (const Vector2D&)
//
void DynamicActor::setAcceleration(const Vector2D& acceleration) {
	this->acceleration = acceleration;
}

// 
// setBoundsAction (const BoundsAction&)
//
void DynamicActor::setBoundsAction(const BoundsAction& action) {
	this->actionAtBounds = action;
}

//
// Destructor 
//
DynamicActor::~DynamicActor() {

}