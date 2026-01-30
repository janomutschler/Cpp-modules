/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:53:42 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/30 13:53:43 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== FORM CREATION TESTS ===" << std::endl;

    try {
        Form validForm("Tax Form", 50, 25);
        std::cout << validForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("Invalid Form", 0, 25);
    }
    catch (std::exception& e) {
        std::cout << "Exception (expected): " << e.what() << std::endl;
    }

    std::cout << "\n=== SIGNING TESTS ===" << std::endl;

    Bureaucrat alice("Alice", 40);
    Bureaucrat bob("Bob", 100);

    Form contract("Contract", 50, 20);

    std::cout << alice << std::endl;
    std::cout << bob << std::endl;
    std::cout << contract << std::endl;

    std::cout << "\n-- Bob tries to sign (should fail) --" << std::endl;
    bob.signForm(contract);

    std::cout << "\n-- Alice tries to sign (should succeed) --" << std::endl;
    alice.signForm(contract);

    std::cout << "\n-- Alice tries to sign again (already signed) --" << std::endl;
    alice.signForm(contract);

    std::cout << "\nFinal form state:" << std::endl;
    std::cout << contract << std::endl;

    return 0;
}
