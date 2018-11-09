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

//
// Main Constructor
//
XScreen::XScreen(const char* name, const char* title,
		unsigned int width, unsigned int height) :
		width(width),
		height(height){
	// Connect to server and get the display and screen
	Display* display = XDisplay::getDisplay();
	int screen = XDisplay::getScreen();

	// Connection was successful so lets setup the screen and mainWindow
	this->mainWindow = XCreateSimpleWindow(display,
			XDisplay::getRootWindow(), 0, 0,
			this->width, this->height, 5, 
			BlackPixel(display, screen),
			WhitePixel(display, screen));
	
	this->graphicsContext = XCreateGC(display, this->mainWindow,
			(unsigned int)0, &gc_values);
	XSetForeground(display, this->graphicsContext,
			BlackPixel(display, screen));
	XSetStandardProperties(display, this->mainWindow,
			name, title, None, 0, 0, nullptr);
	XSelectInput(display, this->mainWindow, NoEventMask);

	XClearWindow(display, this->mainWindow);
	XRaiseWindow(display, this->mainWindow);
	XMapWindow(display, this->mainWindow);

	Sprite s(display, 30, 30);
	s.setColor("black");
	s.drawLine(0, 0, 30, 30);
	s.draw(0, 0, this->mainWindow);

	//Sprite s2(display, this->mainWindow, "test.xbm");
	//s2.draw(0, 0, this->mainWindow);
}

//
// Flush Events
//
void XScreen::flushEvents() {
	XFlush(XDisplay::getDisplay());
}

//
// Destructor 
//
XScreen::~XScreen() {
	auto display = XDisplay::getDisplay();
	XDestroyWindow(display, this->mainWindow);
	XFreeGC(display, this->graphicsContext);
	delete XDisplay::get();
}