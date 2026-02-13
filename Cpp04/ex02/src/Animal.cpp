/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:36 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 06:51:01 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("unknown")
{
	std::cout << "ANIMAL: Default Constructor called for type = " << type << "\n";
}

Animal::Animal(const Animal& src) : type(src.type)
{
	std::cout << "ANIMAL: Copy Constructor called for type = " << type << "\n";
}

Animal&	Animal::operator=(const Animal& src)
{
	std::cout << "ANIMAL: Assignment operator called\n\n";
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "ANIMAL: Destructor called for type = " << type << "\n\n";
}

std::string	Animal::getType() const
{
	return (type);
}