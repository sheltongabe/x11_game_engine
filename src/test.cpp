/**
 *  @file	test.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-02-2018
 *  @version	0.1
 */

#include "test.h"
#include <iostream>
//
// Default Constructor
//
Test::Test() {

}

//
// Copy Constructor
//
Test::Test(Test& copy) {

}

//
// Print
//
void Test::print(const char* message) {
	std::cout << message << '\n';
}

//
// Destructor 
//
Test::~Test() {

}