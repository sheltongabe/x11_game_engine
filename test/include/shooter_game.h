/**
 *  @file	shooter_game.h
 *  @brief	Extend x11_game_engine's Game class to handle the ShooterGame Game
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-27-2018
 *  @version	0.2
 */

#ifndef SHOOTER_GAME_H
#define SHOOTER_GAME_H

#include "x11_game_engine/game.h"

/**
 * 	@class		ShooterGame
 * 	@brief		Handle startup for the ShooterGame game and running the main loop
 */
class ShooterGame : public Game {
	public:
		/**
		 * 	@brief	Delegate variable initialization to the Game Constructor
		 */
		ShooterGame(const char* name, const char* title, int width, int height);
		
		ShooterGame() = delete;
		ShooterGame(ShooterGame& copy) = delete;
		ShooterGame(ShooterGame&& move) = delete;

		/**
		 * @brief	Call Game::load()
		 */
		virtual void load();

		/**
		 * @brief	Implement Game::getStartScene(), and return the starting Scene
		 * @return	Scene*	A new TitleScene
		 */
		virtual Scene* getStartScene();

		/**
		 * 	@brief	Destructor
		 */
		~ShooterGame();

	private:

};

#endif