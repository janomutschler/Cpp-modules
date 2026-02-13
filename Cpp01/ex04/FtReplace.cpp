/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FtReplace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:45:36 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/22 13:05:19 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FtReplace.hpp"


std::string ftReplace(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string	out;
	out.reserve(line.size());
	std::size_t	lastHit = 0;

	while (1)
	{
		std::size_t	hit = line.find(s1, lastHit);
		if (hit == std::string::npos)
		{
			out.append(line, lastHit, std::string::npos);
			break ;
		}
		out.append(line, lastHit, hit - lastHit);
		out += s2;
		lastHit = hit + s1.size();
	}
	return (out);
}