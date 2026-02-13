/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:36:46 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 11:59:26 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class AMateria;

#define INVENTORY_SIZE 4
#define FLOOR_SIZE    16

class Character : public ICharacter
{
  private:
    std::string _name;
    AMateria*   _inv[INVENTORY_SIZE];
    AMateria*   _floor[FLOOR_SIZE];
    int         _floorIdx;

    void _clearInventory();
    void _copyInventory(const Character& src);

  public:
    Character();
    Character(const Character& src);
    Character& operator=(const Character& src);
    virtual ~Character();

    Character(std::string const& name);

    virtual void                equip(AMateria* m);
    virtual void                unequip(int idx);
    virtual void                use(int idx, ICharacter& target);
    virtual std::string const&  getName() const;
};

#endif
