/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:36:33 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/17 11:02:46 by pnaessen         ###   ########lyon.fr   */
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
	return 0;
}