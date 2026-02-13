# cpp02

📌 Overview

This module introduces ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form in C++.

	You’ll learn how to:

		-Implement canonical constructors and destructors.

		-Overload operators for custom classes.

		-Work with fixed-point numbers.

		-Use objects in mathematical and logical expressions.


Exercise 00: My First Class in Orthodox Canonical Form

	Directory: ex00/

	Files to turn in: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp

	Create a Fixed class in Orthodox Canonical Form with:

		Private members:

			-int to store the fixed-point value.

			-static const int to store the fractional bits (always 8).

		Public members:

			-Default constructor.

			-Copy constructor.

			-Copy assignment operator.

			-Destructor.

			-int getRawBits(void) const;

			-void setRawBits(int const raw);

	💡 Goal: Learn Orthodox Canonical Form and encapsulation.


Exercise 01: Towards a more useful fixed-point number class

	Directory: ex01/

	Files to turn in: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp

	Add to Fixed class:

		-Constructor from int.

		-Constructor from float.

		-float toFloat(void) const;

		-int toInt(void) const;

		-Overload operator<< to output as float.

	Allowed function: roundf (from <cmath>).

	💡 Goal: Practice conversions and operator overloading (<<).


Exercise 02: Now we’re talking

	Directory: ex02/

	Files to turn in: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp

	Extend the Fixed class with operator overloads:

		-Comparison operators: >, <, >=, <=, ==, !=

		-Arithmetic operators: +, -, *, /

		-Increment/Decrement: pre/post ++, pre/post --

	Add static functions:

		-static Fixed& min(Fixed& a, Fixed& b);
		-static const Fixed& min(const Fixed& a, const Fixed& b);
		-static Fixed& max(Fixed& a, Fixed& b);
		-static const Fixed& max(const Fixed& a, const Fixed& b);


	💡 Goal: Enable custom numeric operations and comparisons for user-defined types.

Exercise 03: BSP (Binary Space Partitioning)

	Directory: ex03/

	Files to turn in: Makefile, main.cpp, Fixed.{h, hpp}, Fixed.cpp, Point.{h, hpp}, Point.cpp, bsp.cpp

	Create a Point class in Orthodox Canonical Form:

	Private members:

		-Fixed const x;

		-Fixed const y;

	Implement:

		-bool bsp(Point const a, Point const b, Point const c, Point const point);


	Returns true if point is strictly inside the triangle abc.

	Returns false if the point is on an edge or vertex.

	💡 Goal: Use your Fixed class in a geometry problem with precise math.


⚖️ General Rules

	-All classes must follow Orthodox Canonical Form (default ctor, copy ctor, assignment operator, destructor).

	-No function implementations in headers (except templates).

	-Forbidden: printf, malloc, free, etc.

	-using namespace <ns> and friend are forbidden (grade: -42).

	-Memory leaks forbidden.

	-Headers must be independent + include guards.


🎯 Learning Goals

	-Understand and apply the Orthodox Canonical Form.

	-Learn about fixed-point arithmetic.

	-Practice operator overloading for comparisons, arithmetic, and I/O.

	-Gain experience with object-based math and geometry.