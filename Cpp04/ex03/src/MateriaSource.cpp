/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 07:46:42 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 12:11:17 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++) _learned[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    for (int i = 0; i < 4; i++) _learned[i] = NULL;
    _copyLearned(src);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src)
{
    if (this != &src)
	{
        _clearLearned();
        _copyLearned(src);
    }
    return (*this);
}

MateriaSource::~MateriaSource() { _clearLearned();}

void MateriaSource::_clearLearned()
{
    for (int i = 0; i < 4; i++)
	{
        if (_learned[i])
        {
            delete _learned[i];
            _learned[i] = NULL;
        }
    }
}

void MateriaSource::_copyLearned(const MateriaSource& src)
{
    for (int i = 0; i < 4; i++)
	{
        if (src._learned[i])
            _learned[i] = src._learned[i]->clone();
        else
            _learned[i] = NULL;
    }
}

void    MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (_learned[i] == NULL)
        {
            _learned[i] = m->clone();
            delete m;
            std::cout << "MateriaSource: learned " << _learned[i]->getType()
                      << " in slot " << i << "\n";
            return ;
        }
    }
    std::cout   << "MateriaSource: memory full, cannot learn "
                << m->getType() << "\n";
    delete m;
}

AMateria*   MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (_learned[i] && _learned[i]->getType() == type)
        {
            std::cout << "MateriaSource: creating a new " << type << "\n";
            return (_learned[i]->clone());
        }
    }
    std::cout << "MateriaSource: unknown type '" << type << "'\n";
    return (0);
}
