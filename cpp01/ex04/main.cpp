/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:26:53 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/07 17:28:40 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if(argc != 4) {
		std::cout << ".... BAD ARGC" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	
	if(s1.empty()) {
		std::cout << "Error can't replace by empty" << std::endl;
		return 1;
	}
	std::ifstream inFile(filename);
	if(!inFile.is_open()) {
		std::cout << "Error can't open the file" << std::endl;
		return 1;
	}
	
	std::ofstream outFile(filename + ".replace");
	
	std::string line;
	while(std::getline(std::cin, line)) {
		
	}
	inFile.close();
	outFile.close();
}