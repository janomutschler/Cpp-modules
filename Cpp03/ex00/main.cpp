/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:57:59 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 12:13:32 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap a("first");
	ClapTrap b("second");
	ClapTrap x(a);

	x.status();
	x = b;
	x.status();
	x.attack("Enemy");
	x.status();
	x.beRepaired(3);
	x.status();
	x.takeDamage(5);
	x.status();
	x.takeDamage(4044444444);
}
