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

#include <string.h>
#include <stdexcept>

#include "sprite.h"

// 
// Initialization Constructor of a blank sprite
//
Sprite::Sprite(Display* display, unsigned int width, unsigned int height) :
		xDisplay(display),
		width(width),
		height(height) {
	// Create image
	int defaultScreen = XDisplay::getScreen();
	this->image = XCreatePixmap(display, XDisplay::getRootWindow(), 
			this->width, this->height, DefaultDepth(display, defaultScreen));

	// Create Graphics context
	XGCValues values;
	this->graphicsContext = XCreateGC(this->xDisplay, this->image, (unsigned long)0, &values);

	this->setColor("white");
	this->fillRectangle(0, 0, this->width, this->height);
}

//
// Initalization constructor for a sprite that loads from a file
//
Sprite::Sprite(Display* display, Window d, const char* filename) :
		xDisplay(display) {
	// Return values for loading the file
	int x_hot, y_hot;
	int status = XReadBitmapFile(display, d, filename, 
			&(this->width), &(this->height), &(this->image),
			&x_hot, &y_hot);
	if(status != BitmapSuccess)
		throw std::runtime_error(std::string("Image file unable to load") +
				std::string(filename));

	// Create Graphics context
	XGCValues values;
	this->graphicsContext = XCreateGC(this->xDisplay, this->image, (unsigned long)0, &values);
}

// 
// Initialize with a string filename
//
Sprite::Sprite(Display* display, Window w, std::string filename) :
		Sprite(display, w, filename.c_str()) {
	// Delegates to the constructor that works with c-strings
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
	XDrawPoint(XDisplay::getDisplay(), this->image,
			this->graphicsContext, x, y);
}

// 
// drawLine(int, int, int, int)
//
void Sprite::drawLine(int x1, int y1, int x2, int y2) {
	XDrawLine(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x1, y1, x2, y2);
}

// 
// drawRectangle(int, int, int, int)
//
void Sprite::drawRectangle(int x, int y, int width, int height) {
	XDrawRectangle(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x, y, width, height);
}

// 
// fillRectangle(int, int, int, int)
//
void Sprite::fillRectangle(int x, int y, int width, int height) {
	XFillRectangle(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x, y, width, height);
}

// 
// drawString(int, int, const char*)
//
void Sprite::drawString(int x, int y, const char* message) {
	XDrawString(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x, y, message, strlen(message));
}
// 
// drawString(int, int, const std::string&)
//
void Sprite::drawString(int x, int y, const std::string& message) {
	Sprite::drawString(x, y, message.c_str());
}

// 
// setColor(const char*)
//
void Sprite::setColor(const char* color_name) {
	unsigned long color = XDisplay::getColor(color_name);
	XSetForeground(this->xDisplay, this->graphicsContext, color);
}

// 
// draw (int, int, Window)
//
void Sprite::draw(int x, int y, Window destination) {
	XCopyArea(XDisplay::getDisplay(), this->image,
			destination, this->graphicsContext, 0, 0,
			this->width, this->height, x, y);
}

//
// Destructor 
//
Sprite::~Sprite() {
	XFreePixmap(this->xDisplay, this->image);
	XFreeGC(this->xDisplay, this->graphicsContext);
}