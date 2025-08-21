# cpp00
C++ Module 00
📌 Overview

This module is the starting point of the C++ journey at 42.
It introduces the basics of Object-Oriented Programming (OOP) in C++ and covers:

  -Namespaces

	-Classes

  -Member functions

  -I/O streams (iostream)

  -Initialization lists

  -static and const keywords

  -Basic C++ coding style


All exercises must be done in C++98 with the compiler flags:

  -Wall -Wextra -Werror -std=c++98



Exercise 00: Megaphone

Directory: ex00/

Files to turn in: Makefile, megaphone.cpp

Write a program that:

  Takes command-line arguments and prints them in uppercase.

  If no argument is provided, prints:

  * LOUD AND UNBEARABLE FEEDBACK NOISE *


Exercise 01: My Awesome PhoneBook

Directory: ex01/

Files to turn in: Makefile, *.cpp, *.h/*.hpp

Implement two classes:

PhoneBook

  -Stores up to 8 contacts (replace the oldest if full).

  -Uses a fixed array (no dynamic allocation allowed).

Contact

  -Holds personal data: first name, last name, nickname, phone number, darkest secret.

Program accepts three commands:

  -ADD → Add a new contact (all fields required).

  -SEARCH → Display summary table (10-char wide, right aligned, truncated with . if longer).

  -Then display full contact info by user selecting index.

  -EXIT → Quit program.

Exercise 02: The Job Of Your Dreams


Directory: ex02/

Files to turn in: Makefile, Account.cpp, Account.hpp, tests.cpp

  -Task: Recreate a missing Account.cpp file using the given Account.hpp, tests.cpp, and a log file.

  -Program output must match the provided logs (timestamps will differ).

  -Purpose: Practice class implementation, constructors/destructors, and logging behavior.


⚖️ General Rules

No external libraries (Boost, C++11+, etc.)

Forbidden functions: printf(), malloc(), calloc(), realloc(), free()

using namespace <ns> and friend are forbidden (grade: -42).

No STL containers/algorithms.

Memory leaks are forbidden → manage with care.

Each header must be self-contained with include guards.


🎯 Learning Goals

  -Get familiar with C++ syntax vs C.

  -Learn how to design and use classes.

  -Practice input/output with iostream.

  -Understand initialization lists, static members, and const.

  -Write clean, readable, object-oriented code.
