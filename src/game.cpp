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
		isPaused(false),
		s(new BaseSprite(XDisplay::getDisplay(), 30, 30)),
		frameRateSprite(new FontSprite(XDisplay::getDisplay(), 100, 20)),
		lastFPS(0){
	// Initialize the X11 server
	XDisplay::get();
	this->xScreen = new XScreen(name, title, width, height);
	
	// s3 = new ImageSprite("test.xbm", XDisplay::getDisplay(), this->xScreen->getWindow());

	// Begin the main loop
	this->mainLoop();
}
#include <iostream>
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
		
		std::chrono::duration<double, std::nano> elapsed = endTime - initialTime;
		this->update(elapsed.count() / targetTime.count());
		this->render(this->xScreen->getWindow());
		
		std::this_thread::sleep_for(targetTime - elapsed);

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
// update (double)
//
void Game::update(double percentTimeElapsed) {
	((FontSprite*)this->frameRateSprite)->setText(
			std::string("FPS: ") + std::to_string(this->lastFPS));
}

// 
// render (Window)
//
void Game::render(Window window) {
	this->s->setColor("black");
	this->s->drawLine(0, 0, 30, 30);
	this->s->draw(0, 0, window);

	// this->s3->draw(400, 300, window);

	this->frameRateSprite->clear();
	this->frameRateSprite->setColor("black");
	this->frameRateSprite->drawString(0, 10, std::string("FPS: ") + std::to_string(this->lastFPS));
	this->frameRateSprite->draw(700, 10, window);
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

				break;
			
			case ClientMessage:
				if(e.xclient.data.l[0] == XDisplay::getWMDeleteMessage())
					this->isRunning = false;
				break;
		}
	}
}

//
// Destructor 
//
Game::~Game() {
	delete this->xScreen;
	delete this->s;
	// delete this->s3;
	delete this->frameRateSprite;
	delete XDisplay::get();
}