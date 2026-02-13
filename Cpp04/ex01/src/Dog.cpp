/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:42 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 06:20:59 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() 
{
    type = "Dog";
    std::cout << "DOG: Default Constructor called for type = " << type << "\n";
    _brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src) 
{
    std::cout << "DOG: Copy Constructor called for type = " << type << "\n";
    _brain = new Brain(*src._brain);
    type = src.type;
}

Dog& Dog::operator=(const Dog& src) 
{
    std::cout << "DOG: Assignment operator called\n";
    if (this != &src)
    {
        Animal::operator=(src);
        delete _brain;
        _brain = new Brain(*src._brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "DOG: Destructor called for type = " << type << "\n";
    delete _brain;
}

void	Dog::makeSound() const
{
    std::cout << "Woof! Woof!\n";
}

void    Dog::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        _brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (_brain->getIdea(index));
    return ("");
}