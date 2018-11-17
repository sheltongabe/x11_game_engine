/**
 *  @file	dynamic_actor.h
 *  @brief	Define an Actor that moves about
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-17-2018
 *  @version	0.1
 */

#ifndef DYNAMIC_ACTOR_H
#define DYNAMIC_ACTOR_H

#include "static_actor.h"
#include "scene.h"

/**
 * @enum	BoundsAction
 * @brief	Different actions to take when the actor reaches the edge of the screen
 */
enum BoundsAction {
	WRAP,
	BOUNCE,
	DIE,
};

/**
 * @class		DynamicActor
 * @brief		An Extension of StaticActor that allows for movement and acceleration
 * 
 * Adds a velocity and acceleration vector, with the hopes that you only manipulate the acceleration vector by
 *  adding a force
 */
class DynamicActor : public StaticActor{
	public:
		/**
		 * 	@brief	Default Constructor
		 */
		DynamicActor();
		DynamicActor(DynamicActor& copy) = delete;
		DynamicActor(DynamicActor&& copy) = delete;

		/**
		 * @brief	Overload the update method to update position
		 * 
		 * By applying the acceleration vector to velocity
		 * And the velocity vector to position
		 */
		virtual void update(double percentElapsedTime);

		/**
		 * @brief	Figure out if this Actor is of the Scene, and if so take action based on the actionAtBounds
		 * 
		 * Action is determined by a map of lambda expressions
		 * 
		 * @param	Scene*	scene
		 */
		virtual void checkBounds(Scene* scene);

		/**
		 * @brief	Apply a force, adding to the acceleration vector
		 * 
		 * The prefered way to modify position
		 * 
		 * @param	Vector2D&	force
		 */
		inline void applyForce(const Vector2D& force);

		/// getVelocity
		inline Vector2D getVelocity()const;

		/// Set the velocity
		inline void setVelocity(const Vector2D& velocity);

		/// get Acceleration
		inline Vector2D getAcceleration() const;

		/// set Acceleration
		inline void setAcceleration(const Vector2D& acceleration);

		/// Set Bounds Action
		inline void setBoundsAction(const BoundsAction& action);

		/**
		 * 	@brief	Destructor
		 */
		~DynamicActor();

	protected:
		/// Vector for velocity
		Vector2D velocity;

		/// Vector for acceleration
		Vector2D acceleration;

		/// Action to take upon reaching the bounds of the scene
		BoundsAction actionAtBounds;

	private:

};

#endif