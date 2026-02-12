/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:14:46 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/12 11:07:02 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

static void run(const std::string& lit)
{
    std::cout << "========================================\n";
    std::cout << "Input: " << lit << "\n";
    std::cout << "----------------------------------------\n";
    ScalarConverter::convert(lit);
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
            run(argv[i]);
        return 0;
    }

    run("a");
    run("Z");
    run("!");
    run("0");
    run(" ");

    run("42");
    run("-42");
    run("+42");
    run("1");
    run("127");
    run("31");
    run("32");
    run("-2");

    run("2147483647");
    run("-2147483648");
    run("2147483648");

    // --- Double inputs ---
    run("42.0");
    run("-42.0");
    run("0.0");
    run("1.5");
    run("127.0");
    run("128.0");

    // --- Float inputs ---
    run("42.0f");
    run("-42.0f");
    run("0.0f");
    run("1.5f");
    run("127.0f");
    run("128.0f");

    // --- Pseudo literals ---
    run("nan");
    run("+inf");
    run("-inf");
    run("inf");

    run("nanf");
    run("+inff");
    run("-inff");
    run("inff");

    // --- Invalid inputs ---
    run("hello");
    run("++1");
    run("--1");
    run("1..0");
    run("1.0ff");
    run("f");
    run(".");
    run("..");
    run("+-42");
    run("42-");

    return 0;
}
