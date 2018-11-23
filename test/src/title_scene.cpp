/**
 *  @file	title_screen.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-23-2018
 *  @version	0.0
 */

#include "title_scene.h"

// 
// Initialize the Scene
//
TitleScene::TitleScene(Game* game, const char* name, const char* title, 
		unsigned int width, unsigned int height) :
		Scene(game, name, title, width, height) {

}

//
// Destructor 
//
TitleScene::~TitleScene() {

}