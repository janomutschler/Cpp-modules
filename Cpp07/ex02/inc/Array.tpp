/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 11:48:00 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 17:00:46 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
    if (_size == 0)
        _data = NULL;
    else
        _data = new T[_size];
}

template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0) { *this = other; }

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] _data;

        _size = other._size;
        _data = (_size == 0) ? NULL : new T[_size];

        for (unsigned int i = 0; i < _size; ++i)
            _data[i] = other._data[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() { delete[] _data; }

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Array: index out of bounds");
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw OutOfBoundsException();
    return (_data[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw OutOfBoundsException();
    return (_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const { return (_size); }

