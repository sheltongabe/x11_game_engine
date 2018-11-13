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

//
// Initializing constructor
//
Game::Game(const char* name, const char* title, int width, int height) :
		name(std::string(name)),
		title(std::string(title)),
		width(width),
		height(height),
		isRunning(true),
		isPaused(false) {
	// Initialize the X11 server
	XDisplay::get();
	this->xScreen = new XScreen(name, title, width, height);

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
	std::cout << targetTime.count() << '\n';

	Sprite frameRateSprite(XDisplay::getDisplay(), 50, 30);
	Sprite s(XDisplay::getDisplay(), 30, 30);
	int frameCounter = 0, lastFPS = 0;
	double timeSinceLastFrameLog = 0.0;

	while(this->isRunning) {
		initialTime = currentTimeInNano();

		// Do things

		this->xScreen->flushEvents();
		
		endTime = currentTimeInNano();
		std::chrono::duration<double, std::nano> elapsed = endTime - initialTime;
		
		std::this_thread::sleep_for(targetTime - elapsed);

		timeSinceLastFrameLog += (currentTimeInNano() - initialTime).count();
		++frameCounter;
		if(timeSinceLastFrameLog > oneSecondInNano) {
			std::cout << "FPS: " << lastFPS << '\n';
			timeSinceLastFrameLog = 0.0;
			lastFPS = frameCounter;
			frameCounter = 0;
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

/*
From Game Loop


		s.setColor("black");
		s.drawLine(0, 0, 30, 30);
		s.draw(0, 0, this->xScreen->getWindow());

		frameRateSprite.clear();
		frameRateSprite.setColor("black");
		frameRateSprite.drawString(0, 0, "test text");
		frameRateSprite.draw(50, 100, this->xScreen->getWindow());

		//Sprite s2(display, this->mainWindow, "test.xbm");
		//s2.draw(0, 0, this->mainWindow);
*/