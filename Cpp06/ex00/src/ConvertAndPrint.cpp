/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertAndPrint.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:37:04 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/04 17:47:13 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScalarConverterPriv.hpp"
#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cerrno>

struct Flags{
    bool	charImpossible;
    bool	charIntImpossible;
	bool	charIntFloatImpossible;
	bool	nanOrInf;
    int 	pseudoSign; 
};

static void printAll(char c, int i, float f, double d, const Flags& flags)
{
    // char
    if (flags.charImpossible || flags.charIntImpossible || flags.charIntFloatImpossible)
        std::cout << "char: impossible\n";
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: '" << c << "'\n";

    // int
    if (flags.charIntImpossible || flags.charIntFloatImpossible)
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << i << "\n";

    // float
    if (flags.charIntFloatImpossible)
        std::cout << "float: impossible\n";
    else
    {
        if (flags.nanOrInf)
        {
            if (flags.pseudoSign == 0)      std::cout << "float: nanf\n";
            else if (flags.pseudoSign > 0)  std::cout << "float: +inff\n";
            else                         	std::cout << "float: -inff\n";
        }
        else
        {
            if (!flags.nanOrInf && f == std::floor(f))
			{
				std::ios::fmtflags oldFlags = std::cout.flags();
				std::streamsize oldPrec = std::cout.precision();
				std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f\n";
				std::cout.flags(oldFlags);
				std::cout.precision(oldPrec);
			}
            else
                std::cout << "float: " << f << "f\n";
        }
    }

    // double
    if (flags.nanOrInf)
    {
        if (flags.pseudoSign == 0)      std::cout << "double: nan\n";
        else if (flags.pseudoSign > 0)  std::cout << "double: +inf\n";
        else                         	std::cout << "double: -inf\n";
    }
    else
    {
        if (!flags.nanOrInf && d == std::floor(d))
        {
			std::ios::fmtflags oldFlags = std::cout.flags();
			std::streamsize oldPrec = std::cout.precision();
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << "\n";
			std::cout.flags(oldFlags);
			std::cout.precision(oldPrec);
		}
        else
            std::cout << "double: " << d << "\n";
    }
}

static void	printInvalid()
{
	std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    std::cout << "float: impossible\n";
    std::cout << "double: impossible\n";
}
static void	convertChar(const std::string& s, Flags& flags) 
{
	char	c = s[0];
	int		i = static_cast<int>(c);
	double	d = static_cast<double>(c);
	float	f = static_cast<float>(c);
	printAll(c, i, f, d, flags);
}

static void	convertInt(const std::string& s, Flags& flags)
{
	int		i = 0;
	char	c = 0;
	errno = 0;
    char* end = 0;
    long l = std::strtol(s.c_str(), &end, 10);
	if (errno == ERANGE || !end || *end != '\0')
		return (printInvalid());
	if (l < INT_MIN || l > INT_MAX)
	  flags.charIntImpossible = true;
	if (l < 0 || l > 127)
		flags.charImpossible = true;
	if (!flags.charIntImpossible)
	{
		i = static_cast<int>(l);
		if (!flags.charImpossible)
			c = static_cast<char>(i);
	}
	double	d = static_cast<double>(l);
	float	f = static_cast<float>(l);
	printAll(c, i, f, d, flags);
}

static void	convertDoublePseudo(const std::string& s, Flags& flags) 
{
	double	d = 0.0;
	if (s == "nan")
	{
		d = std::numeric_limits<double>::quiet_NaN();
		flags.pseudoSign = 0;
	}
	else if (s == "+inf" || s == "inf")
	{
		d = std::numeric_limits<double>::infinity();
		flags.pseudoSign = +1;
	}
	else if (s == "-inf")
	{
		d = -std::numeric_limits<double>::infinity();
		flags.pseudoSign = -1;
	}
	flags.nanOrInf = true;
	flags.charIntImpossible = true;
	float f = static_cast<float>(d);
	printAll(0, 0, f, d, flags);
}

static void	convertFloatPseudo(const std::string& s, Flags& flags) 
{
	float f = 0.0f;
    if (s == "nanf")
	{
        f = std::numeric_limits<float>::quiet_NaN();
        flags.pseudoSign = 0;
    }
	else if (s == "+inff" || s == "inff")
	{
        f = std::numeric_limits<float>::infinity();
        flags.pseudoSign = +1;
    }
	else if (s == "-inff")
	{
        f = -std::numeric_limits<float>::infinity();
        flags.pseudoSign = -1;
	}
	flags.nanOrInf = true;
    flags.charIntImpossible = true;
	double	d = static_cast<double>(f);
	printAll(0, 0, f, d, flags);
}


static void	convertDouble(const std::string& s, Flags& flags) 
{
	errno = 0;
	char* end = 0;
	double	d = std::strtod(s.c_str(), &end);
	if (errno == ERANGE || !end || *end != '\0')
		return (printInvalid());

	const double	fmax = static_cast<double>(std::numeric_limits<float>::max());
	if (d < -fmax || d > fmax)
	{
		flags.charIntFloatImpossible = true;
		return(printAll(0, 0, 0.0f, d, flags));
	}
	float	f = static_cast<float>(d);

	if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
	{
		flags.charIntImpossible = true;
		return(printAll(0, 0, f, d, flags));
	}
	int		i = static_cast<int>(d);

	if (d < 0.0 || d > 127.0)
	{
		flags.charImpossible = true;
		return(printAll(0, i, f, d, flags));
	}
	char	c = static_cast<char>(d);

	printAll(c, i, f, d, flags);
}


static void	convertFloat(const std::string& s, Flags& flags) 
{
	errno = 0;
	char*		end = 0;
	std::string	core = s.substr(0, s.size() - 1);
	double		tmp = std::strtod(core.c_str(), &end);
	if (errno == ERANGE || !end || *end != '\0')
		return (printInvalid());
	
	const double	fmax = static_cast<double>(std::numeric_limits<float>::max());
	if (tmp < -fmax || tmp > fmax)
		return (printInvalid());
	float	f = static_cast<float>(tmp);
	double	d = static_cast<double>(f);

	if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
	{
		flags.charIntImpossible = true;
		return (printAll(0, 0, f, d, flags));
	}
	int		i = static_cast<int>(f);

	if (i < 0 || i > 127)
	{
		flags.charImpossible = true;
		return (printAll(0, i, f, d, flags));
	}
	char	c = static_cast<char>(f);
	printAll(c, i, f, d, flags);
}


void	convertType(const std::string& s, eType t)
{
	Flags flags;
	flags.charImpossible = false;
	flags.charIntImpossible = false;
	flags.charIntFloatImpossible = false;
	flags.nanOrInf = false;
	flags.pseudoSign = 0;
    switch (t)
    {
        case T_INVALID:			printInvalid(); break;
        case T_CHAR:			convertChar(s, flags); break;
        case T_INT:				convertInt(s, flags); break;
        case T_PSEUDO_DOUBLE:	convertDoublePseudo(s, flags); break;
        case T_DOUBLE:			convertDouble(s, flags); break;
        case T_PSEUDO_FLOAT:	convertFloatPseudo(s, flags); break;
        case T_FLOAT:			convertFloat(s, flags); break;
    }
}