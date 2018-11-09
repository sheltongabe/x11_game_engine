/**
 *  @file	x_display.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-08-2018
 *  @version	0.0
 */

#include <stdexcept>

#include "x_display.h"

XDisplay* XDisplay::singleton = nullptr;

//
// Default Constructor
//
XDisplay::XDisplay() {
	// Connect to x11 server
	if((this->display = XOpenDisplay(nullptr)) == nullptr)
		throw std::domain_error("Could not open display.");
	
	this->screen = XDefaultScreen(this->display);
	this->root_window = RootWindow(this->display, this->screen);
	this->cmap = DefaultColormap(this->display, this->screen);
}

// 
// get() : XDisplay*
//
XDisplay* XDisplay::get() {
	if(singleton == nullptr)
		singleton = new XDisplay();
	
	return singleton;
}

// 
// getDisplay() : Display*
//
Display* XDisplay::getDisplay() {
	return XDisplay::get()->display;
}

// 
// getScreen() : int
//
int XDisplay::getScreen() {
	return XDisplay::get()->screen;
}

// 
// getRootWindow() : Window
//
Window XDisplay::getRootWindow() {
	return XDisplay::get()->root_window;
}

// 
// getColormap() : Colormap
//
Colormap XDisplay::getColormap() {
	return XDisplay::get()->cmap;
}

// 
// getColor(const char*) : unsigned long
//
unsigned long XDisplay::getColor(const char* color_name) {
	unsigned long pixel = 0;

	// Check if the color has been requested before
	auto colors = XDisplay::getColors();
	auto color = colors.find(std::string(color_name));
	if(color == colors.end()) {
		// The Color has not been requested before
		// we need to build it.
		XColor color;
		XParseColor(XDisplay::getDisplay(), XDisplay::getColormap(),
				color_name, &color);
		XAllocColor(XDisplay::getDisplay(), XDisplay::getColormap(), &color);
		pixel = color.pixel;
		colors[std::string(color_name)] = pixel;
	}
	else {
		// The color was requested before so just return its pixel value
		pixel = colors[std::string(color_name)];
	}
		
	return pixel;
}

std::unordered_map<std::string, unsigned long> XDisplay::getColors() {
	return XDisplay::get()->colors;
}

//
// Destructor 
//
XDisplay::~XDisplay() {
	// Free Colors
	auto colors = XDisplay::getColors();
	unsigned long pixels[colors.size()];
	int index = 0;
	for(const auto& pixel : colors) {
		pixels[index] = pixel.second;
		++index;
	}
	XFreeColors(this->display, this->cmap, pixels, colors.size(), (unsigned long)0);
	XFreeColormap(this->display, this->cmap);
	XCloseDisplay(this->display);
}