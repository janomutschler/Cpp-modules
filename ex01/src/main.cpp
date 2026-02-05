/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:24:55 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/05 11:24:56 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data data(42, 'A', "Hello 42");

	Data* original = &data;
	uintptr_t raw = Serializer::serialize(original);
	Data* restored = Serializer::deserialize(raw);

	std::cout << "Original pointer:  " << original << std::endl;
	std::cout << "Serialized value:  " << raw << std::endl;
	std::cout << "Restored pointer:  " << restored << std::endl;

	if (original == restored)
		std::cout << "Success: pointers are equal" << std::endl;
	else
		std::cout << "Error: pointers are NOT equal" << std::endl;

	return 0;
}