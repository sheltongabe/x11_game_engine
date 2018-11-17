/**
 *  @file	static_actor.h
 *  @brief	Define an Actor that does not move, has only a defined position to be drawn at
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-17-2018
 *  @version	0.1
 */

#ifndef STATICACTOR_H
#define STATICACTOR_H

#include "actor.h"

/**
 * @class		StaticActor
 * @brief		Extend Actor to define a version that displays and does not move
 */
class StaticActor : public Actor {
	public:
		/**
		 * @brief	Default Constructor
		 */
		StaticActor();

		/**
		 * @brief	Overload Actor::update(double)
		 * @param	double		percentElapsedTime
		 */
		virtual void update(double percentElapsedTime);

		/**
		 * @brief	Overload Actor::render(Window)
		 * @param	Window		window to display on
		 */
		virtual void render(const Window& window);

		/// Set the position
		virtual void setPosition(const Vector2D& position);
		
		/// Get the position
		virtual Vector2D getPosition();

		/**
		 * @brief	Destructor
		 */
		~StaticActor();

	protected:
		/// The position of the Actor
		Vector2D position;

	private:

};

#endif