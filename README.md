# CPP Module 08 – Templated Containers, Iterators & Algorithms
Overview

This module was my introduction to real STL usage in C++.
Up to this point, most projects avoided containers and algorithms entirely.
CPP08 flips that around and forces you to think in terms of generic code, iterators, and standard containers instead of reinventing the wheel.

The main takeaway for me was understanding how templates + STL containers + iterators work together, and how powerful that combination is when used correctly.

All code follows the C++98 standard and respects the usual 42 constraints.

What This Module Taught Me

How to write generic code using function and class templates

How STL containers behave internally and how to use them idiomatically

Why iterators are the key abstraction behind algorithms and containers

How to design safe, reusable interfaces around standard containers

When and why to use .tpp files for template implementations

How STL algorithms simplify logic and reduce error-prone manual loops

Exercises Breakdown
ex00 – Easy Find

Concepts learned:

Writing a function template that works with different container types

Using iterators instead of assuming random access

Leveraging std::find instead of manual loops

Handling “not found” cases in a way consistent with STL behavior

This exercise showed me how algorithms + iterators allow writing code that works for vector, list, and other containers without modification.

ex01 – Span

Concepts learned:

Designing a class that internally manages a container (std::vector)

Enforcing capacity constraints with exceptions

Using STL algorithms like std::sort, std::min_element, and std::max_element

Efficiently computing distances between elements

Adding elements via iterator ranges instead of repeated function calls

This exercise really emphasized performance and correctness, especially when working with large datasets (10,000+ elements).

ex02 – MutantStack

Concepts learned:

Understanding how container adapters (std::stack) work

Exposing iterators from an underlying container

Inheriting properly while respecting STL design

Making a traditionally non-iterable container iterable

Comparing behavior with other STL containers (std::list)

This exercise helped me understand that many STL containers are just thin abstractions over other containers — and how to extend them safely.

File Structure

Each exercise follows the same clean structure with separated headers and sources:

ex00/
├── inc/
│   ├── easyfind.hpp
│   └── easyfind.tpp
├── src/
│   └── main.cpp
└── Makefile

ex01/
├── inc/
│   └── Span.hpp
├── src/
│   ├── Span.cpp
│   └── main.cpp
└── Makefile

ex02/
├── inc/
│   ├── MutantStack.hpp
│   └── MutantStack.tpp
├── src/
│   └── main.cpp
└── Makefile

Why .tpp Files?

For exercises using templates (ex00 and ex02), I placed template implementations in .tpp files and included them in the headers.
This keeps headers readable while still satisfying the requirement that template definitions must be visible at compile time.

Compilation

All exercises compile with:

c++ -Wall -Wextra -Werror -std=c++98


Each folder contains its own Makefile.

Final Thoughts

CPP08 was the point where C++ finally started to feel expressive instead of restrictive.
Using STL containers and algorithms properly made the code:

shorter

safer

more readable

easier to reason about

This module laid the foundation for understanding modern C++ design, even while staying within C++98 limits.