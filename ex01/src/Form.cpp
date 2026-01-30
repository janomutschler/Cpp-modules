/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:48:36 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/30 14:03:05 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <ostream>

//Exceptions 
const char* Form::GradeTooHighException::what()			const throw() {return "Grade too high";}
const char* Form::GradeTooLowException::what()			const throw() {return "Grade too low";}
const char* Form::FormAlreadySignedException::what()	const throw() {return "Form is already signed";}

//Constructors, copy assignement operator and deconstructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(lowestGrade), _gradeToExecute(lowestGrade) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < highestGrade || gradeToExecute < highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > lowestGrade || gradeToExecute > lowestGrade)
		throw GradeTooLowException();
}

Form::Form(const Form& src) :
	_name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

Form&	Form::operator=(const Form& src)
{
	if (this != &src) {this->_isSigned = src._isSigned;}
	return (*this);
}

Form::~Form() {}

//getter functions
const std::string&	Form::getName()				const {return (_name);}
bool				Form::getIsFormSigned()		const {return (_isSigned);}
int					Form::getGradeToSign()		const {return (_gradeToSign);}
int					Form::getGradeToExecute()	const {return (_gradeToExecute);}

void	Form::beSigned(const Bureaucrat& b)
{
	if (_isSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream&	operator<<(std::ostream& os, const Form& f)
{
	os	<< "Form " << f.getName()
		<< " [signed: " << (f.getIsFormSigned() ? "yes" : "no")
		<< ", gradeToSign: " << f.getGradeToSign()
		<< ", gradeToExecute: " << f.getGradeToExecute()
		<< "]";

	return (os);
}