/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pn <pn@student.42lyon.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:21:43 by pn                #+#    #+#             */
/*   Updated: 2025/08/03 21:40:05 by pn               ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

class RPN
{
private:
	 std::stack<double> _stack;

public:
	// Constructors
	RPN();
	RPN(const RPN &copy);

	// Destructor
	~RPN();

	// Operators
	RPN & operator=(const RPN &assign);

	// Getters / Setters
	

	// Methods
	bool isOperator();
	bool isNumber();

};

std::ostream & operator<<(std::ostream & o, RPN const & i);

#endif