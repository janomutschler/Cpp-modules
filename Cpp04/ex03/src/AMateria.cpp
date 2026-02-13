/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:46:23 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 10:13:37 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() : _type("unknown") {}
AMateria::AMateria(std::string const& type) : _type(type) {}
AMateria::AMateria(const AMateria& src) : _type(src._type) {}

AMateria& AMateria::operator=(const AMateria& src)
{
    if (this != &src) {
        this->_type = src._type;
    }
    return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const { return (_type); }
void    AMateria::use(ICharacter& target) { (void)target; }