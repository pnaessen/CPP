/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 10:10:45 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/17 08:27:06 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int main() {
	try {
		Array<int> arr1;
		std::cout << "arr1 size: " << arr1.size() << std::endl;
		
		Array<int> arr2(5);
		std::cout << "arr2 size: " << arr2.size() << std::endl;
		
		for (unsigned int i = 0; i < arr2.size(); i++) {
			arr2[i] = i * 2;
		}
		
		Array<int> arr3 = arr2;
		arr3[0] = 999;
		
		std::cout << "arr2[0]: " << arr2[0] << " (doit être 0)" << std::endl;
		std::cout << "arr3[0]: " << arr3[0] << " (doit être 999)" << std::endl;
		
		for (unsigned int i = 0; i < arr2.size(); i++) {
			arr2[i] = i * 2;

			std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
		}
		 arr1[0];
		
	} catch (const std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	return 0;
}