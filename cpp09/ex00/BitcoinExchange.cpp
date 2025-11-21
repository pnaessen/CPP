/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:48:12 by pnaessen          #+#    #+#             */
/*   Updated: 2025/11/21 10:40:19 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin() {

}

Bitcoin::Bitcoin(const Bitcoin& obj) : _map(obj._map) {

}

Bitcoin::~Bitcoin() {

}

Bitcoin& Bitcoin::operator=(const Bitcoin& obj) {

	if(this != &obj) {
		_map = obj._map;
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

        std::string key = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);

        if (check_key(key) != 0) {
            std::cout << "Error: bad date => " << key << std::endl;
            continue;
        }

        char *end;
        double rate = std::strtod(valueStr.c_str(), &end);
        if (valueStr.c_str() == end || *end != '\0' || rate < 0) {
            std::cout << "Error: bad exchange rate => " << valueStr << std::endl;
            continue;
        }

        _map[key] = rate;
		//_map.insert(std::pair<std::string, double>(key, rate));
    }
    return !_map.empty();
}

double Bitcoin::getExchangeRate(const std::string& date) const {

    const_iterator it = _map.lower_bound(date);

    if (it != _map.end() && it->first == date) {
        return it->second;
    }

    if (it != _map.begin()) {
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

    if(line != "date | value") {
        std::cout << "Error: first line of the file must be \"date | value\"" << std::endl;
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

    std::string key = line.substr(0, pipePos);
    std::string valueStr = line.substr(pipePos + 3);

    if (check_key(key) != 0) {
        std::cout << "Error: bad date => " << key << std::endl;
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

    double rate = getExchangeRate(key);
    if (rate < 0) {
        std::cout << "Error: no exchange rate available for " << key << std::endl;
        return;
    }

    std::cout << key << " => " << value << " = " << (value * rate) << std::endl;
}


Bitcoin::const_iterator Bitcoin::begin() const {

	return _map.begin();
}
Bitcoin::const_iterator Bitcoin::end() const {

	return _map.end();
}