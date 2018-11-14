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


		/**
		 * @brief	Temporarily implemented but will be pure virtual, where all of the game logic is updated
		 * TODO 	Remove implementation
		 * @param	double		Proportion of the targetTime that was filled
		 */
		virtual void update(double percentTimeElapsed);

		/**
		 * @brief	Temporarilly implemented but will be pure virtual, where the actors / sprites are actually displayed.
		 * TODO		Remove Implementation
		 * @param	Window		Window to draw on
		 */
		virtual void render(Window window);

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
		const static int TARGET_FPS = 60;

		Sprite* frameRateSprite;
		Sprite* s, *s3;
		int lastFPS;

		/**
		 * @brief	Hidden main event loop, designed to run on the xScreen that is current, and populate a queue of events
		 */
		void internalProcessEvents();
};

#endif