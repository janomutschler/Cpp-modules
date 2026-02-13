/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:13:45 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/31 14:31:52 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongAn = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << "Correct Animal dog and cat:\n";
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); 	//output the cat sound;
	j->makeSound(); 	//output the dog sound;
	meta->makeSound();	//output the animal sound;

	delete meta;
	delete j;
	delete i;

	std::cout << "Wro0ng Animal and cat:\n";
	std::cout << wrongAn->getType() << "\n";
	std::cout << wrongCat->getType() << "\n";
	wrongAn->makeSound();
	wrongCat->makeSound();
	
	delete wrongAn;
	delete wrongCat;
	return (0);
}

