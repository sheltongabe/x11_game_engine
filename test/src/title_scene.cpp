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
#include "smiley_actor.h"

// 
// Initialize the Scene
//
TitleScene::TitleScene(Game* game, const char* name, const char* title, 
		unsigned int width, unsigned int height) :
		Scene(game, name, title, width, height) {
	this->load();
}

// 
// load ()
//
void TitleScene::load() {
	DynamicActor* a = new SmileyActor();
	a->setPosition(Vector2D(150, 150));
	a->setVelocity(Vector2D(30, 30));
	a->setBoundsAction(BOUNCE);
	this->actors["image"] = a;
}

//
// Destructor 
//
TitleScene::~TitleScene() {

}