/**
 *  @file	game.cpp
 *  @brief	Implement the Game class and main loop
 * 
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-08-2018
 *  @version	0.1
 */

#include <chrono>
#include <thread>
#include <stdexcept>

#include "game.h"
#include "image_sprite.h"
#include "font_sprite.h"

//
// Initializing constructor
//
Game::Game(const char* name, const char* title, int width, int height) :
		name(std::string(name)),
		title(std::string(title)),
		width(width),
		height(height),
		isRunning(true),
		lastFPS(0),
		currentScene(nullptr),
		scenes(std::unordered_map<std::string, Scene*>()) {
	// Initialize the X11 server
	XDisplay::get();
	this->xScreen = new XScreen(name, title, width, height);
	
	// s3 = new ImageSprite("test.xbm", XDisplay::getDisplay(), this->xScreen->getWindow());
	
	// Call Load
	this->load();

	// Begin the main loop
	this->mainLoop();
}

// 
// load ()
//
void Game::load() {
	// Get the start scene, and set it to current
	this->addScene("start", this->getStartScene());
	this->currentScene = this->getScene("start");
}

//
// update (double)
//
void Game::update(double percentTimeElapsed) {
	this->currentScene->update(percentTimeElapsed);
}

// 
// render (Window)
//
void Game::render() {
	this->currentScene->render();

	this->frameRateSprite->clear();
	this->frameRateSprite->setColor("black");
	this->frameRateSprite->drawString(0, 10, std::string("FPS: ") + std::to_string(this->lastFPS));
	this->frameRateSprite->draw(700, 10, window);
}

// 
// sceneExists (std::string name) -> bool
//
bool Game::sceneExists(std::string name) {
	// check to make sure the scene index does not contain that name already
	auto sceneIndex = this->scenes;
	return sceneIndex.find(name) != sceneIndex.end();
}

// 
// addScene(std::string, Scene*)
//
void Game::addScene(std::string name, Scene* scene) {
	// if it the scene exists, delete that scene and then add ours
	if(this->sceneExists(name))
		delete this->scenes[name];
	
	// Add the newScene to the map of scenes
	this->scenes[name] = scene;
}

// 
// getScene (std::string) -> Scene*
//
Scene* Game::getScene(std::string name) {
	// If the Scene exists return it, otherwise throw an exception
	if(this->sceneExists(name))
		return this->scenes[name];
	else
		throw std::runtime_error(std::string("A Scene does not exist with the name of: ") + name);
}

// 
// removeScene (std::string)
//
void Game::removeScene(std::string name) {
	// If the Scene exists in the index delete and remove it, otherwise throw an exception
	if(this->sceneExists(name)) {
		// Grab, delete, and erase the scene
		auto scene = this->scenes.find(name);
		delete (scene->second);
		this->scenes.erase(scene);
	}
	else {
		throw std::runtime_error(std::string("A Scene does not exist with the name of: ") + name);
	}
}

// 
// endGame()
//
void Game::endGame() {
	this->isRunning = false;
}

// 
// mainLoop ()
//
void Game::mainLoop() {
	// Lambda expression for getting current time in nanoseconds
	auto currentTimeInNano = []() {
		return std::chrono::high_resolution_clock::now();
	};

	auto initialTime = currentTimeInNano();
	auto endTime = currentTimeInNano();
	double oneSecondInNano = 1 * 1000 * 1000 * 1000;
	std::chrono::duration<double, std::nano> targetTime(oneSecondInNano / this->TARGET_FPS);

	int frameCounter = 0;
	double timeSinceLastFrameLog = 0.0;

	while(this->isRunning) {
		endTime = currentTimeInNano();
		//this->xScreen->flushEvents();
		this->internalProcessEvents();
		
		// Calculate the elapsed time, call update and render, and then sleep for the remaining time
		std::chrono::duration<double, std::nano> elapsed = endTime - initialTime;
		this->update(elapsed.count() / targetTime.count());
		this->render();
		std::this_thread::sleep_for(targetTime - elapsed);

		// Frame rate calculations
		timeSinceLastFrameLog += (currentTimeInNano() - initialTime).count();
		++frameCounter;
		if(timeSinceLastFrameLog > oneSecondInNano) {
			timeSinceLastFrameLog = 0.0;
			this->lastFPS = frameCounter;
			frameCounter = 0;
		}
		initialTime = currentTimeInNano();
	}
}

// 
// internalProcessEvents ()
//
void Game::internalProcessEvents() {
	auto display = XDisplay::getDisplay();
	
	// Process Game / System level events
	// TODO delegate game events (keyboard, mouse, etc... to an event Queue)
	while(XPending(display) > 0) {
		// Grab and store the next event
		XEvent e;
		XNextEvent(display, &e);

		// Take a particular action
		switch(e.type) {
			case Expose:
				this->currentScene->render();
				break;
			
			case ClientMessage:
				if(e.xclient.data.l[0] == XDisplay::getWMDeleteMessage())
					this->endGame();
				break;
		}
	}
}

//
// Destructor 
//
Game::~Game() {
	delete this->xScreen;
	delete XDisplay::get();
}