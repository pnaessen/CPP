/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:20:55 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/08 17:07:17 by pnaessen         ###   ########lyon.fr   */
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
	std::cout << "double: " << value << std::endl;
}

bool AScalarConverter::isChar(const std::string& str) {
	
}

bool AScalarConverter::isInt(const std::string& str) {
	
}

bool AScalarConverter::isFloat(const std::string& str) {
	
}

void AScalarConverter::convert(std::string& convert) {
	
	if(isChar(convert)) {
		static_cast<double>(convert.c_str());
	}
	else if(isFloat(convert)) {
		static_cast<double>(convert.ftoi());
	}
	else if(isInt(convert)) { 
		static_cast<double>(convert.stoi());
	}
	else
		static_cast<double>(convert);
}