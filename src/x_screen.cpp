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
	XSelectInput(display, this->mainWindow, ExposureMask);
	auto wmDelete = XDisplay::getWMDeleteMessage();
	XSetWMProtocols(display, this->mainWindow, &wmDelete, 1);

	XClearWindow(display, this->mainWindow);
	XRaiseWindow(display, this->mainWindow);
	XMapWindow(display, this->mainWindow);
}

//
// Flush Events
//
void XScreen::flushEvents() {
	auto display = XDisplay::getDisplay();

	// Clear all the pending events
	while(XPending(display) > 0) {
		XEvent e;
		XNextEvent(display, &e);
	}
}

//
// Destructor 
//
XScreen::~XScreen() {
	auto display = XDisplay::getDisplay();
	XDestroyWindow(display, this->mainWindow);
	XFreeGC(display, this->graphicsContext);
}