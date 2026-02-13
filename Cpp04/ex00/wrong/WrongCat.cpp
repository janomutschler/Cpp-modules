/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:51 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/31 14:29:11 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() 
{
    type = "WrongCat";
    std::cout << "WrongCat: Default Constructor called for type = " << type << "\n";
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src) 
{
    *this = src;
    std::cout << "WrongCat: Copy Constructor called for type = " << type << "\n";
}

WrongCat& WrongCat::operator=(const WrongCat& src) 
{
    std::cout << "WrongCat: Assignment operator called\n";
    if (this != &src) {
        this->type = src.type;
    }
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat: Destructor called for type = " << type << "\n";
}

void	WrongCat::makeSound() const
{
    std::cout << "Wrong Miao! Miao!\n";
}