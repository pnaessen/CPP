/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:36:33 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/26 07:44:41 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(42);
	vec.push_back(3);
	
	try {
		std::vector<int>::iterator it = easyfind(vec, 64);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Not found" << std::endl;
	}

	std::list<double> list_v;
	list_v.push_front(56);
	list_v.push_front(22);
	list_v.push_back(42);

	const std::list<double> const_list = list_v;
	
	try {
		std::list<double>::const_iterator it = easyfind(const_list, 42);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Not found" << std::endl;
	}
	
	// std::stack<int> stack_v;
	// stack_v.push(11);
	// stack_v.push(21);
	// stack_v.push(31);
	
	// try {
	// 	std::stack<int>::iterator it = easyfind(stack_v, 42);
	// 	std::cout << "Found: " << *it << std::endl;
	// }
	// catch (const std::exception& e) {
	// 	std::cout << "Not found" << std::endl;
	// }
	return 0;
}