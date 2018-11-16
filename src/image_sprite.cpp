/**
 *  @file	image_sprite.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-14-2018
 *  @version	0.0
 */

#include "image_sprite.h"

//
// Load and initialize values of base sprite
//
ImageSprite::ImageSprite(const char* filename, Display* display, Window window) :
		BaseSprite(display, 1, 1) {
	// Free the blank pixmap
	XFreePixmap(display, this->image);
	// XFreeGC(display, this->graphicsContext);

	// Load the image
	int x_hot, y_hot;
	int status = XReadBitmapFile(display, window, filename, 
			&(this->width), &(this->height), &(this->image),
			&x_hot, &y_hot);
	if(status != BitmapSuccess)
		throw std::runtime_error(std::string("Image file unable to load") +
				std::string(filename));

	// Setup the Graphics Context
	// XGCValues gc_values;
	// this->graphicsContext = XCreateGC(display, this->image, (unsigned long)0, &gc_values);
}

//
// Overload of Consutructor for std::string
//
ImageSprite::ImageSprite(std::string filename, Display* display, Window window) : 
		ImageSprite(filename.c_str(), display, window) {

}

// 
// draw
//
void ImageSprite::draw(int x, int y, Window destination) {
	XCopyPlane(XDisplay::getDisplay(), this->image, destination, this->graphicsContext,
			0, 0, this->width, this->height, x, y, 1);
}

//
// Destructor 
//
ImageSprite::~ImageSprite() {
	BaseSprite::~BaseSprite();
}