/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:42:19 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 16:34:42 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

const int FragTrap::defaultHP;
const int FragTrap::defaultEP;
const int FragTrap::defaultAD;

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called for " << _name << "\n";
	_hitPoints = defaultHP;
	_energyPoints = defaultEP;
	_attackDamage = defaultAD;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor called for " << _name << "\n";
	_hitPoints = defaultHP;
	_energyPoints = defaultEP;
	_attackDamage = defaultAD;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called\n";
	//nothing to do yet as FragTrap has no own varables;
}

FragTrap&	FragTrap::operator=(const FragTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "FragTrap assignment operator called\n";
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for: " << _name << "\n";
}

void	FragTrap::status() const 
{
    std::cout << "===== FragTrap Status =====\n"
              << "Name:          " << _name << "\n"
              << "Hit Points:    " << _hitPoints << "\n"
              << "Energy Points: " << _energyPoints << "\n"
              << "Attack Damage: " << _attackDamage << "\n"
              << "===========================\n\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (checkIfDead(_hitPoints, _name))
		return ;
	std::cout << "FragTrap " << _name << " requests a positive high five!\n";
}