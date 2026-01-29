/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:36:21 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/29 15:45:11 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define Form_HPP

#include <string>
#include <iostream>
#include <exception>

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		void	signForm();
	
	public:
		Form();
		explicit Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& src);
		Form& operator=(const Form& src);
		~Form();

		const std::string&	getName()			const;
		bool				getIsFormSigned()	const;
		const int			getGradeToSign()	const;
		const int			getGradeToExecute()	const;

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
};
#endif