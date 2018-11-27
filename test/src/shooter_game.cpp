/**
 * @file	shooter_game.cpp
 * @brief	Implement the methods needed for the Shooter_Game game
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	11-27-2018
 * @version	0.2
 */

#include "shooter_game.h"
#include "title_scene.h"

// 
// Initialize Shooter_Game Game
//
ShooterGame::ShooterGame(const char* name, const char* title, int width, int height) : 
		Game(name, title, width, height) {
	this->load();
}

// 
// load ()
//
void ShooterGame::load() {
	Game::load();
}

// 
// getStartScene () -> Scene*
//
Scene* ShooterGame::getStartScene() {
	return new TitleScene(this, name.c_str(), title.c_str(), width, height);
}

//
// Destructor 
//
ShooterGame::~ShooterGame() {

}