/**
 *  @file	smiley_actor.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-23-2018
 *  @version	0.0
 */

#include "smiley_actor.h"
#include "x11_game_engine/image_sprite.h"
#include "x11_game_engine/x_display.h"
#include "test.xpm"

//
// Default Constructor
//
SmileyActor::SmileyActor() : 
		DynamicActor(){
	this->load();
}

// 
// load ()
//
void SmileyActor::load() {
	this->transformedSprite = new ImageSprite(test_xpm,
			XDisplay::getDisplay(), XDisplay::getRootWindow());
}

//
// Destructor 
//
SmileyActor::~SmileyActor() {

}