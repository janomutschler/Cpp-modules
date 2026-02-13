/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 15:12:23 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/29 15:15:51 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

static void test(Point const &A, Point const &B, Point const &C, Point const &P, char const *name) 
{
    std::cout << name << ": " << (bsp(A,B,C,P) ? "inside" : "not inside") << "\n";
}

int main() 
{
    Point A(Fixed(0), Fixed(0));
    Point B(Fixed(10), Fixed(0));
    Point C(Fixed(5), Fixed(8));

    Point P1(Fixed(5), Fixed(3));
    Point P2(Fixed(11), Fixed(1));
    Point P3(Fixed(4), Fixed(0));
    Point P4(Fixed(5), Fixed(8));
    Point P5(Fixed(5), Fixed(1));

    test(A,B,C,P1,"P1");
    test(A,B,C,P2,"P2");
    test(A,B,C,P3,"P3");
    test(A,B,C,P4,"P4");
    test(A,B,C,P5,"P5");

    Point D(Fixed(0), Fixed(0));
    Point E(Fixed(10), Fixed(0));
    Point F(Fixed(3), Fixed(0));
    Point PX(Fixed(3), Fixed(1));
    std::cout << "not a triangle: " << (bsp(D,E,F,PX) ? "inside" : "not inside") << "\n";

    return 0;
}
