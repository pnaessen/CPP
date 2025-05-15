/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:05 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/15 15:31:31 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

int main(void)
{
	std::cout << "===== TESTS BASE =====" << std::endl;
	
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n===== OPERATOR COMPARISON TESTS =====" << std::endl;
	
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "b != d: " << (b != d) << std::endl;
	std::cout << "a == a: " << (a == a) << std::endl;
	
	std::cout << "\n===== ARITHMETIC OPERATOR TESTS =====" << std::endl;
	
	Fixed e(5.05f);
	Fixed f(2);
	
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "e + f = " << (e + f) << std::endl;
	std::cout << "e - f = " << (e - f) << std::endl;
	std::cout << "e * f = " << (e * f) << std::endl;
	std::cout << "e / f = " << (e / f) << std::endl;
	
	Fixed zero(0);
	std::cout << "e / zero = ";
	std::cout << (e / zero) << std::endl;
	
	std::cout << "\n===== INCREMENTATION/DECREMENTATION OPERATOR TESTS =====" << std::endl;
	
	Fixed g(0);
	std::cout << "g init: " << g << std::endl;
	
	std::cout << "++g: " << ++g << std::endl;
	std::cout << "g after ++g: " << g << std::endl;
	
	std::cout << "g++: " << g++ << std::endl;
	std::cout << "g after g++: " << g << std::endl;
	
	std::cout << "--g: " << --g << std::endl;
	std::cout << "g after --g: " << g << std::endl;
	
	std::cout << "g--: " << g-- << std::endl;
	std::cout << "g after g--: " << g << std::endl;
	
	std::cout << "\n===== TESTS FONCTIONS MIN/MAX =====" << std::endl;
	
	std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
	std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;
	
	std::cout << "min(b, c) (const): " << Fixed::min(b, c) << std::endl;
	std::cout << "max(b, c) (const): " << Fixed::max(b, c) << std::endl;
	
	std::cout << "\n===== TEST CLASIC =====" << std::endl;
	
	Fixed h;
	Fixed const i(Fixed(5.05f) * Fixed(2));
	
	std::cout << "h: " << h << std::endl;
	std::cout << "++h: " << ++h << std::endl;
	std::cout << "h: " << h << std::endl;
	std::cout << "h++: " << h++ << std::endl;
	std::cout << "h: " << h << std::endl;
	std::cout << "i: " << i << std::endl;
	std::cout << "max(h, i): " << Fixed::max(h, i) << std::endl;
	
	return 0;
}