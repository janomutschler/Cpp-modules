/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:09:29 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/09 18:35:07 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_db;

		void	loadDatabase(const std::string& csvFile);

		void	processLine(const std::string& line)	const;
		
		double	getRateOnOrBefore(const std::string& date)	const;

		bool	isValidDate(const std::string& date)	const;
		bool	isValidValue(double value)	const;

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& csvFile);
		BitcoinExchange(const BitcoinExchange& src);
		BitcoinExchange&	operator=(const BitcoinExchange& src);
		~BitcoinExchange();

		void	processFile(const std::string& inputFile) const;
};

#endif
