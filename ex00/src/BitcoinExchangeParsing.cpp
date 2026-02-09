/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeParsing.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:16:09 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/09 20:28:11 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <cstdlib>

bool	BitcoinExchange::isValidValue(double value)	const
{
	if (value < 0.0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (value > 1000.0)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidDate(const std::string& date)	const
{
	if (date.size() != 10)
		return (false);

    if (date[4] != '-' || date[7] != '-')
        return (false);

    for (std::size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return (false);
    }
	int	month = std::atoi(date.substr(5, 2).c_str());
    int	day   = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
        return (false);
	if (day < 1 || day > 31)
        return (false);
	return (true);
}

double	BitcoinExchange::getRateOnOrBefore(const std::string& date)	const
{
	std::map<std::string, double>::const_iterator	it = _db.lower_bound(date);

    // Case 1: exact match
    if (it != _db.end() && it->first == date)
        return (it->second);

    // Case 2: date is after the last known date
    if (it == _db.end())
    {
        std::map<std::string, double>::const_iterator	last = _db.end();
        --last;
        return (last->second);
    }

    // Case 3: date is before the first known date
    if (it == _db.begin())
        throw std::runtime_error("Error: no rate available for date.");

    // Case 4: between entries
    --it;
    return (it->second);
}