/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:08:03 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 19:20:00 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <stdexcept>
#include <cstdlib>
#include <cerrno>
#include <climits>

static int	parseNumber(const std::string& s)
{
	if (s.empty())
		throw std::runtime_error("Error: Empty argument");

	// Disallow negative sign
	if (s[0] == '-')
		throw std::runtime_error("Error: negative numbers are not allowed");

	// Allow leading '+'
	size_t start = 0;
	if (s[0] == '+')
	{
		if (s.size() == 1)
			throw std::runtime_error("Error: Invalid input.");
		start = 1;
	}

	// Ensure remaining chars are digits only
	for (size_t i = start; i < s.size(); ++i)
	{
		if (s[i] < '0' || s[i] > '9')
			throw std::runtime_error("Error:  Invalid input.");
	}

	errno = 0;
	char* end = 0;
	long n = std::strtol(s.c_str(), &end, 10);

	// strtol checks
	if (errno != 0 || end == 0 || *end != '\0')
		throw std::runtime_error("Error");

	// overflow check 
	if (n <= 0 || n > INT_MAX)
		throw std::runtime_error("Error: Number to large or 0");

	return (static_cast<int>(n));
}

void	PmergeMe::parseInput(int argc, char** argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	_vec.clear();
	_deq.clear();

	for (int i = 1; i < argc; ++i)
	{
		int value = parseNumber(std::string(argv[i]));
		_vec.push_back(value);
		_deq.push_back(value);
	}

	if (_vec.empty())
		throw std::runtime_error("Error");
}


