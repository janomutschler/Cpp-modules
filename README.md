# cpp07
CPP Module 07 — Templates

This project is part of the 42 C++ curriculum and focuses on learning and applying C++ templates.
The goal of this module was to understand how to write type-generic code, handle const correctness, and manage memory safely, all while staying compliant with C++98 and without using the STL.

Project Constraints

Throughout this module, I followed these rules:

	Compilation with:

		c++ -Wall -Wextra -Werror -std=c++98


	No external libraries

	No printf, malloc, or free

	No STL containers or algorithms

	Templates implemented in header files

	No memory leaks

	Orthodox Canonical Form where required

What I Implemented


ex00 — Function Templates

In this exercise, I implemented basic function templates to understand how templates replace duplicated code for different types.

Implemented in whatever.hpp:

	swap(a, b) — swaps two values

	min(a, b) — returns the smaller value
	(returns the second argument if both are equal)

	max(a, b) — returns the larger value
	(returns the second argument if both are equal)

This exercise helped me understand template syntax, type deduction, and how comparisons depend on operator overloading.



ex01 — iter

In this exercise, I implemented a template function iter that applies a given function to each element of an array.

The function:

	Receives a pointer to an array

	Receives the array length as a const value

	Applies a function to each element

Special care was taken to:

	Support both const and non-const arrays

	Work with functions taking either T& or const T&

This exercise emphasized const correctness and how function pointers interact with templates.



ex02 — Array Class Template

In this exercise, I implemented a generic dynamic array class without using the STL.

The Array<T> class includes:

	A default constructor creating an empty array

	A constructor allocating n elements

	A copy constructor and copy assignment operator performing deep copies

	A destructor properly freeing allocated memory

	An overloaded operator[] with bounds checking

	A size() const method returning the number of elements

This exercise reinforced:

	Manual memory management with new[] / delete[]

	Deep copy vs shallow copy

	Exception safety in template classes

Project Structure
	cpp07
	├── ex00/
	│   ├── Makefile
	│   ├── main.cpp
	│   └── whatever.hpp
	├── ex01/
	│   ├── Makefile
	│   ├── main.cpp
	│   └── iter.hpp
	└── ex02/
		├── Makefile
		├── main.cpp
		├── Array.hpp
		└── Array.tpp

How to Build and Run

From inside each exercise directory:

	make
	./<executable_name>

What I Learned

	How C++ templates work at compile time

	Why template implementations must be visible in headers

	How to write const-correct template functions

	How to safely manage dynamic memory in template classes

	How to implement deep copy semantics

	How to throw and handle exceptions correctly