/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:17:08 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/21 12:15:36 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : _name("nameless") {}
Zombie::Zombie(const std::string &name) : _name(name) {}
Zombie::~Zombie() 
{
  std::cout << _name << " is gone...\n";
}

void Zombie::announce() const {
  std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(const std::string &name)
{ 
  _name = name;
}