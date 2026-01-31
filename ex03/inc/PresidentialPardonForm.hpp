/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:01:16 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 13:01:17 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;
	protected:
		virtual void	executeAction() const;
	public :
		static const int	gradeToSign = 25;
		static const int	gradeToExecute = 5;
		
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& src);
		virtual ~PresidentialPardonForm();
		
		const std::string&	getTarget() const;
};

#endif