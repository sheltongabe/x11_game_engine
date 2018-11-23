/**
 *  @file	font_sprite.cpp
 *  @brief	Implement the FontSprite Class
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-14-2018
 *  @version	0.1
 */

#include "font_sprite.h"

//
// Initialize by calling into BaseSprite, and then building the font
//
FontSprite::FontSprite(Display* display, unsigned int width, unsigned int height) :
		BaseSprite::BaseSprite(display, width, height),
		font(XLoadFont(display, "fixed")) {
	XSetFont(display, this->graphicsContext, this->font);
}

// 
// clone () -> Sprite*
//
Sprite* FontSprite::clone() {
	FontSprite* clone = new FontSprite(XDisplay::getDisplay(), this->width, this->height);
	this->draw(0, 0, clone->image);
	clone->text = this->text;
	return clone;
}

//
// Destructor 
//
FontSprite::~FontSprite() {
	XUnloadFont(XDisplay::getDisplay(), this->font);
}