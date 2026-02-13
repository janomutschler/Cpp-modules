/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 12:25:24 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/30 16:33:33 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
class ScavTrap : public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& src);
		ScavTrap& operator=(const ScavTrap& src);
		~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();

		void	status() const;

		static const int	defaultHP = 100;
		static const int	defaultEP = 50;
		static const int	defaultAD = 20;
};

bool	checkIfDead(const int& hp, const std::string& name);
bool	checkIfExhausted(const int& ep, const std::string& name);

#endif
