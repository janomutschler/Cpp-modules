/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:18:38 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 17:15:59 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::list<int> l;
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Found in vector: " << *it << std::endl;

        std::list<int>::iterator it2 = easyfind(l, 20);
        std::cout << "Found in list: " << *it2 << std::endl;

        easyfind(v, 42); //throw
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    const std::vector<int> cv(v);
    try
    {
        std::vector<int>::const_iterator cit = easyfind(cv, 3);
        std::cout << "Found in const vector: " << *cit << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return (0);
}
