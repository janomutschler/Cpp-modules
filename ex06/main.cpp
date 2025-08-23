/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:09:18 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/23 18:01:25 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static int	get_level(const std::string& level)
{
	static const std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int	i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <DEBUG|INFO|WARRNING|ERROR> (prog only takes one argument)\n";
		return (1);
	}
	Harl		harl;
	const int	level = get_level(argv[1]);
	switch (level)
	{
		case 0:
			std::cout << "[ DEBUG ]\n";
			harl.complain("DEBUG");
			std::cout << "\n";
		// fall through
		case 1:
			std::cout << "[ INFO ]\n";
			harl.complain("INFO");
			std::cout << "\n";
		// fall through
		case 2:
			std::cout << "[ WARNING ]\n";
			harl.complain("WARNING");
			std::cout << "\n";
		// fall through
		case 3:
			std::cout << "[ ERROR ]\n";
			harl.complain("ERROR");
			std::cout << "\n";
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return (0);
}