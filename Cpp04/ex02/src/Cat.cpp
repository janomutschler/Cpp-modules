/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:39 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 06:21:27 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() 
{
    type = "Cat";
    std::cout << "Cat: Default Constructor called for type = " << type << "\n";
    _brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src) 
{
    std::cout << "Cat: Copy Constructor called for type = " << type << "\n";
    _brain = new Brain(*src._brain);
    type = src.type;
}

Cat& Cat::operator=(const Cat& src) 
{
    std::cout << "Cat: Assignment operator called\n";
    if (this != &src)
    {
        Animal::operator=(src);
        delete _brain;
        _brain = new Brain(*src._brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called for type = " << type << "\n";
    delete _brain;
}

void	Cat::makeSound() const
{
    std::cout << "Miao! Miao!\n";
}

void    Cat::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        _brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (_brain->getIdea(index));
    return ("");
}