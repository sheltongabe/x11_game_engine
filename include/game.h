/**
 *  @file	game.h
 *  @brief	Implement the main game loop and keep hold the screen.
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-08-2018
 *  @version	0.1
 */

#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <queue>

#include "scene.h"
#include "x_display.h"
#include "sprite.h"

/**
 * 	@class		Game
 * 	@brief		Contains the main loop and is designed to be extended by users
 */
class Game {
	public:
		/**
		 * @brief	Default Constructor (initialize the connection to the x11 server)
		 * 
		 * Initialize the server connection, 
		 * Call load(), to load implementation specific settings and the start Scene
		 * Start the gameLoop()
		 * 
		 * @version	0.1
		 */
		Game(const char* name, const char* title, int width, int height);
		Game() = delete;
		Game(Game& copy) = delete;
		Game(Game&& move) = delete;

		/// End the game (sets running to false, so the next iteration of the game loop will end)
		void endGame();

		/**
		 * @brief	Add a Scene to the index of loaded Scenes
		 * 
		 * Will ensure Scene::load() is called on the passed Scene
		 * Then will add it to the index of loaded scenes
		 * 
		 * @param	std::string		scene name
		 * @param	Scene*			The Scene to store
		 */
		void addScene(std::string name, Scene* scene);

		/**
		 * @brief	Return the scene matching that name from the scene index
		 * 
		 * @return	Scene*				A Scene matching that name from the scene index
		 * @throws	std::runtime_error	A Scene by that name does not exist in the index
		 */
		Scene* getScene(std::string name);

		/**
		 * @brief	Remove a scene from the scene index
		 * 
		 * Calls delete on the scene referenced by that name
		 * 
		 * @param	std::string			scene name
		 * @throws 	std::runtime_error	scene by that name does not exist
		 */
		void removeScene(std::string name);

		/**
		 * @brief	Switch the current scene
		 * 
		 * Hide the current scene, switch to the new Scene, and show it
		 * 
		 * @param	std::string			scene name
		 * @throws 	std::runtime_error	scene by that name does not exist
		 */
		void switchScene(std::string name);

		~Game();

	protected:
		/**
		 * @brief	Virtual method called by the constructor where any game to load anything game-specific.
		 * 
		 * Do not load the starting Scene in any overloads, simply call Game::load() in the child version
		 * It will get the starting Scene by calling a pure virtual method, getStartScene(), add it to the Scene's map
		 * with the name of 'start' and set it to the current Scene
		 */
		virtual void load();

		/**
		 * @brief	Return the screen that the game implementation will start on.
		 * @return 	Scene which game will start with.
		 */
		virtual Scene* getStartScene() = 0;

		/// The screen to display on
		Scene* currentScene;

		/// The map of scenes in memory
		std::unordered_map<std::string, Scene*> scenes;

		/// Any non-internal events
		

		/// Is the game still running
		bool isRunning;

		// Dimensions of the game
		int width, height;

		// Name and title
		std::string name, title;

	private:
		/// Target FPS for the game loop
		const static int TARGET_FPS = 60;

		// Test Sprites
		Sprite* frameRateSprite;
		Sprite* s, *s3;
		int lastFPS;

		/**
		 * @brief	Check to see if a scene by the passed name exists
		 * 
		 * @param	std::string		name
		 * @return	boolean			if the scene index contains a scene by that name
		 */
		bool sceneExists(std::string);

		/**
		 * @brief	Handle the main game loop
		 * 
		 * Call update(), and render()
		 * handle pausing, and frame rate.
		 */
		void mainLoop();

		/**
		 * @brief	Calls update(percentTimeElapsed) on the currentScene
		 * 
		 * Will also process any events
		 * 
		 * @param	double		Proportion of the targetTime that was filled
		 */
		void update(double percentTimeElapsed);

		/**
		 * @brief	Calls render() on the currentScene
		 */
		void render();

		/**
		 * @brief	Hidden main event loop, designed to run on the xScreen that is current, and populate a queue of events
		 */
		void internalProcessEvents();
};

#endif