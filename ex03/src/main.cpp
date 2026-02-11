/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:07:35 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 14:07:46 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#include <iostream>

int main()
{
	std::cout << "=== Creating Bureaucrats ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat mid("Mid", 50);
	Bureaucrat internB("Intern", 150);

	std::cout << std::endl << "=== Intern creates valid forms ===" << std::endl;
	Intern someRandomIntern;

	AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm* robo  = someRandomIntern.makeForm("robotomy request", "Bender");
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

	std::cout << std::endl << "=== Intern tries invalid form ===" << std::endl;
	AForm* invalid = someRandomIntern.makeForm("coffee request", "Office");

	std::cout << std::endl << "=== Signing & executing forms ===" << std::endl;

	if (shrub)
	{
		internB.signForm(*shrub);
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
	}

	std::cout << std::endl;

	if (robo)
	{
		mid.signForm(*robo);
		internB.executeForm(*robo);
		boss.executeForm(*robo);
	}

	std::cout << std::endl;

	if (pardon)
	{
		mid.signForm(*pardon);
		boss.signForm(*pardon);
		mid.executeForm(*pardon);
		boss.executeForm(*pardon);
	}

	std::cout << std::endl << "=== Cleaning up ===" << std::endl;
	delete shrub;
	delete robo;
	delete pardon;
	delete invalid;

	return 0;
}
