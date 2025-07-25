/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:48:12 by pnaessen          #+#    #+#             */
/*   Updated: 2025/07/25 11:12:15 by pnaessen         ###   ########lyon.fr   */
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

void Bitcoin::loadDB(std::string& filename) {
	
	std::string line;
	std::ifstream file(filename.c_str());
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