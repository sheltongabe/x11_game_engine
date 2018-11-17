/**
 *  @file	vector_2d.h
 *  @brief	Declare a 2D math vector
 *  
 *  @author	Gabriel Shelton	sheltongabe
 *  @date	11-14-2018
 *  @version	0.1
 */

#ifndef VECTOR_2D_H
#define VECTOR_2D_H



/**
 * 	@class		2DVector
 * 	@brief		Contain and enable many of the operations availiable for a 2D Vector
 */
class Vector2D {
	public:
		Vector2D();
		Vector2D(Vector2D& copy);
		Vector2D(Vector2D&& move);

		/**
		 * @brief	Initialize the 2D Vector with an x and y component
		 * 
		 * @param	double 	x-component
		 * @param	double	y-component
		 */
		Vector2D(double x, double y);

		// ----- Operators -----
		/**
		 * @brief	implement the = operator
		 */
		Vector2D& operator=(const Vector2D& rhs);

		/**
		 * @brief	Add by components between this vector and the rhs
		 * @param	2DVector&	rhs
		 * @return	Vector2D&	this resulting vector
		 */
		Vector2D& operator+=(const Vector2D& rhs);

		/**
		 * @brief	Add one vector to another, by component
		 * @param	Vector2D 	lhs
		 * @param	Vector2D&	rhs
		 * @return	Vector2D
		 */
		friend Vector2D operator+(Vector2D lhs, const Vector2D& rhs);
		/**
		 * @brief	Subtract by components between this vector and the rhs
		 * @param	2DVector&	rhs
		 * @return	Vector2D&	this resulting vector
		 */
		Vector2D& operator-=(const Vector2D& rhs);

		/**
		 * @brief	Subtract one vector from another, by component
		 * @param	Vector2D 	lhs
		 * @param	Vector2D&	rhs
		 * @return	Vector2D
		 */
		friend Vector2D operator-(Vector2D lhs, const Vector2D& rhs);

		/**
		 * @brief	Multiply by a scalar to this vector
		 * @param	double&		rhs
		 * @return	Vector2D&	this resulting vector
		 */
		Vector2D& operator*=(const double& rhs);

		/**
		 * @brief	Multiply a vector by a scalar
		 * @param	Vector2D 	lhs
		 * @param	double&	rhs
		 * @return	Vector2D
		 */
		friend Vector2D operator*(Vector2D lhs, const double& rhs);

		// ----- Getters / Setters -----

		/// Get the x-component
		double getX() { return this->x; }

		/// Set the x component
		void setX(double x) { this->x = x; }

		/// Get the y-component
		double getY() { return this->y; }

		/// Set the y component
		void setY(double y) { this->y = y; }

		~Vector2D();

	protected:
		/// The X-Component of the vector
		double x;

		/// The Y-Component of the vector
		double y;

	private:

};

#endif