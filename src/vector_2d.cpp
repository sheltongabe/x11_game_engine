/**
 *  @file	2__vVector.cpp
 *  @brief	
 *  
 * 	Details
 *  
 *  @author	First_Last_Name	username
 *  @date	11-14-2018
 *  @version	0.0
 */

#include <utility>

#include "vector_2d.h"

//
// Default Constructor
//
Vector2D::Vector2D() : 
	x(0),
	y(0) {

}

//
// Copy Constructor
//
Vector2D::Vector2D(Vector2D& copy) :
	x(copy.x),
	y(copy.y) {

}

//
// Move Constructor
//
Vector2D::Vector2D(Vector2D&& move) :
	x(std::move(move.x)),
	y(std::move(move.y)) {

}

// 
// operator= (const Vector2D& rhs) -> Vector2D&
//
Vector2D& Vector2D::operator=(const Vector2D& rhs) {
	// Skip self assignment check
	this->x = rhs.x;
	this->y = rhs.y;
}

// 
// operator+=
//
Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
	this->x += rhs.x;
	this->y += rhs.y;
	return *this;
}

// 
// operator+
//
Vector2D operator+(Vector2D lhs, const Vector2D& rhs) {
	lhs += rhs;
	return lhs;
}

// 
// operator-=
//
Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
	this->x -= rhs.x;
	this->y -= rhs.y;
	return *this;
}

// 
// operator-
//
Vector2D operator-(Vector2D lhs, const Vector2D& rhs) {
	lhs -= rhs;
	return lhs;
}

// 
// operator*=
//
Vector2D& Vector2D::operator*=(const double& rhs) {
	this->x *= rhs;
	this->y *= rhs;
}

// 
// operator*
//
Vector2D operator*(Vector2D lhs, const double& rhs) {
	lhs *= rhs;
	return lhs;
}

//
// Destructor 
//
Vector2D::~Vector2D() {

}