/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:02:21 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 13:02:23 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : 	
AForm("RobotomyRequestForm", gradeToSign, gradeToExecute), _target("Default Target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
AForm("RobotomyRequestForm", gradeToSign, gradeToExecute), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
AForm(src), _target(src.getTarget()) {}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
 	
const std::string&	RobotomyRequestForm::getTarget() const {return (_target);}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRRRR DRRRR DRRRRRR DRILLING NOISES *" << std::endl;
	static bool	seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
	if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}