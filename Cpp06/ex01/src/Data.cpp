/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:16:27 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/05 11:17:27 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : number(42), letter('J'), text("Hello World") {}

Data::Data(int n, char c, const std::string& t)
	: number(n), letter(c), text(t) {}
