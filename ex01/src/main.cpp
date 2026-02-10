/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 09:15:44 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/10 09:19:37 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN  \"inverted Polish mathematical expression\"" << std::endl;
		return 1;
	}

	try{
		RPN rpn;
		std::cout << rpn.evaluate(argv[1]) << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
