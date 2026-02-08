/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 10:06:11 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/08 14:51:14 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <list>

int main()
{
    try
    {
        const unsigned int N = 50000;
        Span sp(N);

        std::srand(std::time(NULL));

		unsigned int i = 0;
        std::vector<int>	values;
        for (; i < (N / 2); ++i)
            values.push_back(std::rand());
        sp.addNumber(values.begin(), values.end());
		
		std::list<int>		lst;
        for (; i < (N - 1); ++i)
			lst.push_back(std::rand());
		sp.addNumber(lst.begin(), lst.end());
		
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span:  " << sp.longestSpan() << std::endl;

        // test overflow
        try {
            sp.addNumber(42);
			std::cout << "Added succesfully" <<std::endl;
        } catch (const std::exception& e) {
            std::cout << "Should not give exception: " << e.what() << std::endl;
        }
		try {
            sp.addNumber(-42);
        } catch (const std::exception& e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
