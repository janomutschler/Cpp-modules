/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:09:32 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/09 19:04:04 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iostream>


BitcoinExchange::BitcoinExchange() 
{
	loadDatabase("data.csv");
	if (_db.empty())
		throw std::runtime_error("Error: empty database.");
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile)
{
	loadDatabase(csvFile);
	if (_db.empty())
		throw std::runtime_error("Error: empty database.");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
	: _db(src._db) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	if (this != &src)
		_db = src._db;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string& str)
{
    std::string::size_type start = 0;
    std::string::size_type end = str.length();

    while (start < end && std::isspace(static_cast<unsigned char>(str[start])))
        ++start;
	
    while (end > start && std::isspace(static_cast<unsigned char>(str[end - 1])))
        --end;

    return str.substr(start, end - start);
}

void	BitcoinExchange::processLine(const std::string& line)	const
{
    std::size_t	bar = line.find('|');
    if (bar == std::string::npos)
    {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	
    std::string			date = trim(line.substr(0, bar));
    std::string			valueStr = trim(line.substr(bar + 1));
	std::istringstream	iss(valueStr);
	double				value;
	
	if (!isValidDate(date) || !(iss >> value))
    {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string extra;
    if (iss >> extra) //trailing junk
    {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
	
	if (!isValidValue(value))
		return ;

    try
    {
        double rate = getRateOnOrBefore(date);
        std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Error: no Data before or at this Date => " << date << std::endl;
    }
}

void	BitcoinExchange::processFile(const std::string& inputFile) const
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	
	std::string	line;
	if (std::getline(file, line))
    {
        if (line != "date | value")
			processLine(line);
    }
	
	while (std::getline(file, line))
	{
		if (line.empty())
            continue;
		processLine(line);
	}
}