/**
 *  @file	x_display.h
 *  @brief	Handle a connection to the x11 server
 *  
 * 	- A singleton class that will store:
 *    the connection, colormap, rootwindow, ect...
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-08-2018
 *  @version	0.1
 */

#ifndef XDISPLAY_H
#define XDISPLAY_H

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unordered_map>

/**
 * 	@class		XDisplay
 * 	@brief		A Singleton class that handles a X11 connection
 */
class XDisplay {
 
	public:
		XDisplay(XDisplay& copy) = delete;
		XDisplay(XDisplay&& move) = delete;

		/**
		 * @brief	Build the instance if needed, otherwise return it
		 * @return	XDisplay*	singleton XDisplay
		 */
		static XDisplay* get();

		/**
		 * @brief	return the display connection
		 * @return	Display* 	connection to x11 server
		 */
		static Display* getDisplay();

		/**
		 * @brief	return the screen, which is setup as the default screen
		 * @return 	int		default screen
		 */
		static int getScreen();

		/**
		 * @brief	return the root window for the connection and screen
		 * @return	Window	the root window
		 */
		static Window getRootWindow();

		/**
		 * @brief	get the colormap that is linked with the server
		 * @return 	Colormap 	cmap linked with server
		 */
		static Colormap getColormap();

		/**
		 * @brief	Lookup a color by name, and return its pixel
		 * @return	unsigned long	pixel value
		 */
		static unsigned long getColor(const char* color_name);

		/**
		 * @brief	Get the unordered map of colors
		 * @return	unordered map of pixels	
		 */
		static std::unordered_map<std::string, unsigned long> getColors();

		/**
		 * 	@brief		Free resources and close connection
		 * 	@version	0.1
		 */
		~XDisplay();

	private:
		/**
		 * 	@brief	Initialize the connection and connection variables
		 * 	@version	0.1
		 */
		XDisplay();

		/// Singleton point of access to the instance variables
		static XDisplay* singleton;

		/// X11 Display connection
		Display* display;

		/// X11 screen, configured to default screen
		int screen;

		/// Root window for this display and screen
		Window root_window;

		/// Colormap for this X11 connection
		Colormap cmap;

		/// map of colors
		std::unordered_map<std::string, unsigned long> colors;
};

#endif