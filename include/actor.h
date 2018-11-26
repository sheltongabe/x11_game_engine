/**
 * @file	actor.h
 * @brief	Implement a Base Actor class that will contain Sprites
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	11-17-2018
 * @version	0.1
 */

#ifndef ACTOR_H
#define ACTOR_H

#include <string>

#include "sprite.h"
#include "vector_2d.h"

/**
 * @enum	Transformations
 * @brief	Define constants on whether or not the transformations have been changed
 */
enum TransformationsChanged {
	UNCHANGED,
	CHANGED,
};

/**
 * @class	Actor
 * @brief	Items actually displayed to the screen
 * 
 * This will hold one sprite, and a key to the original sprite in the registry
 * TODO: Implement a sprite registry, and way to copy sprites.
 * The stored sprite is what will actually be displayed and may have had transformations applied
 * Any time a new set of transformations needs to be applied, I look up in the registry the original
 *  with the key and copy it.
 * This Abstract class will map the idea that an Actor has an update, and render method that needs implemented, 
 *  as well as implements the transformations.
 * Subclasses will implement the idea of position, velocity, acceleration, ect...
 */
class Actor {
	public:
		/**
		 * @brief	Default Constructor
		 */
		Actor();
		Actor(Actor& copy) = delete;
		Actor(Actor&& move) = delete;

		/**
		 * @brief	Update qualities of the Actor, implemented by children
		 * 
		 * @param	double		percentTimeElapsed
		 */
		virtual void update(double percentTimeElapsed) = 0;

		/**
		 * @brief	Draws the transformed sprite at its location, implemented by children
		 * @param	Window		window to draw the sprite to
		 */
		virtual void render(const Drawable& window) = 0;

		/// Set if the Actor is visible or not
		virtual void setVisible(bool visible);

		/// Check if the Actor is visible or not
		virtual bool isVisible();

		// TODO: Implement Transformation code
		/**
		 * @brief	Apply the accumulated transformations to a clone of the original sprite if needed
		 * 
		 * Check if the any transformations have been changed
		 * Get a clone of the original sprite, and apply the transformations
		 * delete transformedSprite, and store the clone and transformed sprite
		 * Set transformations as unchanged
		 */
		void applyTransform();

		/**
		 * @brief	Scale the Actor by a certain amount, specified by Vector2D
		 * 
		 * Also sets transformationDirty 
		 * 
		 * @param	Vector2D	Factors to scale by, by component
		 */
		void scale(Vector2D factor);

		/**
		 * @brief	Rotate by an angle in radians
		 * 
		 * Also sets transformationDirty 
		 * 
		 * @param	double		angle in radians
		 */
		void rotate(double angleInRadians);

		/**
		 * @brief	Destructor
		 */
		virtual ~Actor();

	protected:
		/**
		 * @brief	Do any preperation for the sprite to be displayed
		 */
		virtual void load();

		/// The pointer to the sprite to be displayed
		Sprite* transformedSprite;

		/// Key for the sprite
		std::string name;

		/// Track whether or not the transformation variables have been changed
		TransformationsChanged transformationsDirty;

		/// Tracks whether the actor is visible or not, if it should be redendered or updated
		bool visible;

	private:

};

#endif