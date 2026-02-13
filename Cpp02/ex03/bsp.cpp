/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:36:15 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/29 15:10:11 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	cross (const Point &a, const Point &b, const Point &p)
{
	Fixed ba_x = b.x() - a.x();
	Fixed ba_y = b.y() - a.y();
	Fixed pa_x = p.x() - a.x();
	Fixed pa_y = p.y() - a.y();
	return ((ba_x * pa_y) - (ba_y * pa_x));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	triangle = cross(a, b, c);
	if (triangle == Fixed(0))
		return (false);
	Fixed	edge1 = cross(a, b, point);
	Fixed	edge2 = cross(b, c, point);
	Fixed	edge3 = cross(c, a, point);
	if (edge1 < Fixed(0) && edge2 < Fixed(0) && edge3 < Fixed(0))
		return (true);
	if (edge1 > Fixed(0) && edge2 > Fixed(0) && edge3 > Fixed(0))
		return (true);
	return (false);
}