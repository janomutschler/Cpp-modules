/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:36:57 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/29 14:37:54 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point 
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(Fixed const x, Fixed const y);
		Point(Point const &other);
		~Point();

		Point &operator=(Point const &other);

		Fixed const &x() const { return _x; }
		Fixed const &y() const { return _y; }
};

bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif
