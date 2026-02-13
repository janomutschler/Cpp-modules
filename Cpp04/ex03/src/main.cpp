/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:46:17 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 13:46:16 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "\nDeep Copy tests and unequip:\n";
    std::cout << "First we assign a new charector you:\n";
    ICharacter* you = new Character("you");
    you->use(0, *bob);
    std::cout << "As we didnt assign anything to b yet it doesnt have anything stored so now we assign it to me:\n";
    *you = *me;
    you->use(0, *bob);
    you->use(1, *bob);
    std::cout << "so now you have the same abilitys as me but they are different elements so when we unequip you me still holds his slots\n";
    you->unequip(0);
    you->use(0, *bob);
    me->use(0, *bob);
    delete bob;
    delete me;
    delete you;
    delete src;
    return 0;
}

