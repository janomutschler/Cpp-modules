/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:34:31 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/29 11:07:44 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {return "Grade too high";}

const char* Bureaucrat::GradeTooLowException::what() const throw() {return "Grade too low";}

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(lowestGrade)
{
	std::cout << "Bureaucrat default Constructor called for: " << _name << " with grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < highestGrade)
		throw GradeTooHighException();
	if (grade > lowestGrade)
		throw GradeTooLowException();
	std::cout << "Bureaucrat Constructor called for: " << _name << " with grade: " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		this->_name = src._name;
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string&	Bureaucrat::getName() const {return (_name);}

int	Bureaucrat::getGrade()	const {return (_grade);}

void	Bureaucrat::incrementGrade()
{
	if ((_grade - 1) < highestGrade)
		throw GradeTooHighException();
	_grade--;
}


void	Bureaucrat::decrementGrade()
{
	if ((_grade + 1) > lowestGrade)
		throw GradeTooLowException();
	_grade++;
}
