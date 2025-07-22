/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:53:19 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/22 08:54:16 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main() {
	
	try {
		std::cout << "=== Test 1: Basic functionality ===" << std::endl;
		Span sp = Span(60);
		
		sp.addNumber(-18);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(10);
		
		std::cout << "After adding [-18, 3, 17, 9, 10]:" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		std::vector<int> vec;
		for (size_t i = 0; i < 30; i++) {
			vec.push_back(i);
		}
		
		sp.addMoreNumber(vec.begin(), vec.end());
		std::cout << "\nAfter adding [0, 1, 2, ..., 29]:" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n=== Test 2: Error cases ===" << std::endl;
		
		Span smallSpan(1);
		smallSpan.addNumber(42);
		std::cout << smallSpan.shortestSpan() << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Expected error: " << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n=== Test 3: Capacity overflow ===" << std::endl;
		Span tinySpan(2);
		tinySpan.addNumber(1);
		tinySpan.addNumber(2);
		
		std::vector<int> overflow;
		overflow.push_back(3);
		overflow.push_back(4);
		
		tinySpan.addMoreNumber(overflow.begin(), overflow.end());
		
	} catch (const std::exception& e) {
		std::cout << "Expected error: " << e.what() << std::endl;
	}
	
	try {
		std::cout << "\n=== Test 4: Large span (10000 elements) ===" << std::endl;
		Span bigSpan(10000);
		
		std::vector<int> bigVec;
		for (int i = 0; i < 10000; i++) {
			bigVec.push_back(i * 2);
		}
		
		bigSpan.addMoreNumber(bigVec.begin(), bigVec.end());
		std::cout << "Big span shortest: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Big span longest: " << bigSpan.longestSpan() << std::endl;
		
	} catch (const std::exception& e) {
		std::cout << "Error in big test: " << e.what() << std::endl;
	}
	
	return 0;
}