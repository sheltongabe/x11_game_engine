/**
 *  @file	image_sprite.cpp
 *  @brief	Implement the loading of an image
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-23-2018
 *  @version	0.1
 */

#include <X11/xpm.h>
#include <type_traits>
#include <string>
#include <sstream>

#include "image_sprite.h"

//
// Load and initialize values of base sprite
//
ImageSprite::ImageSprite(const char** imageData, Display* display, Window window) :
		BaseSprite(display, 1, 1),
		imageData(imageData) {
	// Free the blank pixmap
	XFreePixmap(display, this->image);
	XFreeGC(display, this->graphicsContext);

	// Grab the default and screen
	int screen = DefaultScreen(display);

	// Load the image
	Pixmap mask;
	
	// Setup Image attributes
	XpmAttributes image_attributes;
	image_attributes.depth = XDefaultDepth(display, screen);
	image_attributes.colormap = XDisplay::getColormap();
	image_attributes.visual = DefaultVisual(display, screen);
	image_attributes.valuemask = XpmDepth | XpmColormap | XpmVisual;

	int status = XpmCreatePixmapFromData(display, window, const_cast<char**>(imageData), 
			&(this->image), &(mask), &image_attributes);

	// Free the mask if it was created
	if (mask)
		XFreePixmap(display, mask);

	if(status != XpmSuccess)
		throw std::runtime_error(std::string("Image file unable to load"));

	// Setup the Graphics Context
	XGCValues gc_values;
	this->graphicsContext = XCreateGC(display, this->image, (unsigned long)0, &gc_values);

	// TODO: Save the image width and height
	std::stringstream ss;
	ss.flush();
	ss.str(std::string(imageData[0]));

	std::string tmp;
	std::getline(ss, tmp, ' ');
	this->width = std::stoi(tmp);
	std::getline(ss, tmp, ' ');
	this->height = std::stoi(tmp);
}

// 
// draw
//
void ImageSprite::draw(int x, int y, Drawable destination) {
	XCopyArea(XDisplay::getDisplay(), this->image, destination, this->graphicsContext,
			0, 0, this->width, this->height, x, y);
}

// 
// clone () -> Sprite*
//
Sprite* ImageSprite::clone() {
	ImageSprite* clone = new ImageSprite(this->imageData, XDisplay::getDisplay(), XDisplay::getRootWindow());
	this->draw(0, 0, clone->image);
	return clone;
}

//
// Destructor 
//
ImageSprite::~ImageSprite() {

}