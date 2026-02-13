/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:00:54 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 13:00:56 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iosfwd>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	protected:
		virtual void	executeAction() const = 0;
	
	public:
		void	execute(const Bureaucrat& b) const;
		void	beSigned(const Bureaucrat& b);
		
		static const int	highestGrade = 1;
		static const int	lowestGrade = 150;

		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& src);
		AForm& operator=(const AForm& src);
		virtual ~AForm();

		const std::string&	getName()			const;
		bool				getIsFormSigned()	const;
		int					getGradeToSign()	const;
		int					getGradeToExecute()	const;


		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormAlreadySignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif