/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AScalarConverter.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 15:44:02 by pnaessen          #+#    #+#             */
/*   Updated: 2025/06/08 17:27:11 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

	#define INT_MIN -2147483648
	#define INT_MAX 2147483647

class AScalarConverter {
	
	private:
		AScalarConverter();
		AScalarConverter(const AScalarConverter &obj);
		AScalarConverter  &operator=(const AScalarConverter& obj);


		static bool isChar(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isFloat(const std::string & str);

		static void printChar(double value);
		static void printInt(double value);
		static void printFloat(double value);
		static void printDouble(double value);

	public:
		virtual ~AScalarConverter() = 0;
		static void convert(std::string& convert);
};