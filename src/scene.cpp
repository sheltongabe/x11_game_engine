/**
 *  @file	scene.cpp
 *  @brief	Provide a minimal implementation for Scene class
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-16-2018
 *  @version	0.1
 */

#include <algorithm>

#include "scene.h"

//
// Initializing Constructor for XScreen and Scene
//
Scene::Scene(Game* game, const char* name, const char* title, unsigned int width, unsigned int height) :
		XScreen(name, title, width, height),
		game(game),
		isScenePaused(false),
		actors(std::unordered_map<std::string, Actor*>()) {
	// Load the Scene
	this->load();
}

// 
// load ()
//
void Scene::load() {

}

// 
// update (double)
//
void Scene::update(double percentElapsedTime) {
	if(!this->isScenePaused) {
		// call update on each actor
		std::for_each(this->actors.begin(), this->actors.end(), [] (auto& it) {
			it->second->update(percentElapsedTime);
		});

		// TODO: Possible process collisions
	}
}

// 
// render
//
void Scene::render() {
	// Call render on each actor
	std::for_each(this->actors.begin(), this->actors.end(), [&] (auto& it) {
		it->second->render(this->mainWindow);
	});
}

// 
// show ()
//
void Scene::show() {
	XScreen::show();
}

// 
// hide ()
//
void Scene::hide() {
	XScreen::hide();
}

// 
// isPaused () -> bool
//
bool Scene::isPaused() {
	return this->isScenePaused;
}

// 
// pause ()
//
void Scene::pause() {
	this->isScenePaused = true;
}

// 
// play ()
//
void Scene::play() {
	this->isScenePaused = false;
}

//
// Destructor 
//
Scene::~Scene() {

}