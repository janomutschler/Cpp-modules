/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:47:57 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 12:01:52 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>
class Array
{
private:
    T*              _data;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    T&			operator[](unsigned int index);
    const T&	operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"

#endif
