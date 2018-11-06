/**
 *  @file	sprite.h
 *  @brief	Define an image to be used by Actors and others
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-06-2018
 *  @version	0.1
 */

#ifndef SPRITE_H
#define SPRITE_H

#include "x_screen.h"

/**
 * @class		Sprite
 * @brief		Implement how a sprite stores an internal image and works with it
 * 
 * - Stores an internal Pixmap which on request it will draw to the specified window
 * - Provides a series of utility functions for drawing onto a pixmap
 * 
 */
class Sprite {
	public:
		Sprite() = delete;

		/**
		 * @brief	Initialize the internal Pixmap with a particuar width and height
		 * 
		 * @version	0.1
		 */
		Sprite(Display* display, unsigned int width, unsigned int height);

		/**
		 * 	@brief	Copy Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.0
		 */
		Sprite(Sprite& copy);

		/**
		 * 	@brief	Destructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.0
		 */
		~Sprite();

	protected:
		/// Connection to X11 Server
		Display* xDisplay;

		/// Image for this particular sprite
		Pixmap image;

		/// gc to draw on this particular Sprite
		GC graphicsContext;

		// Dimensions of the sprite
		unsigned int width, height;
};

#endif