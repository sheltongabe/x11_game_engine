/**
 *  @file	sprite.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-06-2018
 *  @version	0.0
 */

#include "sprite.h"

// 
// Initialization Constructor
//
Sprite::Sprite(Display* display, unsigned int width, unsigned int height) :
		xDisplay(display),
		width(width),
		height(height) {
	// Create image
	int defaultScreen = XDefaultScreen(this->xDisplay);
	this->image = XCreatePixmap(this->xDisplay, RootWindow(this->xDisplay, defaultScreen), 
			this->width, this->height, DefaultDepth(this->xDisplay, defaultScreen));

	// Create Graphics context
	XGCValues values;
	this->graphicsContext = XCreateGC(this->xDisplay, this->image, (unsigned long)0, &values);
}

//
// Copy Constructor
//
Sprite::Sprite(Sprite& copy) {

}

//
// Destructor 
//
Sprite::~Sprite() {
	XFreePixmap(this->xDisplay, this->image);
	XFreeGC(this->xDisplay, this->graphicsContext);
}