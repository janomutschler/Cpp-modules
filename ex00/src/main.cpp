/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 10:14:46 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/04 17:42:36 by jmutschl         ###   ########.fr       */
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
    // If user provides args, test those only
    if (argc > 1)
    {
        for (int i = 1; i < argc; ++i)
            run(argv[i]);
        return 0;
    }

    // --- Char inputs ---
    run("a");
    run("Z");
    run("!");
    run("0");        // should be int, not char
    run(" ");        // space as char (displayable)
    // Note: non-displayable char inputs are not supposed to be provided by subject.

    // --- Int inputs ---
    run("42");
    run("-42");
    run("+42");
    run("1");        // int
    run("127");      // DEL (non-displayable when cast to char)
    run("31");       // non-displayable char
    run("32");       // space
    run("-2");       // char: impossible

    // INT boundaries (assumes 32-bit int as usual at 42; still useful)
    run("2147483647");   // INT_MAX
    run("-2147483648");  // INT_MIN
    run("2147483648");   // just above INT_MAX -> int impossible

    // too large for long on many systems -> should become invalid (all impossible)
    run("999999999999999999999999999999999999");

    // --- Double inputs ---
    run("42.0");
    run("-42.0");
    run("0.0");
    run("1.5");
    run("127.0");    // char boundary
    run("128.0");    // char impossible
    run("-0.0");     // check formatting/behavior

    // --- Float inputs ---
    run("42.0f");
    run("-42.0f");
    run("0.0f");
    run("1.5f");
    run("127.112466f");
    run("128.3678997f");

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
    run(".");        // depending on your validator: likely invalid
    run("..");
    run("+-42");
    run("42-");
    run(" 42");      // leading whitespace (invalid)
    run("42 ");      // trailing whitespace (invalid)

    return 0;
}
