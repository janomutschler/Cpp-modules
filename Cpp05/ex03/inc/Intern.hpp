/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:05:34 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 14:05:23 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		static AForm*	createShrubbery(const std::string& target);
		static AForm*	createRobotomy(const std::string& target);
		static AForm*	createPresidential(const std::string& target);
		
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& src);
		~Intern();
		
		AForm*	makeForm(const std::string& name, const std::string& target);
};

#endif