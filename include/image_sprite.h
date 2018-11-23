/**
 *  @file	image_sprite.h
 *  @brief	Provide an implementation for a sprite holding an image
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-14-2018
 *  @version	0.1
 */

#ifndef IMAGE_SPRITE_H
#define IMAGE_SPRITE_H

#include "base_sprite.h"

/**
 * 	@class		ImageSprite
 * 	@brief		Hold and display an image
 */
class ImageSprite : public BaseSprite {
	public:
		/**
		 * Load the image and initialize the properties of BaseSprite
		 * 
		 * @param	char**			image data
		 * @param	Display*		display
		 * @param	Window			A window to get the screen / display associated
		 * @throw	runtime_error	file not able to be loaded
		 */
		ImageSprite(const char** imageData, Display* display, Window window);

		ImageSprite() = delete;
		ImageSprite(ImageSprite& copy) = delete;
		ImageSprite(ImageSprite&& move) = delete;

		/// Overload for drawing images
		virtual void draw(int x, int y, Drawable destination);

		/**
		 * @brief	Duplicate the properties of this Sprite and copy the image onto a new Pixmap
		 * 
		 * @return	Sprite* 	Clone of this sprite, caller is responsible for deletion
		 */
		virtual Sprite* clone();

		virtual ~ImageSprite();

	protected:
		const char** imageData;

	private:

};

#endif