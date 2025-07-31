/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:47:53 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/26 15:37:51 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	
	if(argc != 2) {
		std::cout << "Error bad usage" << std::endl;
		return 1;
	}
	Bitcoin test;
	std::string input = argv[1];
	
	if(check_input(input)) {
		
		std::cout << "Error bad format" << std::endl;
		return 1;
	}
	test.loadDB();
	Bitcoin::iterator it = test.begin();
	Bitcoin::iterator ite = test.end();
	
	while (it != ite) {
		std::cout << it->first << "\n" << it->second << "\n------------" << std::endl;
		++it;
	}
}