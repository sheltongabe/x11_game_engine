/**
 * @file	scene.h
 * @brief	Provide a definition for what will be displayed onto the screen
 *  
 * @author	First_Last_Name	username
 * @date	11-16-2018
 * @version	0.0
 */

#ifndef SCENE_H
#define SCENE_H

#include <unordered_map>

#include "game.h"
#include "actor.h"
#include "x_screen.h"

/**
 * @class	Scene
 * @brief	Define a particular stage of the Game, from title to end
 *  
 * TODO: Invert the dependency and make Sprite the parent and XScreen the child
 * It inherits from XScreen, and defines the logic for any particular stage of the game
 * Here all of the Actors might be stored, updated, and rendered in order to organize 
 * 	and facilitate game advancement.
 * A Scene might represent the titleScreen, the main GameScreen, a GameOverScreen, 
 *  or any number of intermediate stages of the Game.
 */
class Scene : public XScreen {
	public:
		/**
		 * @brief	Initialize the XScreen, to work with this Scene
		 * 
		 * It will have a Window, that will not necassarily be displayed immediately
		 * This constructor is also responsible for calling the local Scene::load()
		 * 	which is responsible for initializing the scene, and its resources
		 * This will all prepare it for when Game::mainLoop() calls the update
		 *  and render methods on this class, that are overridden by the user.
		 * 
		 * @param	Game* 			game
		 * @param	const char*		name
		 * @param	const char*		title
		 * @param	uint			width
		 * @param	uint			height
		 */
		Scene(Game* game, const char* name, const char* title,
				unsigned int width, unsigned int height);
		Scene() = delete;
		Scene(Scene& copy) = delete;
		Scene(Scene&& move) = delete;

		/**
		 * @brief	Update the current status of the Actors based on this stages logic
		 * 
		 * If the Scene is not paused
		 * Call Actor::update(percentTimeElapsed) on all of the Actors
		 *   Uses a percentage in order to make it more steady if the frame rate starts varying
		 * TODO: Check collisions as neccassary
		 * If it was paused, check if it should be resumed
		 * 
		 * @param	double		The percentage of the time that was supposed to elapse.
		 */
		virtual void update(double percentTimeElapsed);

		/**
		 * @brief	Render the current status of the Scene based on its particular logic
		 * 
		 * Call Actor::render() on each actor
		 */
		virtual void render();

		/// Have XScreen map the window for this Scene
		void show();

		/// Have XScreen unmap the window for this Scene
		void hide();

		/// Check if the Scene is paused
		bool isPaused();

		/// Pause the scene
		void pause();

		/// Resume the scene
		void play();

		~Scene();

	protected:
		/**
		 * @brief	Should be overridden by an clients, but also call the Parent to make sure configurations are right
		 * 
		 * Prepares the Scene to be played, by loading the Actors, and positioning them
		 */
		virtual void load();

		/// Back-pointer to the Game that this Scene belongs to
		Game* game;

		/// unordered map to hold actors, indexed by strings, allows update and render to find all the actors
		std::unordered_map<std::string, Actor*> actors;

		/// Should the current scene be updating / rendering
		bool isScenePaused;

	private:

};

#endif