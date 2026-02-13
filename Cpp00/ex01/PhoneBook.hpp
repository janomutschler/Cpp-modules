/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:19:08 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/21 08:44:14 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_size;
		int		_next;
	public:
		PhoneBook();
		~PhoneBook();

		void				add(const Contact& c);
		int					size() const;
		const 				Contact* get(int i) const;
		static std::string	fitColumn(const std::string& s);
		void				printContactList() const;
};

#endif