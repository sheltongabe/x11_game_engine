/**
 *  @file	font_sprite.h
 *  @brief	Implement a font display
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-14-2018
 *  @version	0.1
 */

#ifndef FONT_SPRITE_H
#define FONT_SPRITE_H

#include "base_sprite.h"

/**
 * 	@class		FontSprite
 * 	@brief		Add Font capabilities to the standard BaseSprite toolkit.
 * 
 */
class FontSprite : public BaseSprite {
	public:
		/**
		 * @brief	Initialize a BaseSprite, and load the font
		 * 
		 * The Parameters are passed to BaseSprite
		 * 
		 * @param 	Display*	connection
		 * @param	uint		width
		 * @param	uint		height
		 * @version	0.0
		 */
		FontSprite(Display* display, unsigned int width, unsigned int height);
		FontSprite() = delete;
		FontSprite(FontSprite& copy) = delete;
		FontSprite(FontSprite&& move) = delete;

		/// Get the text the sprite will draw
		std::string getText() { return this->text; }

		/// store a new text in the sprite
		void setText(std::string text) { this->text = text; }

		/**
		 * 	@brief	Destructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.0
		 */
		virtual ~FontSprite();

	protected:
		/// The text to display on the sprite
		std::string text;

		/// The Font settings
		Font font;

	private:

};

#endif