/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:46:30 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 10:25:39 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure& src) : AMateria(src) {}

Cure& Cure::operator=(const Cure& src)
{
    if (this != &src)
        AMateria::operator=(src);
    return (*this);
}

Cure::~Cure() {}

void    Cure::use(ICharacter& target) { std::cout << "* heals " << target.getName() << "'s wounds *\n";}
AMateria*   Cure::clone() const { return (new Cure(*this)); }