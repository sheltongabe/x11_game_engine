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

#include <string>

#include "x_screen.h"
#include "x_display.h"

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

		// ------------------------------------------------
		// Drawing Utility functions onto the sprite
		
		/**
		 * @brief	Draw a single Point (Useful for transormations) using the Foreground settings
		 * 
		 * @param	int 	x
		 * @param	int 	y
		 */
		void drawPoint(int x, int y);

		/**
		 * @brief	Draw a line from point 1 to point 2, using foreground settings on the gc
		 * 
		 * @param	int		x1
		 * @param	int		y1
		 * @param	int		x2
		 * @param	int		y2
		 */
		void drawLine(int x1, int y1, int x2, int y2);

		/**
		 * @brief	Draw a rectangle using the foreground settings
		 * 
		 * @param	int		x
		 * @param	int		y
		 * @param	int		width
		 * @param	int		heigh
		 */
		void drawRectangle(int x, int y, int width, int height);

		/**
		 * @brief	Draw and fill a rectangle using the foreground settings
		 * 
		 * @param	int		x
		 * @param	int		y
		 * @param	int		width
		 * @param	int		heigh
		 */
		void fillRectangle(int x, int y, int width, int height);

		/**
		 * @brief	Draw a string to the screen
		 * 
		 * @param	int 			x
		 * @param	int 			y
		 * @param	const char*		String to draw
		 */
		void drawString(int x, int y, const char* message);

		/**
		 * @brief	Draw a string to the screen
		 * 
		 * @param	int 			x
		 * @param	int 			y
		 * @param	std::string&	String to draw
		 */
		void drawString(int x, int y, const std::string& message);

		/**
		 * @brief	Set the color of the foreground
		 * 
		 * @param	const char*		color name
		 */
		void setColor(const char* color_name);

		/**
		 * @brief	Draw the sprite onto the passed window, at the specified location
		 * 
		 * @param	int 	x
		 * @param	int 	y
		 * @param	Window	destination
		 */
		void draw(int x, int y, Window destination);

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

		/// Colormap
		Colormap cmap;
};

#endif