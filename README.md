# CPP Module 09 – STL

This module was my first time really using the STL in a controlled way instead of just knowing that it exists.
Each exercise forced me to pick containers intentionally, understand their behavior, and think about algorithms, data validation, and performance, not just syntax.

What I especially liked (and struggled with) is that every exercise forbids reusing containers from previous ones. That constraint made the learning very real.

# Exercise 00 – Bitcoin Exchange

Goal:
Read historical Bitcoin prices from a CSV file and evaluate values from an input file based on dates.

What I learned

	• How to parse structured input safely (date | value)

	• Why std::map is perfect for time-based lookup

			- automatic sorting

			- lower_bound() for closest previous date

	• How strict input validation quickly explodes in complexity:

			- invalid dates

			- negative values

			- values > 1000

			- malformed lines

	• Separating responsibilities matters:

			- parsing

			- database loading

			- evaluation logic

	• Error handling should be precise and explicit, not generic

This exercise forced me to stop “just parsing strings” and start designing data flow.

# Exercise 01 – Reverse Polish Notation (RPN)

Goal:
Evaluate a mathematical expression written in Reverse Polish Notation.

What I learned

	• Why a stack is the natural data structure for RPN

	• How stack-based evaluation works step by step:

			- push operands

			- pop two values on operator

			- apply operation

			- push result back

	• How fragile evaluation becomes without validation:

			- too many operators

			- too many operands

			- division by zero

			- invalid characters

	• That “the stack should end with exactly one value” is a hard correctness rule

	• Writing small helper functions (like applyOperator) keeps logic readable

This exercise was a good reminder that simple problems still need strict rules to be correct.

# Exercise 02 – PmergeMe

Goal:
Implement the Ford–Johnson (merge-insert) sorting algorithm and compare performance across containers.

This was by far the hardest exercise in the module.

What I learned

	• How the merge-insert algorithm actually works:

			- pairing elements

			- recursive sorting of pairs

			- insertion using the Jacobsthal sequence

	• Why the STL does not magically give you performance

	• The real differences between:

			- std::vector

			- std::deque

	• That algorithm design matters more than container choice

	• Measuring time correctly means:

			- include parsing

			- include copying

			- include insertion

	• Why writing separate implementations per container is sometimes the right call

This exercise finally connected theoretical algorithms with real runtime behavior.

# Project Structure

	├── ex00
	│   ├── input.txt
	│   ├── data.csv
	│   ├── inc/
	│   │   └── BitcoinExchange.hpp
	│   ├── src/
	│   │   ├── BitcoinExchange.cpp
	│   │   ├── BitcoinExchangeDatabase.cpp
	│   │   ├── BitcoinExchangeParsing.cpp
	│   │   └── main.cpp
	│   └── Makefile
	│
	├── ex01
	│   ├── inc/
	│   │   └── RPN.hpp
	│   ├── src/
	│   │   ├── RPN.cpp
	│   │   └── main.cpp
	│   └── Makefile
	│
	├── ex02
	│   ├── inc/
	│   │   ├── PmergeMe.hpp
	│   │   └── utils.hpp
	│   ├── src/
	│   │   ├── PmergeMe.cpp
	│   │   ├── vector.cpp
	│   │   ├── deque.cpp
	│   │   ├── jacobsthalSequence.cpp
	│   │   ├── parsing.cpp
	│   │   ├── utils.cpp
	│   │   └── main.cpp
	│   └── Makefile
	│
	└── README.md

# General Takeaways

	• STL containers are tools, not solutions

	• Constraints (like “you can’t reuse containers”) accelerate learning

	• Clean separation of logic beats clever code

	• Performance discussions only matter when:

			- correctness is guaranteed

			- input size is realistic

	• Debugging algorithms is much harder than debugging syntax

This module pushed me from “I know what a vector is” to
“I know when and why I should use it.”

# Compilation

All exercises follow the same rules:

	c++ -Wall -Wextra -Werror -std=c++98


Each directory contains its own Makefile.
