/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:48:12 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/02 15:58:14 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {
	/*theorie : je getline chaque ligne de fichiers apres je _map.inset() le result boucle sur tout le fichier 
	*/
}

Bitcoin::Bitcoin(const Bitcoin& obj) {

	(void)obj;
}

Bitcoin::~Bitcoin() {

}

Bitcoin& Bitcoin::operator=(const Bitcoin& obj) {
	
	if(this != &obj) {
		
	}
	return *this;
}

bool Bitcoin::loadDB(const std::string& filename) {
	
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open database file." << std::endl;
        return false;
    }
    
    std::string line;
    if (!std::getline(file, line)) {
        std::cout << "Error: empty database file." << std::endl;
        return false;
    }
    
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue; 
        }
        
        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);
        
        if (check_key(date) != 0) {
            std::cout << "Error: bad date => " << date << std::endl;
            continue;
        }
        
        char *end;
        double rate = std::strtod(valueStr.c_str(), &end);
        if (valueStr.c_str() == end || *end != '\0' || rate < 0) {
            std::cout << "Error: bad exchange rate => " << valueStr << std::endl;
            continue;
        }
        
        _exchangeRates[date] = rate;
    }
    
    return !_exchangeRates.empty();
}

double Bitcoin::getExchangeRate(const std::string& date) const {
	
    const_iterator it = _exchangeRates.lower_bound(date);
    
    if (it != _exchangeRates.end() && it->first == date) {
        return it->second;
    }
    
    if (it != _exchangeRates.begin()) {
        --it;
        return it->second;
    }
    
    return -1.0;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int getDaysInMonth(int month, int year) {
    static const int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (month == 2 && isLeapYear(year))
        return 29;
    return daysInMonth[month - 1];
}

int check_key(const std::string& key) {
    if (key.length() != 10 || key[4] != '-' || key[7] != '-')
        return 1;
    
    char *end;
    
    int year = std::strtod(key.substr(0, 4).c_str(), &end);
    if (*end != '\0' || year < 1000 || year > 9999)
        return 1;
    
    int month = std::strtod(key.substr(5, 2).c_str(), &end);
    if (*end != '\0' || month < 1 || month > 12)
        return 1;
    
    int day = std::strtod(key.substr(8, 2).c_str(), &end);
    if (*end != '\0' || day < 1)
        return 1;
    
    int maxDays = getDaysInMonth(month, year);
    if (day > maxDays)
        return 1;
    
    return 0;
}

bool Bitcoin::processInput(const std::string& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return false;
    }
    
    std::string line;
    if (!std::getline(file, line)) {
        std::cout << "Error: empty input file." << std::endl;
        return false;
    }
    
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
            
        processLine(line);
    }
    
    return true;
}

void Bitcoin::processLine(const std::string& line) const {
	
    size_t pipePos = line.find(" | ");
    if (pipePos == std::string::npos) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    
    std::string date = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 3);
    
    if (check_key(date) != 0) {
        std::cout << "Error: bad date => " << date << std::endl;
        return;
    }
    
    char* end;
    double value = std::strtod(valueStr.c_str(), &end);
    
    if (valueStr.c_str() == end || *end != '\0') {
        std::cout << "Error: not a number." << std::endl;
        return;
    }
    
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    
	if (value > 1000) {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }
	
    double rate = getExchangeRate(date);
    if (rate < 0) {
        std::cout << "Error: no exchange rate available for " << date << std::endl;
        return;
    }
    
    std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
}


Bitcoin::const_iterator Bitcoin::begin() const {
	
	return _exchangeRates.begin();
}
Bitcoin::const_iterator Bitcoin::end() const {
	
	return _exchangeRates.end();
}