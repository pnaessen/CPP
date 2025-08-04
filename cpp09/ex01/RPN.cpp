/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:21:41 by pn                #+#    #+#             */
/*   Updated: 2025/08/04 13:13:31 by pnaessen         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	/*theorie : check si bien 2 number check si op pop les 2 elem calculate push le result check si number op number */
}

RPN::RPN(const RPN& copy) :_stack(copy._stack) {
	
}

RPN::~RPN() {
	
}

RPN& RPN::operator=(const RPN& assign) {
	
	if(this != &assign) {
		_stack = assign._stack;
	}
	return *this;
}

bool RPN::isNumber(const std::string& token) {
	
	if(token.empty())
		return false;
	char *end;
	double val = std::strtod(token.c_str(), &end);
	if(end != '\0') {
		std::cout << "Error: bad input" << std::endl;
		return false;
	}
	return true;
	 
}

bool RPN::isOperator(const std::string& token) {
	
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

double process(std::string& expression) {
	
}