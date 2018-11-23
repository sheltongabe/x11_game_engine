/**
 *  @file	title_screen.h
 *  @brief	Implement the title Scene for Pong
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-23-2018
 *  @version	0.1
 */

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "x11_game_engine/scene.h"

/**
 * 	@class		TitleScreen
 * 	@brief		Extend Scene to serve as the starting Scene for Pong
 */
class TitleScene : public Scene {
	public:
		/**
		 * @brief	Call Parent Class to setup Scene
		 */
		TitleScene(Game* game, const char* name, const char* title,
				unsigned int width, unsigned int height);

		TitleScene() = delete;
		TitleScene(TitleScene& copy) = delete;
		TitleScene(TitleScene&& move) = delete;

		/**
		 * 	@brief	Destructor
		 */
		~TitleScene();

	private:

};

#endif