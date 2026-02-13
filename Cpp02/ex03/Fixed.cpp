/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:53:48 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/29 14:09:15 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_fractionalBits = 8;

Fixed::Fixed() : _fixedPointValue(0)
{
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
	if (this != &src)
		this->_fixedPointValue = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
}

static int	limit(long long x)
{
	if (x > INT_MAX)
	{
		std::cout << "Value is to big to be stored _fixed point number will be adjusted to INT_MAX\n";
		return (INT_MAX);
	}
	if (x < INT_MIN)
	{
		std::cout << "Value is to small to be stored _fixed point number will be adjusted to INT_MIN\n";
		return (INT_MIN);
	}
	return (static_cast<int>(x));
}
Fixed::Fixed(const int value)
{
	const long long	scale = (1 << _fractionalBits);
	long long temp = static_cast<long long>(value) * scale;
	_fixedPointValue = limit(temp);
}

Fixed::Fixed(const float value)
{
	const float	scale = static_cast<float>(1 << _fractionalBits);
	long long temp = static_cast<long long>(roundf(value * scale));
	_fixedPointValue = limit(temp);
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

Fixed	Fixed::operator+(const Fixed& right) const
{
	const long long	a = static_cast<long long>(this->_fixedPointValue);
	const long long b = static_cast<long long>(right._fixedPointValue);
	
	long long	sum = a + b;
	
	Fixed	result;
	result.setRawBits(limit(sum));
	return (result);
}

Fixed	Fixed::operator-(const Fixed& right) const
{
	const long long	a = static_cast<long long>(this->_fixedPointValue);
	const long long b = static_cast<long long>(right._fixedPointValue);

	long long	dif = a - b;
	
	Fixed	result;
	result.setRawBits(limit(dif));
	return (result);
}

Fixed	Fixed::operator*(const Fixed& right) const
{
	const long long	a = static_cast<long long>(this->_fixedPointValue);
	const long long b = static_cast<long long>(right._fixedPointValue);
	const long long	scale = (1LL << _fractionalBits);
	
	long long	prd = (a * b) / scale;
	
	Fixed	result;
	result.setRawBits(limit(prd));
	return (result);
}

Fixed	Fixed::operator/(const Fixed& right) const
{
	const long long	a = static_cast<long long>(this->_fixedPointValue);
	const long long b = static_cast<long long>(right._fixedPointValue);
	const long long	scale = (1LL << _fractionalBits);
	
	const long long	temp = a * scale;
	long long		quo = temp / b;
	
	Fixed			result;
	result.setRawBits(limit(quo));
	return (result);
}

bool Fixed::operator>(const Fixed& rhs) const  { return (this->_fixedPointValue >  rhs._fixedPointValue); }
bool Fixed::operator<(const Fixed& rhs) const  { return (this->_fixedPointValue <  rhs._fixedPointValue); }
bool Fixed::operator>=(const Fixed& rhs) const { return (this->_fixedPointValue >= rhs._fixedPointValue); }
bool Fixed::operator<=(const Fixed& rhs) const { return (this->_fixedPointValue <= rhs._fixedPointValue); }
bool Fixed::operator==(const Fixed& rhs) const { return (this->_fixedPointValue == rhs._fixedPointValue); }
bool Fixed::operator!=(const Fixed& rhs) const { return (this->_fixedPointValue != rhs._fixedPointValue); }

Fixed&	Fixed::operator++()
{
	++_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);
	++_fixedPointValue;
	return (old);
}

Fixed&	Fixed::operator--()
{
	--_fixedPointValue;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);
	--_fixedPointValue;
	return (old);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) { return ((a < b) ? a : b); }
Fixed&	Fixed::max(Fixed& a, Fixed& b) { return ((a > b) ? a : b); }

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) { return ((a < b) ? a : b); }
const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) { return ((a > b) ? a : b); }

std::ostream	&operator<<(std::ostream &os, const Fixed &output)
{
	os << output.toFloat();
	return (os);
}