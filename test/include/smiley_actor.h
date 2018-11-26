/**
 *  @file	smiley_actor.h
 *  @brief	Test an actor that contains an image
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-23-2018
 *  @version	0.1
 */

#ifndef SMILEYACTOR_H
#define SMILEYACTOR_H

#include "x11_game_engine/dynamic_actor.h"

/**
 * 	@class		SmileyActor
 * 	@brief		Test a DynamicActor with an image
 */
class SmileyActor : public DynamicActor {
	public:
		/**
		 * 	@brief	Default Constructor
		 * 
		 * 	@version	0.1
		 */
		SmileyActor();

		SmileyActor(SmileyActor& copy) = delete;
		SmileyActor(SmileyActor&& move) = delete;

		/// Load
		virtual void load();

		/**
		 * 	@brief	Destructor
		 */
		~SmileyActor();

	private:

};

#endif