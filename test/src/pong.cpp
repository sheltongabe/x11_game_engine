/**
 * @file	pong.cpp
 * @brief	Implement the methods needed for the Pong game
 *  
 * @author	Gabriel Shelton	sheltongabe
 * @date	11-23-2018
 * @version	0.1
 */

#include "pong.h"
#include "title_scene.h"

// 
// Initialize Pong Game
//
Pong::Pong(const char* name, const char* title, int width, int height) : 
		Game(name, title, width, height) {
	this->load();
}

// 
// load ()
//
void Pong::load() {
	Game::load();
}

// 
// getStartScene () -> Scene*
//
Scene* Pong::getStartScene() {
	return new TitleScene(this, name.c_str(), title.c_str(), width, height);
}

//
// Destructor 
//
Pong::~Pong() {

}