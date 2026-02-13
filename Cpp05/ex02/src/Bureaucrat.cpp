/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:54:15 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 11:47:24 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include <iostream>

//Exceptions 
const char* Bureaucrat::GradeTooHighException::what() const throw() {return "Grade too high";}
const char* Bureaucrat::GradeTooLowException::what() const throw() {return "Grade too low";}

//Constructors, copy assignement operator and deconstructor
Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(lowestGrade) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (grade < highestGrade)
		throw GradeTooHighException();
	if (grade > lowestGrade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

//getter functions
const std::string&	Bureaucrat::getName() const {return (_name);}
int					Bureaucrat::getGrade()	const {return (_grade);}

//increment, decrement Bureaucrat Grade
void	Bureaucrat::incrementGrade()
{
	if (_grade <= highestGrade)
		throw GradeTooHighException();
	--_grade;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade >= lowestGrade)
		throw GradeTooLowException();
	++_grade;
}

void	Bureaucrat::signForm(AForm& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< this->getName() << " couldn’t sign " << f.getName()
					<< " because " << e.what() << "." << std::endl;
	}
}
void	Bureaucrat::executeForm(const AForm& f) const
{
	try
	{
		f.execute(*this);
		std::cout << this->getName() << " executed " << f.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout	<< this->getName() << " couldn’t execute " << f.getName()
					<< " because " << e.what() << "." << std::endl;
	}
}
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return (os);
}