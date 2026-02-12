*This project has been created as part of the 42 curriculum by jmutschl.*

# CPP Module 05 — Repetition & Exceptions (ex00–ex03)

This module was all about designing a small “bureaucracy” system while practicing exceptions, class relationships, and polymorphism in C++98. The big theme: keep objects valid, enforce rules with exceptions, and connect classes through clean interfaces.

# ex00 — Bureaucrat (grades + exceptions)
What I built

    • A Bureaucrat with:
    
        - const std::string _name
        
        -int _grade in range [1..150] (1 is best, 150 is worst)

    • Custom exceptions:
    
        - GradeTooHighException
        
        - GradeTooLowException
    
    • Grade operations:
    
        - incrementGrade() (grade goes down numerically: 3 → 2)
        
        - decrementGrade() (grade goes up numerically: 3 → 4)
    
    • operator<< to print:
    
        - "<name>, bureaucrat grade <grade>."

How I solved it

I treated the grade rule as an invariant:

    • Constructor validates _grade immediately and throws if invalid.
    
    • Increment/decrement also validate and throw if they would go out of bounds.
      This way, a Bureaucrat object can never exist in an invalid state.

What it taught me

    • Exception handling is perfect for enforcing “hard rules” (like grade boundaries).
    
    • The difference between throwing and printing errors: the class throws; main decides what to do.
    
    • Overloading operator<< makes debugging and test output clean.

# ex01 — Form (interaction between classes)
What I built

    • A Form with:

        - const std::string _name
        
        - bool _isSigned
        
        - const int _signGrade
        
        - const int _execGrade

    • Exceptions:
    
        - Form::GradeTooHighException
        
        - Form::GradeTooLowException
    
    • Form::beSigned(Bureaucrat const&)
    
        - signs the form if bureaucrat grade is high enough
        
        - otherwise throws GradeTooLowException
    
    • Bureaucrat::signForm(Form&)
    
        - calls beSigned() inside try/catch and prints success/failure messages

How I solved it

I kept responsibilities clear:

    • Form decides whether it can be signed.
    
    • Bureaucrat just attempts to sign and reports the result.

What it taught me

    • How to connect two classes safely without mixing responsibilities.
    
    • Designing a clean API: beSigned() is the only way to change the signed state.
    
    • Writing error messages in the caller while keeping the logic inside the class.

# ex02 — AForm (abstract base class + concrete forms)
What I built

    • Replaced Form with an abstract base class AForm
    
    • Added concrete forms:
    
        - ShrubberyCreationForm (sign 145, exec 137) → creates <target>_shrubbery with ASCII trees
        
        - RobotomyRequestForm (sign 72, exec 45) → 50% success robotomy + drilling noises
        
        - PresidentialPardonForm (sign 25, exec 5) → prints pardon message
    
    • Added:
    
        - AForm::execute(Bureaucrat const& executor) const
        
          - checks: signed + executor grade high enough
          
          - then triggers the form-specific action (implemented in derived class)
    
    • Added Bureaucrat::executeForm(AForm const&)

How I solved it

I implemented the “elegant” approach:

    • All common checks live in AForm::execute():
    
        - “is it signed?”
        
        - “is executor grade sufficient?”
    
    • After passing checks, AForm calls a derived behavior (like executeAction()).
     This prevents copy/pasting the same checks in every derived class.

What it taught me

    • Abstract classes enforce a contract (“every form can be executed”).
    
    • Polymorphism: one executeForm() works for any form type.
    
    • Better architecture: shared logic in base class, specific behavior in derived classes.
    
    • Being careful with new (forms created dynamically) → don’t leak memory.

# ex03 — Intern (factory pattern without ugly if/else chains)
What I built

    • An Intern class that can create forms dynamically:
    
        - AForm* makeForm(std::string const& name, std::string const& target)
    
    • It prints:
    
        - Intern creates <form>
    
    • If name doesn’t match:
    
        - prints an explicit error and returns NULL (or similar)

How I solved it

Instead of a huge if/else if/else, I used a lookup table idea:

    • Map form names → a creation function
    
    • Search in that table and call the matching creator
      This keeps makeForm() readable and easy to extend.

What it taught me

    • A simple factory pattern in C++98
    
    • Avoiding messy branching logic by using structured data
    
    • Returning base-class pointers (AForm*) while constructing derived objects

# Project structure
    ./ex00
      Makefile
      inc/Bureaucrat.hpp
      src/Bureaucrat.cpp
      src/main.cpp
    
    ./ex01
      Makefile
      inc/Bureaucrat.hpp
      inc/Form.hpp
      src/Bureaucrat.cpp
      src/Form.cpp
      src/main.cpp
    
    ./ex02
      Makefile
      inc/Bureaucrat.hpp
      inc/AForm.hpp
      inc/ShrubberyCreationForm.hpp
      inc/RobotomyRequestForm.hpp
      inc/PresidentialPardonForm.hpp
      src/Bureaucrat.cpp
      src/AForm.cpp
      src/ShrubberyCreationForm.cpp
      src/RobotomyRequestForm.cpp
      src/PresidentialPardonForm.cpp
      src/main.cpp
    
    ./ex03
      Makefile
      inc/Bureaucrat.hpp
      inc/AForm.hpp
      inc/Intern.hpp
      inc/ShrubberyCreationForm.hpp
      inc/RobotomyRequestForm.hpp
      inc/PresidentialPardonForm.hpp
      src/Bureaucrat.cpp
      src/AForm.cpp
      src/Intern.cpp
      src/ShrubberyCreationForm.cpp
      src/RobotomyRequestForm.cpp
      src/PresidentialPardonForm.cpp
      src/main.cpp

# How to build & run

From any exercise folder:

    make
    ./ex00   # or ./ex01, ./ex02, ./ex03 depending on the folder

# Key concepts I practiced (big takeaways)

    • Exceptions for enforcing invariants and reporting errors cleanly 
    
    • Operator overloading (operator<<) for clean debug output
    
    • Class relationships (Bureaucrat ↔ Form/AForm)
    
    • Abstract classes + polymorphism (one interface, many behaviors)
    
    • Factory pattern with an Intern creating derived classes from strings
    
    • Memory discipline when returning new objects (caller owns the pointer)
