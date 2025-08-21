/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:20:55 by pnaessen          #+#    #+#             */
/*   Updated: 2025/08/21 09:04:22 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& input) {
	
	Type type = detectType(input);
	
	if (type == INVALID_LITERAL) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}
	
	double value = parseValue(input, type);
	
	if (isNanValue(value) || isInfValue(value) || value < 0 || value > 127) {
		std::cout << "char: impossible" << std::endl;
	} 
	else if (!std::isprint(static_cast<char>(value))) {
		std::cout << "char: Non displayable" << std::endl;
	} 
	else {
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	}
	
	if (isNanValue(value) || isInfValue(value) || value < INT_MIN || value > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	} 
	else {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	
	std::cout << "float: ";
	
	float float_val = static_cast<float>(value);
	if (isNanValue(value)) {
		std::cout << "nanf" << std::endl;
	} 
	else if (std::isinf(float_val)) {
		if (value > 0)
			std::cout << "+inff" << std::endl;
		else
			std::cout << "-inff" << std::endl;
	} 
	else {
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	}
	
	std::cout << "double: ";
	if (isNanValue(value)) {
		std::cout << "nan" << std::endl;
	} 
	else if (isInfValue(value)) {
		if (value > 0)
			std::cout << "+inf" << std::endl;
		else
			std::cout << "-inf" << std::endl;
	} 
	else {
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	}
}

ScalarConverter::Type ScalarConverter::detectType(const std::string& input) {
	
	if (isSpecialLiteral(input))
		return SPECIAL_LITERAL;
	if (isCharLiteral(input))
		return CHAR_LITERAL;
	if (isFloatLiteral(input))
		return FLOAT_LITERAL;
	if (isIntLiteral(input))
		return INT_LITERAL;
	if (isDoubleLiteral(input))
		return DOUBLE_LITERAL;
	return INVALID_LITERAL;
}

bool ScalarConverter::isCharLiteral(const std::string& input) {
	
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        return true;
    }
    
    if (input.length() == 1) {
        return true;
    }
    
    return false;
}

bool ScalarConverter::isIntLiteral(const std::string& input) {
	
	if (input.empty())
		return false;
	
	std::stringstream ss(input);
	long val;
	
	if (!(ss >> val) || !ss.eof())
		return false;
	
	return (val >= INT_MIN && val <= INT_MAX);
}

bool ScalarConverter::isFloatLiteral(const std::string& input) {
	
	if (input.length() < 3 || input[input.length() - 1] != 'f')
		return false;
	
	std::string without_f = input.substr(0, input.length() - 1);
	
	if (without_f.find('.') == std::string::npos)
		return false;
	
	std::stringstream ss(without_f);
	float val;
	
	return (ss >> val) && ss.eof();
}

bool ScalarConverter::isDoubleLiteral(const std::string& input) {
	
	if (input.empty())
		return false;
	
	if (input[input.length() - 1] == 'f')
		return false;
	
	std::stringstream ss(input);
	double val;
	
	if (!(ss >> val) || !ss.eof())
		return false;
	
	return (input.find('.') != std::string::npos) || 
			(val > INT_MAX || val < INT_MIN);
}

bool ScalarConverter::isSpecialLiteral(const std::string& input) {
	return (input == "nan" || input == "+inf" || input == "-inf" || 
			input == "nanf" || input == "+inff" || input == "-inff");
}

double ScalarConverter::parseValue(const std::string& input, Type type) {
	
	switch (type) {
		case CHAR_LITERAL:
    	if (input.length() == 1) {
        	return static_cast<double>(input[0]);
    	}
		 else {
        	return static_cast<double>(input[1]);
    	}
		
		case INT_LITERAL: {
			std::stringstream ss(input);
			int val;
			ss >> val;
			return static_cast<double>(val);
		}
		
		case FLOAT_LITERAL: {
			std::string without_f = input.substr(0, input.length() - 1);
			std::stringstream ss(without_f);
			float val;
			ss >> val;
			return static_cast<double>(val);
		}
		
		case DOUBLE_LITERAL: {
			std::stringstream ss(input);
			double val;
			ss >> val;
			return val;
		}
		
		case SPECIAL_LITERAL:
			if (input == "nan" || input == "nanf") {
				return 0.0 / 0.0;
			} 
			else if (input == "+inf" || input == "+inff") {
				return HUGE_VAL;
			} 
			else if (input == "-inf" || input == "-inff") {
				return -HUGE_VAL;
			}
			break;
		
		default:
			break;
	}
	return 0.0;
}

bool ScalarConverter::isNanValue(double value) {
	return (value != value);
}

bool ScalarConverter::isInfValue(double value) {
	return value == HUGE_VAL || value == -HUGE_VAL;
}