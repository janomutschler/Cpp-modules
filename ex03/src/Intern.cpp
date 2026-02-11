/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:13:37 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 14:09:36 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}
Intern::Intern(const Intern& src) {(void)src;}
Intern&	Intern::operator=(const Intern& src) {(void)src; return (*this);}
Intern::~Intern() {}
		
AForm* Intern::createShrubbery(const std::string& target){
	return (new ShrubberyCreationForm(target));}
	
AForm* Intern::createRobotomy(const std::string& target){
	return (new RobotomyRequestForm(target));}

AForm* Intern::createPresidential(const std::string& target){
	return (new PresidentialPardonForm(target));}

struct FormEntry
{
	const std::string name;
	AForm* (*create)(const std::string& target);
};

AForm*	Intern::makeForm(const std::string& name, const std::string& target)
{
	FormEntry formTable[] =
	{
		{ "shrubbery creation", &Intern::createShrubbery },
		{ "robotomy request", &Intern::createRobotomy },
		{ "presidential pardon", &Intern::createPresidential }
	};
	for (int i = 0; i < 3; ++i)
	{
		if (formTable[i].name == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (formTable[i].create(target));
		}
	}
	std::cerr << "Intern cannot create form: " << name << std::endl;
	return (NULL);
}