/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:45 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 06:50:50 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    const int size = 6;
    Animal* zoo[size];

    for (int i = 0; i < size / 2; i++) zoo[i] = new Dog();
    for (int i = size / 2; i < size; i++) zoo[i] = new Cat();

    for (int i = 0; i < size; i++) {
        zoo[i]->makeSound();
        delete zoo[i];
    }

    std::cout << "Deep copy check:\n";
    Dog a;
    a.setIdea(0, "chase a stick");
    std::cout << "Dog A: Idea 0 = " << a.getIdea(0) << "\n";
    
    std::cout << "\nCopy constructore check\n";
    Dog b(a);
    std::cout << "Dog A: Idea 0 = " << a.getIdea(0) << "\n";
    std::cout << "Dog B: Idea 0 = " << b.getIdea(0) << "\n";
    std::cout << "now we change the idea of dog b as they both have there own brain it should only change b\n";
    b.setIdea(0, "chase my own tail");
    std::cout << "Dog A: Idea 0 = " << a.getIdea(0) << "\n";
    std::cout << "Dog B: Idea 0 = " << b.getIdea(0) << "\n";
    
    std::cout << "\nAssignment operator check\n";
    Dog c;
    c = a;
    std::cout << "Dog A: Idea 0 = " << a.getIdea(0) << "\n";
    std::cout << "Dog C: Idea 0 = " << c.getIdea(0) << "\n";
    std::cout << "\nnow we change the idea of dog c as they both have there own brain it should only change c\n";
    c.setIdea(0, "chase my own tail");
    std::cout << "Dog A: Idea 0 = " << a.getIdea(0) << "\n";
    std::cout << "Dog C: Idea 0 = " << c.getIdea(0) << "\n\n";

    Animal fail;
    return 0;
}

