/**
 *  @file	base_sprite.h
 *  @brief	Provide a base implementation for a sprite, drawing onto a pixmap only really
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-14-2018
 *  @version	0.1
 */

#ifndef BASE_SPRITE_H
#define BASE_SPRITE_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string.h>

#include "sprite.h"

/**
 * 	@class		BaseSprite
 * 	@brief		Define the base details of a sprite, and base operations that can be done
 */
class BaseSprite : public Sprite {
	public:
		/**
		 * @brief	Initializing constructor
		 * 
		 * Provide the width, height and reference to the display
		 * 
		 * @param	Display*		Display
		 * @param	uint			width
		 * @param	uint			height
		 */
		BaseSprite(Display* display, unsigned int width, unsigned int height);
		BaseSprite() = delete;
		BaseSprite(BaseSprite& copy) = delete;
		BaseSprite(BaseSprite&& move) = delete;

		// ----- Drawing functions -----
		
		/**
		 * @brief	Draw a single Point (Useful for transormations) using the Foreground settings
		 * 
		 * @param	int 	x
		 * @param	int 	y
		 */
		virtual void drawPoint(int x, int y);

		/**
		 * @brief	Draw a line from point 1 to point 2, using foreground settings on the gc
		 * 
		 * @param	int		x1
		 * @param	int		y1
		 * @param	int		x2
		 * @param	int		y2
		 */
		virtual void drawLine(int x1, int y1, int x2, int y2);

		/**
		 * @brief	Draw a rectangle using the foreground settings
		 * 
		 * @param	int		x
		 * @param	int		y
		 * @param	int		width
		 * @param	int		heigh
		 */
		virtual void drawRectangle(int x, int y, int width, int height);

		/**
		 * @brief	Draw and fill a rectangle using the foreground settings
		 * 
		 * @param	int		x
		 * @param	int		y
		 * @param	int		width
		 * @param	int		heigh
		 */
		virtual void fillRectangle(int x, int y, int width, int height);

		/**
		 * @brief	Draw a string to the screen
		 * 
		 * @param	int 			x
		 * @param	int 			y
		 * @param	const char*		String to draw
		 */
		virtual void drawString(int x, int y, const char* message);

		/**
		 * @brief	Draw a string to the screen
		 * 
		 * @param	int 			x
		 * @param	int 			y
		 * @param	std::string&	String to draw
		 */
		virtual void drawString(int x, int y, const std::string& message);

		/**
		 * @brief	Clear the sprite
		 */
		virtual void clear();

		/**
		 * @brief	Set the color of the foreground
		 * 
		 * @param	const char*		color name
		 */
		virtual void setColor(const char* color_name);

		/**
		 * @brief	Draw the sprite onto the passed window, at the specified location
		 * 
		 * @param	int 	x
		 * @param	int 	y
		 * @param	Window	destination
		 */
		virtual void draw(int x, int y, Window destination);

		/**
		 * 	@brief	Destructor
		 */
		virtual ~BaseSprite();

	protected:
		/// Image that will be drawn
		Pixmap image;

		/// Graphics settings for drawing with the image
		GC graphicsContext;

	private:

};

#endif