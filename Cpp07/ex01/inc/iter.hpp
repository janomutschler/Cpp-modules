/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:44:16 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 11:10:16 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

//template func read only
template <typename T>
void printElem(const T& x)
{
    std::cout << x << " ";
}

//template func modifies elements
template <typename T>
void increment(T& x)
{
    x += 1;
}

template <typename T>
void iter(T* array, size_t len, void (*f)(T&))
{
    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}

template <typename T>
void iter(const T* array, size_t len, void (*f)(const T&))
{
    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}

#endif