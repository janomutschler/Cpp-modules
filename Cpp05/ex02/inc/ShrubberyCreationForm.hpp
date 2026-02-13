/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:25:42 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 11:29:23 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
	protected:
		virtual void	executeAction() const;
	public :
		static const int	gradeToSign = 145;
		static const int	gradeToExecute = 137;
		
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& src);
		virtual ~ShrubberyCreationForm();
		
		const std::string&	getTarget() const;
	};

#endif