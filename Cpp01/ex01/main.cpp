/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:14:05 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/21 12:05:13 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int const amount = 5;
    Zombie* horde = zombieHorde(amount, "hordeeee");
    if (!horde)
		return 1;
    for (int i = 0; i < amount; ++i)
		horde[i].announce();
    delete[] horde;
    return 0;
}