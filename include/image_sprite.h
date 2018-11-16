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
		 * @param	const char*		filename
		 * @param	Display*		display
		 * @param	Window			A window to get the screen / display associated
		 * @throw	runtime_error	file not able to be loaded
		 */
		ImageSprite(const char* filename, Display* display, Window window);

		/**
		 * Load the image and initialize the properties of BaseSprite
		 * 
		 * @param	std::string		filename
		 * @param	Display*		display
		 * @param	Window			A window to get the screen / display associated
		 * @throw	runtime_error	file not able to be loaded
		 */
		ImageSprite(std::string filename, Display* display, Window window);
		ImageSprite() = delete;
		ImageSprite(ImageSprite& copy) = delete;
		ImageSprite(ImageSprite&& move) = delete;

		/// Overload for drawing images
		virtual void draw(int x, int y, Window destination);

		virtual ~ImageSprite();

	protected:


	private:

};

#endif