/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:25:28 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 16:35:08 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

const int ScavTrap::defaultHP;
const int ScavTrap::defaultEP;
const int ScavTrap::defaultAD;

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called for " << _name << "\n";
	_hitPoints = defaultHP;
	_energyPoints = defaultEP;
	_attackDamage = defaultAD;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called for " << _name << "\n";
	_hitPoints = defaultHP;
	_energyPoints = defaultEP;
	_attackDamage = defaultAD;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called\n";
	//nothing to do yet as ScavTrap has no own varables;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& src)
{
	if (this != &src)
		ClapTrap::operator=(src);
	std::cout << "ScavTrap assignment operator called\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for: " << _name << "\n";
}

void	ScavTrap::attack(const std::string& target)
{
	if (checkIfDead(_hitPoints, _name) || checkIfExhausted(_energyPoints, _name))
		return ;
	--_energyPoints;
	std::cout	<< "ScavTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attackDamage
				<< " points of damage!\n";
}

void	ScavTrap::guardGate()
{
	if (checkIfDead(_hitPoints, _name))
		return ;
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}

void	ScavTrap::status() const 
{
    std::cout << "===== ScavTrap Status =====\n"
              << "Name:          " << _name << "\n"
              << "Hit Points:    " << _hitPoints << "\n"
              << "Energy Points: " << _energyPoints << "\n"
              << "Attack Damage: " << _attackDamage << "\n"
              << "===========================\n\n";
}