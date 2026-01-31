/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:01:27 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 13:02:37 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;
	protected:
		virtual void	executeAction() const;
	public :
		static const int	gradeToSign = 72;
		static const int	gradeToExecute = 45;
		
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& src);
		virtual ~RobotomyRequestForm();
		
		const std::string&	getTarget() const;
	};

#endif