/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:32:52 by jmutschl          #+#    #+#             */
/*   Updated: 2025/09/01 06:24:16 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <iostream>

Brain::Brain()
{
    std::cout << "Brain: Default constructor called\n";
}

Brain::Brain(const Brain& src)
{
    std::cout << "Brain: Copy constructor called\n";
    *this = src;
}

Brain& Brain::operator=(const Brain& src)
{
    std::cout << "Brain: Copy assignment operator called\n";
    if (this != &src)
	{
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = src._ideas[i];
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << "Brain: Destructor called\n";
}

void    Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
        _ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return (_ideas[index]);
    return ("");
}