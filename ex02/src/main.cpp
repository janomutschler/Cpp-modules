/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:48:02 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 12:15:18 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "=== Basic int array ===" << std::endl;
    Array<int> a(3);
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;

    std::cout << "\n=== Copy test ===" << std::endl;
    Array<int> b = a;
    b[1] = 99;
    std::cout << "a[1] = " << a[1] << " (should be 20)" << std::endl;
    std::cout << "b[1] = " << b[1] << " (should be 99)" << std::endl;

    std::cout << "\n=== Const access ===" << std::endl;
    const Array<int> c = a;
    std::cout << "c[0] = " << c[0] << std::endl;

    std::cout << "\n=== Out of bounds ===" << std::endl;
    try
    {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== String array ===" << std::endl;
    Array<std::string> s(2);
    s[0] = "hello";
    s[1] = "world";
    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << s[i] << std::endl;

    return (0);
}
