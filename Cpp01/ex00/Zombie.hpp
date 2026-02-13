/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:17:37 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/22 08:56:12 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
  std::string _name;
public:
  explicit Zombie(const std::string &name);
  ~Zombie();
  void announce() const;
};

Zombie* newZombie(const std::string &name);
void    randomChump(const std::string &name);

#endif