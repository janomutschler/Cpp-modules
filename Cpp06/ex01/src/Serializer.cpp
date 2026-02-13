/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:18:00 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/05 11:28:54 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Data.hpp"
#include "../inc/Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return (*this); }
Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(Data* ptr)
{
	if (!ptr) return 0;
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	if (!raw) return NULL;
	return (reinterpret_cast<Data*>(raw));	
}