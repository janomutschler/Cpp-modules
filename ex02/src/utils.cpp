/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:32:21 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 18:51:50 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "utils.hpp"
#include <iostream>

void	PmergeMe::printBefore() const
{
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void	PmergeMe::printAfter() const
{
	std::cout << "After:";
	for (size_t i = 0; i < _vec.size(); ++i)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

double	PmergeMe::getTimeDiff(clock_t start, clock_t end) const
{
	// clock() gives CPU time in ticks; convert to microseconds
	return ((static_cast<double>(end - start) * 1000000.0) / CLOCKS_PER_SEC);
}

void	swap(Node& a, Node& b)
{
	Node	temp = a;
	a = b;
	b = temp;
}

bool	ordered(const Node& lhs, const Node& rhs)
{
	if (lhs.value != rhs.value)
		return lhs.value < rhs.value;
	return (lhs.id < rhs.id);
}