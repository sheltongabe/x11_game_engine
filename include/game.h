/**
 *  @file	game.h
 *  @brief	Implement the main game loop and keep hold the screen.
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-08-2018
 *  @version	0.1
 */

#ifndef GAME_H
#define GAME_H

#include "x_screen.h"
#include "x_display.h"
#include "sprite.h"

/**
 * 	@class		Game
 * 	@brief		Contains the main loop and is designed to be extended by users
 */
class Game {
	public:
		/**
		 * 	@brief	Default Constructor (initialize the connection to the x11 server)
		 * 	@version	0.1
		 */
		Game(const char* name, const char* title, int width, int height);
		Game() = delete;
		Game(Game& copy) = delete;
		Game(Game&& move) = delete;

		void mainLoop();

		virtual void update() { }

		virtual void render() { };

		/**
		 * 	@brief	Destructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.0
		 */
		~Game();

	protected:
		/// The screen to display on
		XScreen* xScreen;

		/// Is the game still running
		bool isRunning;

		/// Should the game be paused
		bool isPaused;

		// Dimensions of the game
		int width, height;

		// Name and title
		std::string name, title;

	private:
		/// Target FPS for the game loop
		const static int TARGET_FPS = 30;
};

#endif