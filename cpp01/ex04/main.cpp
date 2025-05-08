/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:26:53 by pnaessen          #+#    #+#             */
/*   Updated: 2025/05/08 12:01:11 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

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
	
	std::ifstream inFile(filename.c_str());
	if(!inFile.is_open()) {
		std::cout << "Error can't open the file" << std::endl;
		return 1;
	}
	
	std::string outFileName = filename + ".replace";
	
	std::ofstream outFile(outFileName.c_str());
	if(!outFile.is_open()) {
		std::cout << "Error can't open the outFile" << std::endl;
		return 1;
	}
	
	std::string line;
	while (std::getline(inFile, line)) {
		std::string modifLine;
		size_t startPos = 0;
		size_t newPos;

		while ((newPos = line.find(s1, startPos)) != std::string::npos) {
			modifLine += line.substr(startPos, newPos - startPos);
			modifLine += s2;
			startPos = newPos + s1.length();
		}
		
		modifLine += line.substr(startPos);
		
		outFile << modifLine;
	
		if (!inFile.eof()) {
			outFile << '\n';
		}
	}
	inFile.close();
	outFile.close();
}