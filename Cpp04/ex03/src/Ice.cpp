/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:46:33 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 10:25:27 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice& src) : AMateria(src) {}

Ice& Ice::operator=(const Ice& src)
{
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

Ice::~Ice() {}


void    Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";}
AMateria*   Ice::clone() const { return (new Ice(*this)); }