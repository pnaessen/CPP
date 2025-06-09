/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:20:55 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/09 17:13:57 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AScalarConverter.hpp"

void AScalarConverter::printChar(double value) {
	
	if (value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} 
	else if (!std::isprint(static_cast<char>(value))) {
		std::cout << "char: Non displayable" << std::endl;
	} 
	else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
}

void AScalarConverter::printFloat(double value) {

	std::cout << value << std:: endl;
}

void AScalarConverter::printInt(double value) {

	 
	if (value < INT_MIN || value > INT_MAX) {
		std::cout << "int: overflow" << std::endl;
	}
	else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
}

void AScalarConverter::printDouble(double value) {
	std::cout << std::fixed << std::setprecision(0)  << "double: " << value << std::endl;
}

bool AScalarConverter::isChar(const std::string& str) {
	
	if (str.length() != 1)
		return false;

	char c = str[0];

	if (std::isdigit(c))
		return false;

	if (c == '+' || c == '-')
		return false;

	return true;
}

bool AScalarConverter::isInt(const std::string& str) {
	if (str.empty())
		return false;
	
	size_t start = 0;
	
	if (str[0] == '+' || str[0] == '-')
		start = 1;
	
	if (start >= str.length())
		return false;
	
	for (size_t i = start; i < str.length(); ++i) {
		if (!std::isdigit(str[i]))
			return false;
		if(i > 8)
			return false;
	}
	
	return true;
}

bool AScalarConverter::isFloat(const std::string& str) {
		(void)str;

	return false;
}

void AScalarConverter::convert(std::string& convert) {
	
	double val;
	
	if(isChar(convert)) {
		val = static_cast<double>(convert[0]);
	}
	else if(isFloat(convert)) {
		val = static_cast<double>(std::atof(convert.c_str()));
	}
	else if(isInt(convert)) { 
		val = static_cast<double>(std::atoi(convert.c_str()));
	}
	else
		val = std::atof(convert.c_str());

	printChar(val);
	printInt(val);
	printDouble(val);
}