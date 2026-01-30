/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 13:02:19 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/30 11:24:03 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../inc/Bureaucrat.hpp"
//#include <iostream>

//int main() {
//	try {
//		Bureaucrat a("Alpha", 150);
//		std::cout << a << std::endl;
//	}
//	catch (const std::exception &err) {
//		std::cerr << "Exception caught: "<< err.what() << std::endl;
//	}

//	std::cout << "\n\n";
//	try {
//		Bureaucrat b("Beta", 0);
//		std::cout << b << std::endl;
//	}
//	catch (const std::exception &err) {
//		std::cerr << "Exception caught: "<< err.what() << std::endl;
//	}

//	std::cout << "\n\n";
//	try {
//		Bureaucrat c("Gamma", 1);
//		c.incrementGrade();
//		std::cout << c << std::endl;
//	}
//	catch (const std::exception &err) {
//		std::cerr << "Exception caught: "<< err.what() << std::endl;
//	}

//	std::cout << "\n\n";
//	try {
//		Bureaucrat d("Delta", 150);
//		d.decrementGrade();
//		std::cout << d << std::endl;
//	}
//	catch (const std::exception &err) {
//		std::cerr << "Exception caught: "<< err.what() << std::endl;
//	}

//	std::cout << "\n\n";
//	try {
//		Bureaucrat e("Epsilon", 149);
//		e.decrementGrade();
//		std::cout << e << std::endl;
//	}
//	catch (const std::exception &err) {
//		std::cerr << "Exception caught: "<< err.what() << std::endl;
//	}
//	return 0;
//}

#include "../inc/Bureaucrat.hpp"
#include <iostream>

static void printHeader(const std::string& title)
{
    std::cout << "\n=== " << title << " ===\n";
}

int main()
{
    // 1) Valid construction
    printHeader("Valid construction");
    try
    {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 150);
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    // 2) Invalid construction (too high)
    printHeader("Invalid construction: too high");
    try
    {
        Bureaucrat x("X", 0);
        std::cout << x << std::endl; // should never run
    }
    catch (std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // 3) Invalid construction (too low)
    printHeader("Invalid construction: too low");
    try
    {
        Bureaucrat y("Y", 151);
        std::cout << y << std::endl; // should never run
    }
    catch (std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // 4) Increment boundary
    printHeader("Increment boundary");
    try
    {
        Bureaucrat c("Charlie", 2);
        std::cout << c << std::endl;
        c.incrementGrade();
        std::cout << c << std::endl; // should be grade 1
        c.incrementGrade();          // should throw
        std::cout << "ERROR: should not reach here\n";
    }
    catch (std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    // 5) Decrement boundary
    printHeader("Decrement boundary");
    try
    {
        Bureaucrat d("Dana", 149);
        std::cout << d << std::endl;
        d.decrementGrade();
        std::cout << d << std::endl; // should be grade 150
        d.decrementGrade();          // should throw
        std::cout << "ERROR: should not reach here\n";
    }
    catch (std::exception& e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
