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
 * TODO: Isolate X11 references from this Sprite class
 * 
 * - Stores an internal Pixmap which on request it will draw to the specified window
 * - Provides a series of utility functions for drawing onto a pixmap
 * 
 */
class Sprite {
	public:
		Sprite();

		/**
		 * @brief	Initialize the internal Pixmap with a file
		 * 
		 * @version	0.1
		 */
		Sprite(Display* display, Window w, const char* filename);
		Sprite(Display* display, Window w, std::string filename);

		Sprite(Sprite& copy) = delete;
		Sprite(Sprite&& move) = delete;

		// ------------------------------------------------
		// Drawing Utility functions onto the sprite
		
		/**
		 * @brief	Draw a single Point (Useful for transormations) using the Foreground settings
		 * 
		 * @param	int 	x
		 * @param	int 	y
		 */
		virtual void drawPoint(int x, int y) = 0;

		/**
		 * @brief	Draw a line from point 1 to point 2, using foreground settings on the gc
		 * 
		 * @param	int		x1
		 * @param	int		y1
		 * @param	int		x2
		 * @param	int		y2
		 */
		virtual void drawLine(int x1, int y1, int x2, int y2) = 0;

		/**
		 * @brief	Draw a rectangle using the foreground settings
		 * 
		 * @param	int		x
		 * @param	int		y
		 * @param	int		width
		 * @param	int		heigh
		 */
		virtual void drawRectangle(int x, int y, int width, int height) = 0;

		/**
		 * @brief	Draw and fill a rectangle using the foreground settings
		 * 
		 * @param	int		x
		 * @param	int		y
		 * @param	int		width
		 * @param	int		heigh
		 */
		virtual void fillRectangle(int x, int y, int width, int height) = 0;

		/**
		 * @brief	Draw a string to the screen
		 * 
		 * @param	int 			x
		 * @param	int 			y
		 * @param	const char*		String to draw
		 */
		virtual void drawString(int x, int y, const char* message) = 0;

		/**
		 * @brief	Draw a string to the screen
		 * 
		 * @param	int 			x
		 * @param	int 			y
		 * @param	std::string&	String to draw
		 */
		virtual void drawString(int x, int y, const std::string& message) = 0;

		/**
		 * @brief	Clear the sprite
		 */
		virtual void clear() = 0;

		/**
		 * @brief	Set the color of the foreground
		 * 
		 * @param	const char*		color name
		 */
		virtual void setColor(const char* color_name) = 0;

		/**
		 * @brief	Draw the sprite onto the passed window, at the specified location
		 * 
		 * @param	int 	x
		 * @param	int 	y
		 * @param	Window	destination
		 */
		virtual void draw(int x, int y, Window destination) = 0;

		/**
		 * 	@brief	Destructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.0
		 */
		virtual ~Sprite();
};

#endif