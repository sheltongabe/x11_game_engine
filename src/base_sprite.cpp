/**
 *  @file	base_sprite.cpp
 *  @brief	BaseSprite's implementation
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-14-2018
 *  @version	0.1
 */

#include "base_sprite.h"
#include "x_display.h"

//
// Initializing Constructor
//
BaseSprite::BaseSprite(Display* display, unsigned int width, unsigned int height) :
		Sprite::Sprite() {
	this->width = width;
	this->height = height;
	// Build the image
	auto screen = XDisplay::getScreen();
	this->image = XCreatePixmap(display, XDisplay::getRootWindow(), 
			width, height, XDefaultDepth(display, screen));
	
	// Setup the Graphics Context
	XGCValues gc_values;
	this->graphicsContext = XCreateGC(display, this->image, (unsigned long)0, &gc_values);

	this->clear();
}
// 
// drawPoint (int, int)
//
void BaseSprite::drawPoint(int x, int y) {
	XDrawPoint(XDisplay::getDisplay(), this->image,
			this->graphicsContext, x, y);
}

// 
// drawLine(int, int, int, int)
//
void BaseSprite::drawLine(int x1, int y1, int x2, int y2) {
	XDrawLine(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x1, y1, x2, y2);
}

// 
// drawRectangle(int, int, int, int)
//
void BaseSprite::drawRectangle(int x, int y, int width, int height) {
	XDrawRectangle(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x, y, width, height);
}

// 
// fillRectangle(int, int, int, int)
//
void BaseSprite::fillRectangle(int x, int y, int width, int height) {
	XFillRectangle(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x, y, width, height);
}

// 
// drawString(int, int, const char*)
//
void BaseSprite::drawString(int x, int y, const char* message) {
	XDrawString(XDisplay::getDisplay(), this->image, this->graphicsContext,
			x, y, message, strlen(message));
}
// 
// drawString(int, int, const std::string&)
//
void BaseSprite::drawString(int x, int y, const std::string& message) {
	BaseSprite::drawString(x, y, message.c_str());
}

// 
// clear ()
//
void BaseSprite::clear() {
	this->setColor("white");
	this->fillRectangle(0, 0, this->width, this->height);
}

// 
// setColor(const char*)
//
void BaseSprite::setColor(const char* color_name) {
	unsigned long color = XDisplay::getColor(color_name);
	XSetForeground(XDisplay::getDisplay(), this->graphicsContext, color);
}

// 
// draw (int, int, Window)
//
void BaseSprite::draw(int x, int y, Drawable destination) {
	XCopyArea(XDisplay::getDisplay(), this->image,
			destination, this->graphicsContext, 0, 0,
			this->width, this->height, x, y);
}

// 
// clone () -> Sprite*
//
Sprite* BaseSprite::clone() {
	BaseSprite* clone = new BaseSprite(XDisplay::getDisplay(), this->width, this->height);
	this->draw(0, 0, clone->image);
	return clone;
}

//
// Destructor 
//
BaseSprite::~BaseSprite() {
	auto display = XDisplay::getDisplay();
	XFreeGC(display, this->graphicsContext);
	XFreePixmap(display, this->image);
}