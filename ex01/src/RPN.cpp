/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:16:45 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 09:34:46 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>

RPN::RPN() {}
RPN::RPN(const RPN& other) : _stack(other._stack) {}
RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}
RPN::~RPN() {}

void	RPN::applyOperator(char op)
{
	if (_stack.size() < 2)
		throw std::runtime_error("Error");
	
	int	b = _stack.top();
		_stack.pop();
	int	a = _stack.top();
		_stack.pop();

	if (op == '+')
		_stack.push(a + b);
	else if (op == '-')
		_stack.push(a - b);
	else if (op == '*')
		_stack.push(a * b);
	else if (op == '/')
	{
		if (b == 0)
			throw std::runtime_error("Error division by 0");
		_stack.push(a / b);
	}
}

void	RPN::processToken(char token)
{
	if (token >= '0' && token <= '9')
		_stack.push(token - '0');
	else if (token == '+' || token == '-' || token == '*' || token == '/')
		applyOperator(token);
	else
		throw std::runtime_error("Error");
}

int	RPN::evaluate(const std::string& expression)
{
	for (size_t i = 0; i < expression.length(); i++)
	{
		if (std::isspace(static_cast<unsigned char>(expression[i])))
			continue;
		processToken(expression[i]);
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Invalid RPN expression");

	return (_stack.top());
}
