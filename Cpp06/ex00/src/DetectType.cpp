/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DetectType.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:35:27 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/04 17:47:20 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverterPriv.hpp"
#include <cctype>

static bool isPseudoDouble(const std::string& s)
{
    return (s == "nan" || s == "+inf" || s == "-inf" || s == "inf");
}

static bool isPseudoFloat(const std::string& s)
{
    return (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff");
}

static bool isChar(const std::string& s)
{
    return (s.size() == 1 &&
            !std::isdigit(static_cast<unsigned char>(s[0])));
}

static bool isInt(const std::string& s)
{
    if (s.empty())
		return (false);

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
		i++;
    if (i == s.size())
		return (false);

    for (; i < s.size(); i++)
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return (false);

    return (true);
}

static bool isDecimal(const std::string& s)
{
    if (s.empty())
		return (false);

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
		i++;
    if (i == s.size())
		return (false);

    bool seenDigit = false;
    bool seenDot = false;

    for (; i < s.size(); i++)
    {
        if (std::isdigit(static_cast<unsigned char>(s[i])))
            seenDigit = true;
        else if (s[i] == '.' && !seenDot)
            seenDot = true;
        else
            return (false);
    }
    return seenDigit;
}

static bool	isFloat(const std::string& s)
{
    if (s.size() < 2)
		return (false);
    if (s[s.size() - 1] != 'f')
		return (false);
	std::string core = s.substr(0, s.size() - 1);
    return (isDecimal(core) || isInt(core));
}

static bool	isDouble(const std::string& s) { return isDecimal(s); }

eType	detectType(const std::string& s)
{
    if (isPseudoFloat(s))
		return (T_PSEUDO_FLOAT);
    if (isPseudoDouble(s))
		return (T_PSEUDO_DOUBLE);
	if (isChar(s))
        return (T_CHAR);
	if (isInt(s))
		return (T_INT);
    if (isFloat(s))
		return (T_FLOAT);
    if (isDouble(s))
		return (T_DOUBLE);
	return (T_INVALID);
}