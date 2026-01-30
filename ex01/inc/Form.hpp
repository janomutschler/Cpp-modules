/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:21 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/30 13:02:44 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iosfwd>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	
	public:
		static const int	highestGrade = 1;
		static const int	lowestGrade = 150;

		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		const std::string&	getName()			const;
		bool				getIsFormSigned()	const;
		int					getGradeToSign()	const;
		int					getGradeToExecute()	const;

		void	beSigned(const Bureaucrat& b);

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
};

std::ostream&	operator<<(std::ostream& os, const Form& b);

#endif