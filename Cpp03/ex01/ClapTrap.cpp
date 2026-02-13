/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:57:56 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 15:01:58 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <climits>
#include <iostream>

static const int	defaultHP = 10;
static const int	defaultEP = 10;
static const int	defaultAD = 0;

ClapTrap::ClapTrap() : _name("Default ClapTrap"), _hitPoints(defaultHP), _energyPoints(defaultEP), _attackDamage(defaultAD)
{
	std::cout << "ClapTrap default constructor called for: " << _name << "\n";
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(defaultHP), _energyPoints(defaultEP), _attackDamage(defaultAD)
{
	std::cout << "ClapTrap constructor called for: " << name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap& src) : _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints),
											_attackDamage(src._attackDamage)
{
	std::cout << "ClapTrap copy constructor called\n";
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& src)
{
	std::cout << "ClapTrap assignment operator called\n";
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for: " << _name << "\n\n";
}

bool	checkIfDead(const int& hp, const std::string& name)
{
	if (!hp)
	{
		std::cout << "ClapTrap: " << name << " is dead\n";
		return (true);
	}
	return (false);
}

bool	checkIfExhausted(const int& ep, const std::string& name)
{
	if (!ep)
	{
		std::cout << "ClapTrap: " << name << " has no energy points left\n";
		return (true);
	}
	return (false);
}

void	ClapTrap::attack(const std::string& target)
{
	if (checkIfDead(_hitPoints, _name) || checkIfExhausted(_energyPoints, _name))
		return ;
	--_energyPoints;
	std::cout	<< "ClapTrap " << _name
				<< " attacks " << target
				<< ", causing " << _attackDamage
				<< " points of damage!\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (checkIfDead(_hitPoints, _name) || checkIfExhausted(_energyPoints, _name))
		return ;
	if (amount > static_cast<unsigned int>(INT_MAX - _hitPoints))
	_hitPoints = INT_MAX;
	else
		_hitPoints += static_cast<int>(amount);
	--_energyPoints;
	std::cout	<< "ClapTrap " << _name
				<< " repairs itself by " << amount
				<< " hit points.\n"
				<< "ClapTrap HP: " << _hitPoints << "\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (checkIfDead(_hitPoints, _name))
		return ;
	if (amount >= static_cast<unsigned int>(_hitPoints))
	{
		_hitPoints = 0;
		std::cout	<< "ClapTrap " << _name
					<< " takes " << amount
					<< " damage and dies\n";
	}
	else
	{
		_hitPoints -= static_cast<int>(amount);
		std::cout	<< "ClapTrap " << _name
					<<" takes " << amount << " damage\n"
					<< "ClapTrap HP: " << _hitPoints << "\n";
	}
}

void	ClapTrap::status() const 
{
    std::cout << "===== ClapTrap Status =====\n"
              << "Name:          " << _name << "\n"
              << "Hit Points:    " << _hitPoints << "\n"
              << "Energy Points: " << _energyPoints << "\n"
              << "Attack Damage: " << _attackDamage << "\n"
              << "===========================\n\n";
}
