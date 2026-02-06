/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 10:44:19 by jmutschl          #+#    #+#             */
/*   Updated: 2026/02/06 11:12:36 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
    int		arr[] = {1, 2, 3, 4};
    size_t	len = 4;

    std::cout << "Original array: ";
    iter(arr, len, printElem<int>);
    std::cout << std::endl;

    iter(arr, len, increment<int>);

    std::cout << "After increment: ";
    iter(arr, len, printElem<int>);
    std::cout << std::endl;

    const int	constArr[] = {10, 20, 30};

    std::cout << "Const array: ";
    iter(constArr, 3, printElem<int>);
    std::cout << std::endl;

    return 0;
}