#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <ostream>

//Exceptions 
const char* AForm::GradeTooHighException::what()		const throw() {return "Grade too high";}
const char* AForm::GradeTooLowException::what()			const throw() {return "Grade too low";}
const char* AForm::FormAlreadySignedException::what()	const throw() {return "Form is already signed";}
const char* AForm::FormNotSignedException::what()		const throw() {return "Form needs to be signed before execution";}

//Constructors, copy assignement operator and deconstructor
AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(lowestGrade), _gradeToExecute(lowestGrade) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
	_name(name), _isSigned(false),
	_gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < highestGrade || gradeToExecute < highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > lowestGrade || gradeToExecute > lowestGrade)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& src) :
	_name(src._name), _isSigned(src._isSigned),
	_gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm&	AForm::operator=(const AForm& src)
{
	if (this != &src) {this->_isSigned = src._isSigned;}
	return (*this);
}

AForm::~AForm() {}

//getter functions
const std::string&	AForm::getName()			const {return (_name);}
bool				AForm::getIsFormSigned()	const {return (_isSigned);}
int					AForm::getGradeToSign()		const {return (_gradeToSign);}
int					AForm::getGradeToExecute()	const {return (_gradeToExecute);}

void	AForm::beSigned(const Bureaucrat& b)
{
	if (_isSigned)
		throw FormAlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}
void	AForm::execute(const Bureaucrat& b) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (b.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

std::ostream&	operator<<(std::ostream& os, const AForm& f)
{
	os	<< "AForm " << f.getName()
		<< " [signed: " << (f.getIsFormSigned() ? "yes" : "no")
		<< ", gradeToSign: " << f.getGradeToSign()
		<< ", gradeToExecute: " << f.getGradeToExecute()
		<< "]";

	return (os);
}