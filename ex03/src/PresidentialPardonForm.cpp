#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : 	
AForm("PresidentialPardonForm", gradeToSign, gradeToExecute), _target("Default Target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
AForm("PresidentialPardonForm", gradeToSign, gradeToExecute), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
AForm(src), _target(src.getTarget()) {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}
 	
const std::string&	PresidentialPardonForm::getTarget() const {return (_target);}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}