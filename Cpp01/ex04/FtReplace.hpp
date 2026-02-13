/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtReplace.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:45:30 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/22 13:37:18 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FTREPLACE_HPP
#define FTREPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

std::string ftReplace(const std::string& input, const std::string& s1, const std::string& s2);

#endif