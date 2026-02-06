/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:58:08 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 10:31:34 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
	T	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T min(T a, T b) { return (a < b ? a : b); }

template <typename T>
T max(T a, T b) { return (a > b ? a : b); }

#endif