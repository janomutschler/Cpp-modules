/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:28:17 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/12 09:33:03 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm() : 	
AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target("Default Target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) :
AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
AForm(src), _target(src.getTarget()) {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
 	
const std::string&	ShrubberyCreationForm::getTarget() const {return (_target);}

void	ShrubberyCreationForm::executeAction() const
{
	const std::string	filename = _target + "_shrubbery";
    std::ofstream out(filename.c_str());

    if (!out.is_open())
        throw std::runtime_error("could not open shrubbery file");

    out <<
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\             /\n"
"   ~  \\\\ //  ~\n"
"       | |\n"
"       | |\n"
"      // \\\\\n";

    out.close();
}