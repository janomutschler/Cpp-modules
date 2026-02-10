/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:01:10 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 18:54:12 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <algorithm>

// Default constructor
PmergeMe::PmergeMe()
	: _vec()
	, _deq()
	, _vecTime(0.0)
	, _deqTime(0.0)
{
}

// Parsing constructor
PmergeMe::PmergeMe(int argc, char** argv)
	: _vec()
	, _deq()
	, _vecTime(0.0)
	, _deqTime(0.0)
{
	parseInput(argc, argv);
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& src)
	: _vec(src._vec)
	, _deq(src._deq)
	, _vecTime(src._vecTime)
	, _deqTime(src._deqTime)
{
}

// Copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != &src)
	{
		_vec = src._vec;
		_deq = src._deq;
		_vecTime = src._vecTime;
		_deqTime = src._deqTime;
	}
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe() {}

static bool isSortedDeq(const std::deque<int>& d)
{
	if (d.size() < 2)
		return true;

	for (size_t i = 1; i < d.size(); ++i)
	{
		if (d[i - 1] > d[i])
			return false;
	}
	return true;
}

static bool isSorted(const std::vector<int>& v)
{
	if (v.size() < 2)
		return true;

	for (size_t i = 1; i < v.size(); ++i)
	{
		if (v[i - 1] > v[i])
			return false;
	}
	return true;
}

void	PmergeMe::run()
{
	printBefore();

	clock_t start;
	clock_t end;

	// VECTOR
	start = std::clock();
	sortVector();
	end = std::clock();
	_vecTime = getTimeDiff(start, end);

	// DEQUE
	start = std::clock();
	sortDeque();
	end = std::clock();
	_deqTime = getTimeDiff(start, end);

	if (!isSorted(_vec) || !isSortedDeq(_deq))
		throw std::runtime_error("Error");
	printAfter();
	// Timing output
	std::cout << "Time to process a range of " << _vec.size()
	          << " elements with std::vector : " << _vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
	          << " elements with std::deque  : " << _deqTime << " us" << std::endl;
}