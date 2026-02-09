/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchangeDatabase.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 16:57:24 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/09 17:03:44 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <sstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

static bool parseCsvLine(const std::string& line, std::string& dateOut, double& rateOut)
{
    // expected: "YYYY-MM-DD,123.45"
    std::size_t	comma = line.find(',');
    if (comma == std::string::npos)
        return (false);

    std::string			date = line.substr(0, comma);
    std::string			rateStr = line.substr(comma + 1);

    std::istringstream	iss(rateStr);
    double				rate;
    if (!(iss >> rate))
        return (false);

    dateOut = date;
    rateOut = rate;
    return (true);
}

void	BitcoinExchange::loadDatabase(const std::string& filename)
{
	
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open database file.");
	
	std::map<std::string, double>&	db = _db;
	std::string line;
	// skip header if present
	if (std::getline(file, line))
	{
		if (line != "date,exchange_rate")
		{
			std::string	date;
			double		rate;
			if (parseCsvLine(line, date, rate))
				db[date] = rate;
		}
	}

	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string	date;
		double		rate;
		if (!parseCsvLine(line, date, rate))
			continue;

        db[date] = rate;
    }
}