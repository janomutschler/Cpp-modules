/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:42 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/31 14:05:07 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() 
{
    type = "Dog";
    std::cout << "DOG: Default Constructor called for type = " << type << "\n";
}

Dog::Dog(const Dog& src) : Animal(src) 
{
    *this = src;
    std::cout << "DOG: Copy Constructor called for type = " << type << "\n";
}

Dog& Dog::operator=(const Dog& src) 
{
    std::cout << "DOG: Assignment operator called\n";
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "DOG: Destructor called for type = " << type << "\n";
}

void	Dog::makeSound() const
{
    std::cout << "Woof! Woof!\n";
}