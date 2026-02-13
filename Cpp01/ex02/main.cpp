/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:12:49 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/22 08:20:22 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;
	
	std::cout << "Address of str:       " << &str << "\n";
    std::cout << "Address in stringPTR: " << stringPTR << "\n";
    std::cout << "Address in stringREF: " << &stringREF << "\n";

    std::cout << "Value of str:         " << str << "\n";
    std::cout << "Value via stringPTR:  " << *stringPTR << "\n";
    std::cout << "Value via stringREF:  " << stringREF << "\n";
}