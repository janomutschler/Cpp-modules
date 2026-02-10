/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:01:51 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 13:02:47 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <exception>

int main(int argc, char** argv)
{
	try
	{
		if (argc < 2)
			throw std::runtime_error("Error: not enough arguments");

		PmergeMe pm(argc, argv);
		pm.run();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
