/**
 *  @file	x_screen.h
 *  @brief	Provide the implementation of showing a blank window on the screen
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-06-2018
 *  @version	0.1
 */

#ifndef XSCREEN_H
#define XSCREEN_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>

/**
 * 	@class		XScreen
 * 	@brief		Show a blank window on the screen
 */
class XScreen {
	public:
		/**
		 * @brief	Create a default window
		 * 
		 * - Open a display and map a default window to it, 
		 *   to serve as the primary screen.	
		 * 
		 * @version	0.1
		 */
		XScreen(const char* name, const char* title,
			unsigned int width, unsigned int height);

		// Delete the Default, Move, and copy constructors
		XScreen() = delete;
		XScreen(XScreen& copy) = delete;
		XScreen(XScreen&& screen) = delete;

		/**
		 * @brief	Remove pending events from the queue
		 * 
		 * @version	0.1
		 */
		void flushEvents();

		/**
		 * 	@brief	Destructor
		 * 	@version	0.1
		 */
		~XScreen();

	protected:
		/// Display to connect to
		Display* xDisplay;
		int screen;

		/// Window to draw on
		Window mainWindow;

		/// Width and height of the window
		unsigned int width, height;

		// Graphics Context
		GC graphicsContext;
		XGCValues gc_values;
};

#endif