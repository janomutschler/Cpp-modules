/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 15:23:55 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 16:36:15 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("DefaultDiamondTrap_clap_name"), ScavTrap("DefaultDiamondTrap"), FragTrap("DefaultDiamondTrap"), _name("DefaultDiamondTrap")
{
	_hitPoints    = FragTrap::defaultHP;
	_energyPoints = ScavTrap::defaultEP;
	_attackDamage = FragTrap::defaultAD;
	std::cout << "DiamondTrap  default constructor called for: " << _name << "\n";
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_hitPoints    = FragTrap::defaultHP;
	_energyPoints = ScavTrap::defaultEP;
	_attackDamage = FragTrap::defaultAD;
	std::cout << "DiamondTrap constructor called for: " << _name << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	_hitPoints    = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;
	std::cout << "DiamondTrap copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	if (this != &src)
	{
		ClapTrap::operator=(src);
		ScavTrap::operator=(src);
		FragTrap::operator=(src);
		_name = src._name;
		_hitPoints = src._hitPoints;
		_energyPoints = src._energyPoints;
		_attackDamage = src._attackDamage;
	}
	 std::cout << "DiamondTrap copy assignment operator called\n";
	 return (*this);
}

DiamondTrap::~DiamondTrap() { std::cout << "DiamondTrap destructor called for: " << _name << "\n"; }

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name
              << " | ClapTrap name: " << ClapTrap::_name << "\n";
}

void DiamondTrap::status() const
{
	if (checkIfDead(_hitPoints, _name))
		return ;
    std::cout << "[STATUS] "
              << "DiamondTrap name: " << _name
              << " | ClapTrap name: " << ClapTrap::_name
              << " | HP: " << _hitPoints
              << " | EP: " << _energyPoints
              << " | AD: " << _attackDamage
              << "\n";
}