/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:17:37 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/21 12:19:48 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
  private:
    std::string _name;
    
  public:
    Zombie();
    explicit Zombie(const std::string &name);
    ~Zombie();

    void announce() const;
    void setName(const std::string &name);
};

Zombie* zombieHorde( int N, std::string name );

#endif