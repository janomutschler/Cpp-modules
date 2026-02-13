/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:39 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/31 14:08:13 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() 
{
    type = "Cat";
    std::cout << "Cat: Default Constructor called for type = " << type << "\n";
}

Cat::Cat(const Cat& src) : Animal(src) 
{
    *this = src;
    std::cout << "Cat: Copy Constructor called for type = " << type << "\n";
}

Cat& Cat::operator=(const Cat& src) 
{
    std::cout << "Cat: Assignment operator called\n";
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat: Destructor called for type = " << type << "\n";
}

void	Cat::makeSound() const
{
    std::cout << "Miao! Miao!\n";
}