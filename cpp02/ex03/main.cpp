/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:23:05 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/16 14:32:06 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"


int main(void)
{
	std::cout << "===== TEST FUCTION BSP =====" << std::endl;
	
	Point a(0.0f, 0.0f);
	Point b(10.0f, 0.0f);
	Point c(5.0f, 10.0f);
	
	std::cout << "A(0,0), B(10,0), C(5,10)" << std::endl << std::endl;
	
	Point p1(5.0f, 5.0f);
	std::cout << "Test 1: Point(5,5) INSIDE" << std::endl;
	std::cout << "Result: " << (bsp(a, b, c, p1) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	Point p2(15.0f, 5.0f);
	std::cout << "Test 2: Point(15,5) OUTSIDE" << std::endl;
	std::cout << "Result: " << (bsp(a, b, c, p2) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	Point p3(0.0f, 0.0f);
	std::cout << "Test 3: Point(0,0) in a summit" << std::endl;
	std::cout << "Result: " << (bsp(a, b, c, p3) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	Point p4(5.0f, 0.0f);
	std::cout << "Test 4: Point(5,0) ON A BORDER" << std::endl;
	std::cout << "Result: " << (bsp(a, b, c, p4) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	Point p5(0.1f, 0.1f);
	std::cout << "Test 5: Point(0.1,0.1) close to border INSIDE" << std::endl;
	std::cout << "Result: " << (bsp(a, b, c, p5) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	Point p6(-0.1f, 0.1f);
	std::cout << "Test 6: Point(-0.1,0.1) close to border but OUTSIDE" << std::endl;
	std::cout << "Result: " << (bsp(a, b, c, p6) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	Point n1(-5.0f, -5.0f);
	Point n2(5.0f, -5.0f);
	Point n3(0.0f, 5.0f);
	Point p7(0.0f, 0.0f);
	
	std::cout << "Test 7: negative : (-5,-5), (5,-5), (0,5)" << std::endl;
	std::cout << "Point(0,0) INSIDE" << std::endl;
	std::cout << "Result: " << (bsp(n1, n2, n3, p7) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	Point d1(0.0f, 0.0f);
	Point d2(10.0f, 0.0f);
	Point d3(5.0f, 0.1f);
	Point p8(5.0f, 0.05f);
	
	std::cout << "Test 8: degenerate triangle: (0,0), (10,0), (5,0.1)" << std::endl;
	std::cout << "Point(5,0.05) INSIDE" << std::endl;
	std::cout << "Result: " << (bsp(d1, d2, d3, p8) ? "INSIDE" : "OUTSIDE") << std::endl;
	
	return 0;
}