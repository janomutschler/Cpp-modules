/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:19:11 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/20 09:33:44 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _size(0), _next(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::add(const Contact& c)
{
	_contacts[_next] = c;
	_next = (_next + 1) % 8;
	if (_size < 8)
		_size++;
}

int PhoneBook::size() const
{
	return (_size);
}

const Contact* PhoneBook::get(int i) const
{
	if (i < 0 || i >= _size)
		return (0);
	return (&_contacts[i]);
}

std::string PhoneBook::fitColumn(const std::string& s)
{
    if (s.length() <= 10) return s;
    return s.substr(0, 9) + ".";
}

void PhoneBook::printContactList() const
{
    std::cout << std::setw(10) << "INDEX" << "|"
              << std::setw(10) << "FIRST NAME" << "|"
              << std::setw(10) << "LAST NAME" << "|"
              << std::setw(10) << "NICKNAME" << "\n";
    for (int i = 0; i < _size; ++i) 
	{
        const Contact& c = _contacts[i];
        std::cout << std::setw(10) << (i + 1) << "|"
                  << std::setw(10) << fitColumn(c.getFirstName()) << "|"
                  << std::setw(10) << fitColumn(c.getLastName())  << "|"
                  << std::setw(10) << fitColumn(c.getNickname())  << "\n";
    }
}