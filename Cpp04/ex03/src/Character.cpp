/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:46:26 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 12:35:00 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : _name("default"), _floorIdx(0)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) _inv[i] = NULL;
    for (int i = 0; i < FLOOR_SIZE; i++) _floor[i] = NULL;
    std::cout << "Created Character " << _name << "\n";
}

Character::Character(std::string const& name) : _name(name), _floorIdx(0)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) _inv[i] = NULL;
    for (int i = 0; i < FLOOR_SIZE; i++) _floor[i] = NULL;
    std::cout << "Created Character " << _name << "\n";
}

Character::Character(const Character& src) : _name(src._name), _floorIdx(src._floorIdx)
{
    for (int i = 0; i < INVENTORY_SIZE; i++) _inv[i] = NULL;
    for (int i = 0; i < FLOOR_SIZE; i++) _floor[i] = NULL;
    _copyInventory(src);
}
void Character::_copyInventory(const Character& src)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
	{
        if (src._inv[i])
            _inv[i] = src._inv[i]->clone();
        else
            _inv[i] = NULL;
    }
    for (int j = 0; j < FLOOR_SIZE; j++)
    {
        if (src._floor[j])
            _floor[j] = src._floor[j]->clone();
        else
            _floor[j] = NULL;
    }
}

void Character::_clearInventory()
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
	{
        delete _inv[i];
        _inv[i] = NULL;
    }
    for (int j = 0; j < FLOOR_SIZE; j++)
    {
        delete _floor[j];
        _floor[j] = NULL;
    }
}

Character& Character::operator=(const Character& src)
{
    if (this != &src)
	{
        _name = src._name;
        _clearInventory();
        _copyInventory(src);
        _floorIdx = src._floorIdx;
    }
    return (*this);
}

Character::~Character() { _clearInventory(); }



void    Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (_inv[i] == NULL)
        {
            _inv[i] = m;
            std::cout << _name << ": equips " << m->getType() << " in slot " << i << "\n";
            return ;
        }
    }
    std::cout << _name << ": Inventory is full, cannot equip " << m->getType() << "\n";
}

void    Character::unequip(int idx)
{
    if (idx < 0 || idx >= INVENTORY_SIZE || !_inv[idx])
    {
        std::cout << "Nothing equiped in slot: " << idx << "\n";
        return ;
    }
    if (_floorIdx < FLOOR_SIZE)
    {
        _floor[_floorIdx++] = _inv[idx];
        std::cout << _name << " unequips " << _inv[idx]->getType()
                    << " from slot " << idx << "\n";
    } else {
        std::cout << _name << "'s floor is full, losing " << _inv[idx]->getType() << "\n";
        delete _inv[idx];
    }
    _inv[idx] = NULL; 
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= INVENTORY_SIZE || !_inv[idx])
    {
        std::cout << "Nothing equiped in slot: " << idx << "\n";
        return ;
    }
        _inv[idx]->use(target);
}

std::string const&  Character::getName() const { return (_name); }