*This project has been created as part of the 42 curriculum by jmutschl.*

# C++ Module 06 — C++ Casts

This repository contains my solutions for C++ Module 06 at 42.
The focus of this module is understanding and correctly using C++ casts:

    • static_cast
    
    • reinterpret_cast
    
    • dynamic_cast

The main idea: conversions are not just syntax — they have runtime meaning (overflow, precision loss, RTTI checks, pointer identity, etc.). This module forced me to be explicit and intentional about type conversions.

# ex00 — ScalarConverter

Goal: Convert a string literal into:

    • char
    
    • int
    
    • float
    
    • double

Including special pseudo-literals like nan, +inf, -inf, and their f variants.

What I did

    • Separated type detection from conversion logic.
    
    • Handled edge cases (overflow, non-displayable chars, impossible conversions).
    
    • Used explicit casts to convert between scalar types.
    
    • Carefully formatted output (e.g. 42.0f, impossible, Non displayable).

What I learned

    • Robust literal parsing.
    
    • Numeric limits and precision handling.
    
    • Why implicit conversions are dangerous.

# ex01 — Serializer

Goal: Convert a pointer to an integer and back.

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

What I did

    • Used reinterpret_cast to convert between Data* and uintptr_t.
    
    • Proved pointer identity (ptr == deserialize(serialize(ptr))).

What I learned

    • What uintptr_t is for.
    
    • Difference between actual serialization and raw address casting.
    
    • When reinterpret_cast is the correct tool.

# ex02 — Identify Real Type

Goal: Identify the real type (A, B, or C) behind a Base* or Base& without using typeid.

What I did

    • Implemented generate() to randomly create A, B, or C.
    
    • Used dynamic_cast for safe downcasting.
    
        - Pointer version → check for NULL
        
        - Reference version → catch std::bad_cast

What I learned

    • RTTI and polymorphism basics.
    
    • Why a virtual destructor is required.
    
    • Difference between pointer and reference dynamic_cast.

# Project Structure
    ./README.md
    
    ./ex00
      Makefile
      inc/
        ScalarConverter.hpp
        ScalarConverterPriv.hpp
      src/
        ScalarConverter.cpp
        DetectType.cpp
        ConvertAndPrint.cpp
        main.cpp
    
    ./ex01
      Makefile
      inc/
        Data.hpp
        Serializer.hpp
      src/
        Data.cpp
        Serializer.cpp
        main.cpp
    
    ./ex02
      Makefile
      inc/
        Base.hpp
        A.hpp
        B.hpp
        C.hpp
      src/
        Base.cpp
        A.cpp
        B.cpp
        C.cpp
        main.cpp

Each exercise is standalone and compiled with C++98 (-Wall -Wextra -Werror).

# Summary

Module 06 strengthened my understanding of:

    • Explicit type conversions
    
    • Safe vs unsafe casting
    
    • Pointer identity
    
    • Runtime type identification

It made me more precise about how and why I convert types in C++, instead of relying on implicit behavior.
