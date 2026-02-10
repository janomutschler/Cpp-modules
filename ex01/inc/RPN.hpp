/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:15:58 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 09:15:59 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<int>	_stack;

		void	processToken(char token);
		void	applyOperator(char op);

	public:
		RPN();
		RPN(const RPN& srcr);
		RPN& operator=(const RPN& src);
		~RPN();

		int		evaluate(const std::string& expression);
};

#endif
