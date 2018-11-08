/**
 *  @file	x_screen.cpp
 *  @brief	implement XScreen
 * 
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-06-2018
 *  @version	0.1
 */

#include "x_screen.h"
#include "sprite.h"
#include <stdexcept>

//
// Main Constructor
//
XScreen::XScreen(const char* name, const char* title,
		unsigned int width, unsigned int height) :
		width(width),
		height(height){
	// Connect to display
	if((this->xDisplay = XOpenDisplay(nullptr)) == nullptr)
		throw std::domain_error("Could not open Display");
	
	// Connection was successful so lets setup the screen and mainWindow
	this->screen = XDefaultScreen(this->xDisplay);
	this->mainWindow = XCreateSimpleWindow(this->xDisplay,
			RootWindow(this->xDisplay, this->screen), 0, 0,
			this->width, this->height, 5, 
			BlackPixel(this->xDisplay, this->screen),
			WhitePixel(this->xDisplay, this->screen));
	
	this->graphicsContext = XCreateGC(this->xDisplay, this->mainWindow,
			(unsigned int)0, &gc_values);
	XSetForeground(this->xDisplay, this->graphicsContext,
			BlackPixel(this->xDisplay, this->screen));
	XSetStandardProperties(this->xDisplay, this->mainWindow,
			name, title, None, 0, 0, nullptr);
	XSelectInput(this->xDisplay, this->mainWindow, NoEventMask);

	XClearWindow(this->xDisplay, this->mainWindow);
	XRaiseWindow(this->xDisplay, this->mainWindow);
	XMapWindow(this->xDisplay, this->mainWindow);

	Sprite s(this->xDisplay, 30, 30);
	s.setColor("blue");
}

//
// Flush Events
//
void XScreen::flushEvents() {
	XFlush(this->xDisplay);
}

//
// Destructor 
//
XScreen::~XScreen() {
	XDestroyWindow(this->xDisplay, this->mainWindow);
	XFreeGC(this->xDisplay, this->graphicsContext);
	XCloseDisplay(this->xDisplay);
}