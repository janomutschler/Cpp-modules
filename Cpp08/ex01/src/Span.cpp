/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:06:14 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/08 14:00:59 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int N) : _max(N)
{
	_numbers.reserve(_max);
}

Span::Span(const Span& src) : _numbers(src._numbers), _max(src._max) {}

Span& Span::operator=(const Span& src)
{
	if (this != &src)
	{
		this->_numbers = src._numbers;
		this->_max = src._max;
		_numbers.reserve(_max);
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int n)
{
    if (_numbers.size() >= _max)
        throw std::out_of_range("Span is full");
    _numbers.push_back(n);
}
 
// return the shortest span between any two numbers
// by sorting the vector and then finding the shortest span between neighboring numbers
//(need to first create a temp of the _numbers vec as we dont wanna modify it and this func is const)
int	Span::shortestSpan()	const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements");

	std::vector<int>	temp(_numbers);
	std::sort(temp.begin(), temp.end());
	
	int	minSpan = temp[1] - temp[0];
	for (size_t i = 1; i < (temp.size() - 1); i++)
	{
		int	curSpan = temp[i + 1] - temp[i];
		if (minSpan > curSpan)
			minSpan = curSpan;
	}

	return (minSpan);
}

// function gets the largest span between any two numbers in Span _numbers
// it get the min and max element by using the func min_element and max_element
// the result of these functions is a iterator (pointer) pointing at an int
// therefor we derefrence it and store it in a int and retrun the span between min and max
int	Span::longestSpan()	const
{
	if (_numbers.size() < 2)
		throw std::logic_error("Not enough elements");

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (max - min);
}