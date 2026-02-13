/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contract.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:19:14 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/20 08:42:11 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void	Contact::setFirstName(const std::string& str)
{
	_firstName = str;
}

void	Contact::setLastName(const std::string& str)
{
	_lastName = str;
}

void	Contact::setNickname(const std::string& str)
{
	_nickname = str;
}

void	Contact::setPhoneNumber(const std::string& str)
{
	_phoneNumber = str;
}

void	Contact::setDarkestSecret(const std::string& str)
{
	_darkestSecret = str;
}

const	std::string& Contact::getFirstName() const
{
	return (_firstName);
}

const	std::string& Contact::getLastName() const
{
	return (_lastName);
}

const	std::string& Contact::getNickname() const
{
	return (_nickname);
}

const	std::string& Contact::getPhoneNumber() const
{
	return (_phoneNumber);
}

const	std::string& Contact::getDarkestSecret() const
{
	return (_darkestSecret);
}