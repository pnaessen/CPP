/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:48:12 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/26 15:12:52 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {
	/*theorie : je getline chaque ligne de fichiers apres je _map.inset() le result boucle sur tout le fichier 
	*/
}

Bitcoin::Bitcoin(Bitcoin& obj) {

	(void)obj;
}

Bitcoin::~Bitcoin() {

}

Bitcoin& Bitcoin::operator=(Bitcoin& obj) {
	
	if(this != &obj) {
		
	}
	return *this;
}

void Bitcoin::loadDB() {
	
	std::string line;
	std::ifstream file("data.csv");
	if(!file.is_open()) {
		std::cout << "Error can't open the file" << std::endl;
		return ;
	}
	
	std::getline(file, line);
	
	while(std::getline(file, line)) {
		
		if(line.empty()) 
			continue;
			
		size_t pos = line.find(",");
		if (pos == std::string::npos) {
			std::cout << "Error bad input" << std::endl;
			return ;
		}
		std::string key = line.substr(0, pos);
		if(check_key(key)) {
			std::cout << "Error bad input" << std::endl;
			return ;
		}
		std::string value_str = line.substr(pos + 1);
		
		char *end;
		double value = std::strtod(value_str.c_str(), &end);
		if(value_str.c_str() == end || *end != '\0') {
			std::cout << "Error bad input" << std::endl;
			return ;
		}
		
		_map.insert(std::pair<std::string, double>(key, value));
	}
}

Bitcoin::iterator Bitcoin::begin() {
	
	return (_map.begin());
}

Bitcoin::iterator Bitcoin::end() {
	
	return (_map.end());
}

int check_key(std::string key) {
	
	char *end;
	double years = std::strtod(key.c_str(), &end);
	if(*end != '-' || years < 1000 || years > 9999) {
		return 1;
	}

	int month  = std::strtod(key.c_str() + 5, &end);
	if(*end != '-' || month < 1 || month > 12) {
		return 1;
	}

	int date = std::strtod(key.c_str() + 8, &end);
	if(*end != '\0' || date < 0 || date > 31) {
		return 1;
	}

	return 0;
}

int check_input(std::string filename) {
	
	std::string line;
	std::ifstream file(filename.c_str());
	if(!file.is_open()) {
		std::cout << "Error can't open the file" << std::endl;
		return 1;
	}
	
	std::getline(file, line);
	while(std::getline(file, line)) {
		
		if(line.empty())
			continue ;
		
		size_t pos = line.find("|");
		if (pos == std::string::npos) {
			return 1;
		}
		

		std::string key = line.substr(0, pos - 1);
		if(check_key(key)) {
			return 1;
		}
		

		std::string value_str = line.substr(pos + 2);
		
		char *end;
		std::strtod(value_str.c_str(), &end);
		if(value_str.c_str() == end || *end != '\0') {
			return 1;
		}
	}
	return 0;
}