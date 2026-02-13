/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:53:48 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/29 10:24:17 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called\n";
	const long long	scale = (1 << _fractionalBits);
	long long temp = static_cast<long long>(value) * scale;
	if (temp > INT_MAX)
	{
		std::cout << "Value is to big to be stored _fixed point number will be adjusted to INT_MAX\n";
		_fixedPointValue = INT_MAX;
	}
	else if (temp < INT_MIN)
	{
		std::cout << "Value is to small to be stored _fixed point number will be adjusted to INT_MIN\n";
		_fixedPointValue = INT_MIN;
	}
	else
		_fixedPointValue = static_cast<int>(temp);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called\n";
	const float	scale = static_cast<float>(1 << _fractionalBits);
	long long temp = static_cast<long long>(roundf(value * scale));
	if (temp > INT_MAX)
	{
		std::cout << "Value is to big to be stored _fixed point number will be adjusted to INT_MAX\n";
		_fixedPointValue = INT_MAX;
	}
	else if (temp < INT_MIN)
	{
		std::cout << "Value is to small to be stored _fixed point number will be adjusted to INT_MIN\n";
		_fixedPointValue = INT_MIN;
	}
	else
		_fixedPointValue = static_cast<int>(temp);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPointValue >> _fractionalBits);
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->_fixedPointValue) / (1 << _fractionalBits));
}

std::ostream	&operator<<(std::ostream &os, const Fixed &output)
{
	os << output.toFloat();
	return (os);
}