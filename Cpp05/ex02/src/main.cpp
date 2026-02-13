/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 11:36:12 by jmutschl          #+#    #+#             */
/*   Updated: 2026/01/31 12:01:13 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Creating Bureaucrats ===" << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);
    Bureaucrat mid("Mid", 50);

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;
    std::cout << mid << std::endl;

    std::cout << "\n=== ShrubberyCreationForm tests ===" << std::endl;
    ShrubberyCreationForm shrub("home");

    intern.signForm(shrub);   // should fail
    boss.signForm(shrub);     // should succeed

    intern.executeForm(shrub); // should fail
    boss.executeForm(shrub);   // should succeed (creates file)

    std::cout << "\n=== RobotomyRequestForm tests ===" << std::endl;
    RobotomyRequestForm robot("Bender");

    mid.signForm(robot);      // should succeed (grade 50 <= 72)
    intern.executeForm(robot); // should fail (grade too low)
    boss.executeForm(robot);   // random success/failure

    std::cout << "\n=== PresidentialPardonForm tests ===" << std::endl;
    PresidentialPardonForm pardon("Arthur Dent");

    mid.signForm(pardon);     // should fail (grade too low)
    boss.signForm(pardon);    // should succeed

    mid.executeForm(pardon);  // should fail
    boss.executeForm(pardon); // should succeed

    std::cout << "\n=== Direct exception test (execute unsigned) ===" << std::endl;
    RobotomyRequestForm unsignedForm("Marvin");
    try
    {
        boss.executeForm(unsignedForm); // should throw (not signed)
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}
