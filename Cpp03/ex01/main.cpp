/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:57:59 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 15:02:20 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "ScavTrap Tests\n";
	ClapTrap a("first");
	ClapTrap b("second");
	ClapTrap x(a);
	x.status();
	x = b;
	x.status();
	x.attack("Enemy");
	x.status();
	x.beRepaired(3);
	x.status();
	x.takeDamage(5);
	x.status();
	x.takeDamage(4044444444);
	x.beRepaired(5);

	std::cout << "\n\nScavTrap Tests\n";
	ScavTrap sa("first scavtrap");
	ScavTrap sb("second scavtrap");
	ScavTrap sx(sa);
	sx.status();
	sx = sb;
	sx.status();
	sx.attack("Enemy");
	sx.status();
	sa.guardGate();

	std::cout << "\n\nDestructor:\n";
}
