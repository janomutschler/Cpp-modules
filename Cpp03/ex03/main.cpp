/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:57:59 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 16:41:27 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "create DiamondTrap:\n";
	DiamondTrap	a("dia");
	DiamondTrap b("sec");
	a.status();
	std::cout << "\ncopy constructor DiamondTrap:\n";
	DiamondTrap x(b);
	x.status();
	std::cout << "\nassignment operator DiamondTrap:\n";
	x = a;
	x.status();
	std::cout << "\nattack:\n";
	x.attack("Enemy");
	x.status();
	std::cout << "\nbeRepaired:\n";
	x.beRepaired(5);
	x.status();
	std::cout << "\nScav special func guardGate:\n";
	x.guardGate();
	std::cout << "\nFrag special func highFiveGuys:\n";
	x.highFivesGuys();
	std::cout << "\ntakeDamage\n";
	x.takeDamage(35);
	x.status();
	std::cout << "\ntake to much damage\n";
	x.takeDamage(6457567);
	std::cout << "\ndestructors:\n";
    return 0;
}

