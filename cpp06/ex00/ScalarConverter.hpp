/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:44:00 by pnaessen         #+#    #+#             */
/*   Updated: 2025/07/08 11:15:58 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

	#include <string>
	#include <iostream>
	#include <iomanip>
	#include <sstream>
	#include <climits>
	#include <cmath>
	#include <cctype>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter();

	enum Type {
		CHAR_LITERAL,
		INT_LITERAL,
		FLOAT_LITERAL,
		DOUBLE_LITERAL,
		SPECIAL_LITERAL,
		INVALID_LITERAL
	};

	static Type detectType(const std::string& input);
	static bool isCharLiteral(const std::string& input);
	static bool isIntLiteral(const std::string& input);
	static bool isFloatLiteral(const std::string& input);
	static bool isDoubleLiteral(const std::string& input);
	static bool isSpecialLiteral(const std::string& input);
	
	static double parseValue(const std::string& input, Type type);
	static bool isNanValue(double value);
	static bool isInfValue(double value);

public:
	static void convert(const std::string& input);
};

#endif