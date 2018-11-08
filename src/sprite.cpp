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
	this->cmap = DefaultColormap(display, defaultScreen);
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
// drawPoint (int, int)
//
void Sprite::drawPoint(int x, int y) {

}

// 
// drawLine(int, int, int, int)
//
void Sprite::drawLine(int x1, int y1, int x2, int y2) {

}

// 
// drawRectangle(int, int, int, int)
//
void Sprite::drawRectangle(int x, int y, int width, int height) {

}

// 
// fillRectangle(int, int, int, int)
//
void Sprite::fillRectangle(int x, int y, int width, int height) {

}

// 
// drawString(int, int, const char*)
//
void Sprite::drawString(int x, int y, const char* message) {

}
// 
// drawString(int, int, const std::string&)
//
void Sprite::drawString(int x, int y, const std::string& message) {

}

// 
// setColor(const char*)
//
void Sprite::setColor(const char* color_name) {
	XColor color;
	XParseColor(this->xDisplay, this->cmap, color_name, &color);
	XAllocColor(this->xDisplay, this->cmap, &color);
	XSetForeground(this->xDisplay, this->graphicsContext, color.pixel);
}

//
// Destructor 
//
Sprite::~Sprite() {
	XFreePixmap(this->xDisplay, this->image);
	XFreeGC(this->xDisplay, this->graphicsContext);
	XFreeColormap(this->xDisplay, this->cmap);
}