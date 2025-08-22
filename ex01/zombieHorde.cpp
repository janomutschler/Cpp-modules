/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:05:48 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/21 12:23:28 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, const std::string name )
{
	if (N <= 0)
	{
		std::cout << "zombie amount is 0 or less\n";
		return (0);
	}
	Zombie* horde = new (std::nothrow) Zombie[N];
	if (!horde)
	{
		std::cout << "ALLOCATION FAILED\n";
		return (0);
	}
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (horde);
}