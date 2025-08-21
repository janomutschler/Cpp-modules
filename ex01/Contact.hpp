/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:19:03 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/20 08:41:20 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();
	~Contact();

	void	setFirstName(const std::string& str);
	void	setLastName(const std::string& str);
	void	setNickname(const std::string& str);
	void	setPhoneNumber(const std::string& str);
	void	setDarkestSecret(const std::string& str);
    const	std::string& getFirstName() const;
    const	std::string& getLastName() const;
    const	std::string& getNickname() const;
    const	std::string& getPhoneNumber() const;
    const	std::string& getDarkestSecret() const;
	
};

#endif