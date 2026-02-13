/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:19:17 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/20 10:06:21 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <cstdlib>

bool	isOnlySpace(const std::string& str)
{
	for (size_t i = 0; i < str.size(); ++i)
	{
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return (false);
	}
	return (true);
}

std::string prompt(const std::string& str)
{
	std::string	userInput;
	do
	{
		std::cout << str;
		if (!std::getline(std::cin, userInput))
		{
			std::cout << "\nEOF detected.\nEXITING\n";
			exit(0);
		}
	} while (userInput.empty() || isOnlySpace(userInput));
	return (userInput);
}

void	create_and_add_Contact(PhoneBook &book)
{
	Contact	c;
	c.setFirstName(prompt("First Name: "));
	c.setLastName(prompt("Last Name: "));
	c.setNickname(prompt("Nickname: "));
	c.setPhoneNumber(prompt("Phone Number: "));
	c.setDarkestSecret(prompt("Darkest Secret: "));
	book.add(c);
	std::cout << "Contact added!\n";
}

bool	ft_atoi(const std::string& str, int& res)
{
	std::istringstream	inputStringStream(str);
	char				trailing;
	if (!(inputStringStream >> res))
		return (false);
	if (inputStringStream >> trailing)
		return (false);
	return (true);
}
void search(const PhoneBook& book)
{
	if (book.size() == 0)
	{
		std::cout << "PhoneBook is empty\n";
		return ;
	}
	book.printContactList();
	while (1)
	{
		std::string	indexString = prompt("Enter index to view details or CANCEL(c) to return: ");
		if (indexString == "CANCEL" || indexString == "c")
			return ;
		int	index;
		if (!ft_atoi(indexString, index))
		{
			std::cout << "Invalid Index. Please enter a number or CANCEL(c)\n";
			continue ;
		}
		const Contact* c = book.get(index - 1);
		if (!c)
		{
			std::cout << "Out of range. Valid: 1..." << book.size() << "\n";
			continue ;
		}
		std::cout << "First name: "     << c->getFirstName()     << "\n";
		std::cout << "Last name: "      << c->getLastName()      << "\n";
		std::cout << "Nickname: "       << c->getNickname()      << "\n";
		std::cout << "Phone number: "   << c->getPhoneNumber()   << "\n";
		std::cout << "Darkest secret: " << c->getDarkestSecret() << "\n";
		return ;
	}
}
int	main(void)
{
	PhoneBook 	book;
	std::string	command;

	std::cout << "Welcome to 42 PhoneBook!\n";
	std::cout << "Commands: ADD(a), SEARCH(s), EXIT(x)\n";

	while (1)
	{
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected.\nEXITING\n";
			break ;
		}
		if (command == "ADD" || command == "a")
			create_and_add_Contact(book);
		else if (command == "SEARCH" || command == "s")
			search(book);
		else if (command == "EXIT" || command == "x")
		{
			std::cout << "EXITING\n";
			break ;
		}
		else
			std::cout << "Unknown command. Try ADD(a), SEARCH(s), or EXIT(x).\n";		
	}
	return (0);
}
