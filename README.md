# cpp01
C++ Module 01

📌 Overview

	This module builds upon C++ basics and introduces:

		-Memory allocation (new, delete)

		-Pointers to members

		-References

		-switch statements


You’ll start working more with object lifecycles, memory management, and references, preparing for deeper OOP concepts.

As always, compile with:

-Wall -Wextra -Werror -std=c++98


Exercise 00: BraiiiiiiinnnzzzZ

	Directory: ex00/

	Files to turn in: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, newZombie.cpp, randomChump.cpp

	Implement a Zombie class with:

		-announce() method printing:

			-<name>: BraiiiiiiinnnzzzZ...


	Implement functions:

		-Zombie* newZombie(std::string name); → heap allocation.

		-void randomChump(std::string name); → stack allocation + immediate announce.

	Destructor must print a message when a zombie is destroyed.

	💡 Goal: Understand stack vs heap allocation.


Exercise 01: Moar brainz!

	Directory: ex01/

	Files to turn in: Makefile, main.cpp, Zombie.{h, hpp}, Zombie.cpp, zombieHorde.cpp

	Implement:

		-Zombie* zombieHorde(int N, std::string name);

	Creates N zombies in a single allocation.

	Each zombie should announce itself.

	Remember to delete [] the allocated array.


Exercise 02: HI THIS IS BRAIN

	Directory: ex02/

	Files to turn in: Makefile, main.cpp

	Program requirements:

		-A string initialized with "HI THIS IS BRAIN".

		-A pointer (stringPTR) and a reference (stringREF) to it.

		-Print memory addresses and values via variable, pointer, and reference.

	💡 Goal: Demystify references vs pointers.


Exercise 03: Unnecessary violence

	Directory: ex03/

	Files to turn in: Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h, hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp

	Implement:

		-Weapon class with getType() and setType().

	Two human classes:

		-HumanA → always has a weapon (passed in constructor).

		-HumanB → may or may not have a weapon (can be set later).

	Both must have an attack() function:

		-<name> attacks with their <weapon type>


Exercise 04: Sed is for losers

	Directory: ex04/

	Files to turn in: Makefile, main.cpp, *.cpp, *.h/*.hpp

	Program takes:

		-./sedIsForLosers <filename> <s1> <s2>

	Copies <filename> into <filename>.replace, replacing all occurrences of s1 with s2.

	Forbidden: std::string::replace.


Exercise 05: Harl 2.0

Directory: ex05/

	Files to turn in: Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp

	Implement a Harl class with complaints: DEBUG, INFO, WARNING, ERROR.

	Use pointers to member functions (no giant if/else).

	Method:

		-void complain(std::string level);


Exercise 06: Harl filter

	Directory: ex06/

	Files to turn in: Makefile, main.cpp, Harl.{h, hpp}, Harl.cpp

	Extend Harl:

		-Program takes one parameter (DEBUG, INFO, WARNING, ERROR).

		-Prints messages from that level and all higher severity levels.

	Invalid input → print:

		-[ Probably complaining about insignificant problems ]

	Must use a switch statement.

	Executable must be named harlFilter.


⚖️ General Rules

	Forbidden: printf, malloc, free, etc.

	using namespace <ns> and friend → forbidden (grade: -42).

	Memory leaks = forbidden.

	Each header must be independent + have include guards.


🎯 Learning Goals

	Practice constructors/destructors.

	Differentiate stack vs heap allocation.

	Understand pointers, references, and member pointers.

	Use switch statements in a real-world example.

	Build modular C++ programs across multiple classes.