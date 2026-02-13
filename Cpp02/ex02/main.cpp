/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmutschl <jmutschl@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:27:43 by jmutschl          #+#    #+#             */
/*   Updated: 2025/08/29 14:18:32 by jmutschl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

//int main( void )
//{
//Fixed a;
//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//std::cout << a << std::endl;
//std::cout << ++a << std::endl;
//std::cout << a << std::endl;
//std::cout << a++ << std::endl;
//std::cout << a << std::endl;
//std::cout << b << std::endl;
//std::cout << Fixed::max( a, b ) << std::endl;
//return 0;
//}

int main() {
    std::cout << "===== Constructors & basic output =====\n";
    Fixed a;                  // default
    Fixed b(10);              // int ctor
    Fixed c(42.42f);          // float ctor
    Fixed d(b);               // copy ctor
    a = Fixed(1234.4321f);    // copy assignment

    std::cout << "a = " << a << " (as int " << a.toInt() << ")\n";
    std::cout << "b = " << b << " (as int " << b.toInt() << ")\n";
    std::cout << "c = " << c << " (as int " << c.toInt() << ")\n";
    std::cout << "d = " << d << " (as int " << d.toInt() << ")\n";

    std::cout << "\n===== Arithmetic operators =====\n";
    Fixed x(5.5f);
    Fixed y(2);

    std::cout << x << " + " << y << " = " << (x + y) << "\n";
    std::cout << x << " - " << y << " = " << (x - y) << "\n";
    std::cout << x << " * " << y << " = " << (x * y) << "\n";
    std::cout << x << " / " << y << " = " << (x / y) << "\n";

    std::cout << "\n===== Comparison operators =====\n";
    std::cout << x << " > " << y << " ? " << (x > y) << "\n";
    std::cout << x << " < " << y << " ? " << (x < y) << "\n";
    std::cout << x << " >= " << y << " ? " << (x >= y) << "\n";
    std::cout << x << " <= " << y << " ? " << (x <= y) << "\n";
    std::cout << x << " == " << y << " ? " << (x == y) << "\n";
    std::cout << x << " != " << y << " ? " << (x != y) << "\n";

    std::cout << "\n===== Increment / Decrement =====\n";
    Fixed z;
    std::cout << "z = " << z << "\n";
    std::cout << "++z = " << ++z << "\n"; // pre-increment
    std::cout << "z   = " << z << "\n";
    std::cout << "z++ = " << z++ << "\n"; // post-increment
    std::cout << "z   = " << z << "\n";
    std::cout << "--z = " << --z << "\n"; // pre-decrement
    std::cout << "z   = " << z << "\n";
    std::cout << "z-- = " << z-- << "\n"; // post-decrement
    std::cout << "z   = " << z << "\n";

    std::cout << "\n===== min / max =====\n";
    Fixed e(1.25f);
    Fixed f(2.5f);
    const Fixed g(3.75f);
    const Fixed h(0.5f);

    std::cout << "min(" << e << ", " << f << ") = " << Fixed::min(e, f) << "\n";
    std::cout << "max(" << e << ", " << f << ") = " << Fixed::max(e, f) << "\n";
    std::cout << "min(" << g << ", " << h << ") = " << Fixed::min(g, h) << "\n";
    std::cout << "max(" << g << ", " << h << ") = " << Fixed::max(g, h) << "\n";

    std::cout << "\n===== Edge cases =====\n";
    Fixed big(8388607);  // near max int for Q24.8
    Fixed small(-8388608);
    std::cout << "big   = " << big << "\n";
    std::cout << "small = " << small << "\n";
    std::cout << "big + big = " << (big + big) << " (should limit)\n";
    std::cout << "small - big = " << (small - big) << " (should limit)\n";

    return 0;
}
