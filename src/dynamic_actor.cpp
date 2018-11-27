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
		acceleration(Vector2D(0, 0)),
		actionAtBounds(DIE) {

}

// 
// update (double)
//
void DynamicActor::update(double percentTimeElapsed) {
	if(!this->isVisible())
		return;

	// Update position
	this->velocity += this->acceleration * percentTimeElapsed;
	this->position += this->velocity * percentTimeElapsed;
}

// 
// checkBounds (unsigned int, unsigned int)
//
void DynamicActor::checkBounds(unsigned int width, unsigned int height) {
	auto x = this->position.getX();
	auto y = this->position.getY(); 

	// Otherwise perform your bounds action
	switch(this->actionAtBounds) {
		case WRAP:
			if(x - this->transformedSprite->getSpriteWidth() < 0) 
				this->position.setX(width);
			if(x > width) 
				this->position.setX(0);
			if(y - this->transformedSprite->getSpriteHeight() < 0) 
				this->position.setY(height);
			if(y > height) 
				this->position.setY(0);
			break;
		
		case BOUNCE:
			if(x < 0 || x + this->transformedSprite->getSpriteWidth() > width)
				this->velocity.setX(this->velocity.getX() * -1);
			if(y < 0 || y + this->transformedSprite->getSpriteHeight() > height) 
				this->velocity.setY(this->velocity.getY() * -1);
			break;
		
		case DIE:
			if(x < 0 || x + this->transformedSprite->getSpriteWidth() > width ||
					y < 0 || y + this->transformedSprite->getSpriteHeight() > height) 
				this->setVisible(false);
			break;
		
		case STOP:
			if(x < 0 || x + this->transformedSprite->getSpriteWidth() > width
					|| y < 0 || y + this->transformedSprite->getSpriteHeight() > height)
				this->velocity = Vector2D(0, 0);
			break;
	}
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
Vector2D DynamicActor::getVelocity() {
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
Vector2D DynamicActor::getAcceleration() {
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