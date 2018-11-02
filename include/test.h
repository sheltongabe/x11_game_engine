/**
 *  @file	test.h
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-02-2018
 *  @version	0.0
 */

#ifndef TEST_H
#define TEST_H



/**
 * 	@class		Test
 * 	@brief		
 * 
 * 	Details
 * 
 */
class Test {
	public:
		/**
		 * 	@brief	Default Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		Test();

		/**
		 * 	@brief	Copy Constructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		Test(Test& copy);

		void print(const char* message);

		/**
		 * 	@brief	Destructor
		 * 
		 * 	Details
		 * 
		 * 	@version	0.1
		 */
		~Test();

	private:

};

#endif