/**
 *  @file	pong.h
 *  @brief	Extend x11_game_engine's Game class to handle the Pong Game
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-23-2018
 *  @version	0.1
 */

#ifndef PONG_H
#define PONG_H

#include "x11_game_engine/game.h"
#include "x11_game_engine/scene.h"

/**
 * 	@class		Pong
 * 	@brief		Handle startup for the Pong game and running the main loop
 */
class Pong : public Game {
	public:
		/**
		 * 	@brief	Delegate variable initialization to the Game Constructor
		 */
		Pong(const char* name, const char* title, int width, int height);
		
		Pong() = delete;
		Pong(Pong& copy) = delete;
		Pong(Pong&& move) = delete;

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
		~Pong();

	private:

};

#endif