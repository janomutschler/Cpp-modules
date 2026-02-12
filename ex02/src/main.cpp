/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:53:29 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/12 11:10:19 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include <iostream>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include <exception> // std::bad_cast
#include <typeinfo>


#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Randomly instantiate A, B, or C and return as Base*
Base* generate(void)
{
	int r = std::rand() % 3;

	switch (r)
	{
		case 0:
			std::cout << "[generate] created: A" << std::endl;
			return (new A());
		case 1:
			std::cout << "[generate] created: B" << std::endl;
			return (new B());
		default:
			std::cout << "[generate] created: C" << std::endl;
			return (new C());
	}
}

void identify(Base* p)
{
	if (!p)
	{
		std::cout << "identify(Base*): null" << std::endl;
		return ;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "identify(Base*): A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "identify(Base*): B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "identify(Base*): C" << std::endl;
	else
		std::cout << "identify(Base*): unknown" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "identify(Base&): A" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "identify(Base&): B" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "identify(Base&): C" << std::endl;
		return;
	}
	catch (const std::bad_cast&) {}

	std::cout << "identify(Base&): unknown" << std::endl;
}

int main()
{
	// Seed once
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// tests
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "\n=== Test " << (i + 1) << " ===" << std::endl;
		Base* p = generate();
		identify(p);
		identify(*p);
		delete p;
	}

	//null pointer test
	std::cout << "\n=== Null pointer test ===" << std::endl;
	Base* nullPtr = NULL;
	identify(nullPtr);

	return 0;
}
