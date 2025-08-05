/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnaessen <pnaessen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:21:41 by pn                #+#    #+#             */
/*   Updated: 2025/08/05 11:10:09 by pnaessen         ###   ########lyon.fr   */
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
	std::strtod(token.c_str(), &end);
    return (*end == '\0');
}

bool RPN::isOperator(const std::string& token) {
	
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

double RPN::process(std::string& expression) {
	
	std::istringstream iss(expression);
    std::string token;

	while (iss >> token)
	{
		try
		{
			processToken(token);
		}
		catch (std::exception const & e)
		{
			while (!_stack.empty())
				_stack.pop();
			throw ;
		}
	}
	if(!_stack.empty()) {
		throw std::runtime_error("Error: empty expression");
	}
	if(_stack.size() != 1) {
		 throw std::runtime_error("Error: invalid expression");
	}
	return _stack.top();
}

double RPN::parseNumber(const std::string& token) const {
	
	char *end;
	double value = std::strtod(token.c_str(), &end);
	if(token.c_str() == end || *end != '\0') {
		throw std::runtime_error("Error: invalide number"); // need to change the throw
	}
	return value;
}

void RPN::processToken(const std::string& token) {
	if (isNumber(token))
	{
		double value = parseNumber(token);
		_stack.push(value);
	}
	else if (isOperator(token)) {
		if(_stack.size() < 2)
			throw std::runtime_error("Error: not enought number ");
		double b = _stack.top();
		_stack.pop();
		double a = _stack.top();
		_stack.pop();
		double result = perform(token, a, b);
		_stack.push(result);
	}
	else
		throw std::runtime_error("Error: unknown token");
}

double RPN::perform(const std::string& token, double a, double b) {
	if(token == "+") {
		return (a + b);
	}
	else if (token == "-") {
		return (a - b);
	}
	else if (token == "*") {
		return (a * b);
	}
	else if (token == "/") {
		if(b == 0.0) {
			throw std::runtime_error("Error : divition by 0");
		}
		return (b / a);
	}
	else
		throw std::runtime_error("Error: unknown operator");
}