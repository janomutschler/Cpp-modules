/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:48 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/31 14:17:01 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("unknown")
{
	std::cout << "WRONGANIMAL: Default Constructor called for type = " << type << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type)
{
	std::cout << "WRONGANIMAL: Copy Constructor called for type = " << type << "\n";
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& src)
{
	std::cout << "WRONGANIMAL: Assignment operator called\n\n";
	if (this != &src)
	{
		this->type = src.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WRONGANIMAL: Destructor called for type = " << type << "\n\n";
}

void	WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal Sound\n";
}

std::string	WrongAnimal::getType() const
{
	return (type);
}