/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:38:45 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/29 14:39:32 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}
Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}
Point::Point(Point const &o) : _x(o._x), _y(o._y) {}
Point::~Point() {}

Point &Point::operator=(Point const &o)
{
    (void)o;
    return *this;
}